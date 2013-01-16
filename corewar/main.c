/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 15 17:02:37 2013 adrien dellamaggiora
*/

#include	"include.h"

int		main(int argc, char **argv, char **envp)
{
  t_vmmem	*vmmem;
  t_champ	prog;

  if ((vmmem = malloc(MEM_SIZE * sizeof(char))) == NULL)
    return (-1);
  my_memset(vmmem, MEM_SIZE, 0x0);
  load_champ(argv[1], &prog);
  printf("%s\n%d\n%s\nProgram Binary is :\n", prog.header.prog_name, prog.header.prog_size, prog.header.comment);
  write(1, &prog.champcode, prog.header.prog_size);
  free(prog.freeme);
  free(vmmem);
  return (0);
}
