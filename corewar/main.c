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
  char	**args;

  args = &(argv[1]);
  pre_pars(args, envp, argc - 1);
  init_vm_stats(CYCLE_TO_DIE, -1, &vm);
  if (pars(&(argv[1]), argc - 1, &vm) != -1)
    while (handle_game(&vm, envp) == 0)
      {
        my_apply_on_list(vm.process_list, &exe_process, &vm);
        usleep(1000);
      }
  free_all(&vm);
  return (0);
}
