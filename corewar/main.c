/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun Jan 27 20:37:42 2013 luc sinet
*/

#include	"include.h"

int		main(int argc, char **argv, char **envp)
{
  t_vm		vm;

  init_vm_stats(CYCLE_TO_DIE, -1, &vm);
  if (pars(&(argv[1]), argc - 1, &vm) == -1)
    return (-1);
  while (handle_game(&vm) == 0)
    {
      my_apply_on_list(vm.process_list, &exe_process, &vm);
      usleep(1000);
    }
  my_rm_list(vm.process_list, &delete_process);
  free(vm.champs);
  free(vm.mem);
  return (0);
}
