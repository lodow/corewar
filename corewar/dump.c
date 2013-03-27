/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	print_adrr_dump(int adrr)
{
  char	*tmp;
  int	i;

  my_putstr("0x", 1, -1);
  tmp = my_uint_strbase(adrr, "0123456789ABCDEF");
  if ((i = my_strlen(tmp)) != 8)
    {
      i = 8 - i;
      while (i > 0)
        {
          my_putstr("0", 1, 1);
          i--;
        }
    }
  my_putstr(tmp, 1, -1);
  my_putstr(" ", 1, -1);
  free(tmp);
}

void			dump_memory(t_vm *vm, int size, char **env)
{
  int			i;
  char			*hexa;
  unsigned char	tmp;

  i = 0;
  hexa = "0123456789ABCDEF";
  print_adrr_dump(i);
  my_putstr(" ", 1, -1);
  while (i < size)
    {
      tmp = vm->mem[i];
      my_putstr(&hexa[tmp / 16], 1, 1);
      my_putstr(&hexa[tmp % 16], 1, 1);
      i++;
      if (i % 20 == 0)
        {
          my_putstr("\n", 1, -1);
          print_adrr_dump(i);
        }
      if (i < size)
        my_putstr(" ", 1, -1);
    }
  my_putstr("\n\n", 1, -1);
}
