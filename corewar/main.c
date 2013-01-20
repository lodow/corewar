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

void my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    if (write(2, "Write error\n", 12) == -1)
      exit(0);
}

void			print_hexa(char *mem, int nb)
{
  int			i;
  char			hexa[] = "0123456789ABCDEF";
  unsigned char	tmp;

  i = 0;
  while (i < nb)
    {
      tmp = mem[i];
      my_putstr("0x");
      my_putchar(hexa[tmp / 16]);
      my_putchar(hexa[tmp % 16]);
      if (i != nb - 1)
        my_putstr(",");
      i++;
    }
}

int		main(int argc, char **argv, char **envp)
{
  t_vmmem	*vmmem;
  t_champ	prog;

  if ((vmmem = malloc(MEM_SIZE * sizeof(char))) == NULL)
    return (-1);
  my_memset(vmmem, MEM_SIZE, 0x0);
  if (load_champ(argv[1], &prog) >= 0)
    {
      printf("%s\n%d\n%s\nProgram Binary is :\n", prog.header.prog_name, prog.header.prog_size, prog.header.comment);
      print_hexa(prog.champcode, prog.header.prog_size);
      free(prog.freeme);
    }
  free(vmmem);
  return (0);
}
