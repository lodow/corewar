/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Mar 25 13:45:19 2013 Hugues
*/

#include	"include.h"

int	check_define()
{
  if ((MEM_SIZE < 1) || (IDX_MOD < 1)
      || (REG_NUMBER < 1)
      || ((IND_SIZE != 2) || (REG_SIZE != 4) || (DIR_SIZE != 4))
      || (MAX_ARGS_NUMBER != 4)
      || ((T_IND != 4) || (T_REG != 1) || (T_DIR != 2))
      || ((NBR_LIVE < 1) || (CYCLE_TO_DIE < 0) || (CYCLE_DELTA < 0))
      || ((PROG_NAME_LENGTH < 0) || (COMMENT_LENGTH < 0)))
    return (0);
  return (1);
}

void	delete_champ_tab(t_champ **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
        free(tab[i]->freeme);
        free(tab[i]);
        i++;
      }
}

void	free_all(t_vm *vm, char **args)
{
  int	i;

  i = 0;
  my_rm_list(vm->process_list, &delete_process);
  delete_champ_tab(vm->champs);
  free(vm->champs);
  free(vm->mem);
  while ((args != NULL) && (args[i] != NULL))
    {
      free(args[i]);
      i++;
    }
  free(args);
}

char	**init_prog(t_vm *vm, char **argv, char **envp)
{
  char	**args;

  if ((args = pre_pars(&argv[1], envp)) == NULL)
    return (NULL);
  if (init_vm_stats(CYCLE_TO_DIE, -1, vm) == NULL)
    {
      my_putstr("Can't perform malloc\n", 2, -1);
      return (NULL);
    }
  if (pars(args, tab_size(args), vm) == -1)
    return (NULL);
  return (args);
}

int	main(int argc, char **argv, char **envp)
{
  t_vm		vm;
  char		**args;

  if (check_define())
    {
      if ((args = init_prog(&vm, argv, envp)) == NULL)
        return (-1);
      while (handle_game(&vm, envp) == 0)
        my_apply_on_list(vm.process_list, &exe_process, &vm);
      free_all(&vm, args);
    }
  else
    my_putstr("A define is wrong\n", 1, -1);
  return (0);
}
