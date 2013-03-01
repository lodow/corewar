/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu Feb 21 15:02:05 2013 Hugues
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
    init_vm_stats(CYCLE_TO_DIE, -1, &vm);
    if (pars(&(argv[1]), argc - 1, &vm) != -1)
      while (handle_game(&vm, envp) == 0)
      {
        my_apply_on_list(vm.process_list, &exe_process, &vm);
        /*            usleep(1000);*/
      }
    free_all(&vm);
  }
  else
    my_putstr("A define is wrong\n", 1, -1);
  return (0);
}
