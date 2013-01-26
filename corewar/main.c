/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Jan 23 18:30:41 2013 luc sinet
*/

#include	"include.h"

int		main(int argc, char **argv, char **envp)
{
  t_vm		vm;
  t_champ	*prog;
  int		tmpfd;

  if (pars(&(argv[1]), argc - 1) == -1)
    return (-1);
  tmpfd = open(argv[1], O_RDONLY);
  init_vm_stats(CYCLE_TO_DIE, -1, &vm);
  if ((vm.champs = add_champ_t_tab(vm.champs, load_champ(tmpfd, 42))) != NULL)
    {
      prog = vm.champs[0];
      my_add_to_list(&(vm.process_list), up_champ_t_mem(vm.mem, prog, 0));
      printf("%s\n%d\n%s\nProgram Binary is :\n", prog->header.prog_name, prog->header.prog_size, prog->header.comment);
      dump_memory(prog->champcode, prog->header.prog_size);
      printf("\n");
      while (handle_game(&vm) == 0)
        my_apply_on_list(vm.process_list, &exe_process, &vm);
      free(prog->freeme);
      free(vm.champs[0]);
      my_rm_list(vm.process_list, &delete_process);
    }
  free(vm.champs);
  free(vm.mem);
  return (0);
}

