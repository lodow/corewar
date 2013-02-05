/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun Feb  3 13:48:26 2013 luc sinet
*/

#include	"include.h"

int	check_define()
{
  if (MEM_SIZE < 1)
    return (0);
  if (IDX_MOD < 1)
    return (0);
  if (REG_NUMBER < 1)
    return (0);
  if ((IND_SIZE != 2) || (REG_SIZE != 4) || (DIR_SIZE != 4))
    return (0);
  if (MAX_ARGS_NUMBER != 4)
    return (0);
  if ((T_IND != 4) || (T_REG != 1) || (T_DIR != 2))
    return (0);
  if ((NBR_LIVE < 1) || (CYCLE_TO_DIE < 0) || (CYCLE_DELTA < 0))
    return (0);
  if ((PROG_NAME_LENGTH < 0) || (COMMENT_LENGTH < 0))
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

void	free_all(t_vm *vm)
{
  my_rm_list(vm->process_list, &delete_process);
  delete_champ_tab(vm->champs);
  free(vm->champs);
  free(vm->mem);
}

int	main(int argc, char **argv, char **envp)
{
  t_vm	vm;

  if (check_define())
    {
      pre_pars(&(argv[1]), envp, argc - 1);
      init_vm_stats(CYCLE_TO_DIE, -1, &vm);
      if (pars(&(argv[1]), argc - 1, &vm) != -1)
        while (handle_game(&vm, envp) == 0)
          {
            my_apply_on_list(vm.process_list, &exe_process, &vm);
            usleep(1000);
          }
      free_all(&vm);
    }
  else
    my_putstr("A define is wrong\n", 1, -1);
  return (0);
}
