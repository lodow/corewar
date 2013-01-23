/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Jan 23 15:15:20 2013 luc sinet
*/

#include	"include.h"

void			print_hexa(char *mem, int nb)
{
  int			i;
  char			*hexa;
  unsigned char	tmp;

  i = 0;
  hexa = "0123456789ABCDEF";
  while (i < nb)
    {
      tmp = mem[i];
      my_putstr("0x", 1, 2);
      my_putstr(&hexa[tmp / 16], 1, 1);
      my_putstr(&hexa[tmp % 16], 1, 1);
      if (i != nb - 1)
        my_putstr(",", 1, 1);
      i++;
    }
}

int		main(int argc, char **argv, char **envp)
{
  t_vm		vm;
  t_champ	*prog;
  int		tmpfd;

  vm.process_list = NULL;
  vm.cycle_count = 0;
  vm.cycle_to_die = CYCLE_TO_DIE;
  if (pars(argv, argc) == -1 || ((vm.mem = malloc(MEM_SIZE * sizeof(char))) == NULL))
    return (-1);
  my_memset(vm.mem, MEM_SIZE, 0x0);
  tmpfd = open(argv[1], O_RDONLY);
  if ((prog = load_champ(tmpfd, 1)) != NULL)
    {
      my_add_to_list(&(vm.process_list), up_champ_t_mem(vm.mem, prog, 0));
      printf("%s\n%d\n%s\nProgram Binary is :\n", prog->header.prog_name, prog->header.prog_size, prog->header.comment);
      print_hexa(prog->champcode, prog->header.prog_size);
      printf("\n");
      free(prog->freeme);
      my_rm_list(vm.process_list, &delete_process);
    }
  free(vm.mem);
  return (0);
}
