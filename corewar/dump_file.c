/*
** dump_file.c for dump in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Feb  2 08:05:12 2013 luc sinet
** Last update Sat Feb  2 17:43:36 2013 luc sinet
*/

#include "include.h"

int		write_dump(t_vmmem *mem, int size)
{
  int		i;
  char		*hexa;
  int		fd;
  unsigned char	tmp;
  int		inter;
  char		buf[3];

  inter = my_square_root(size);
  i = 0;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  fd = open("fdf_file", O_WRONLY | O_CREAT | O_TRUNC, mode);
  hexa = "0123456789ABCDEF";
  buf[2] = '\0';
  while (i + inter < size)
    {
      tmp = mem[i];
      buf[0] = hexa[tmp / 16];
      buf[1] = hexa[tmp % 16];
      i++;
      my_put_nbr(my_getnbr_base(buf, hexa), fd);
      if (i % inter == 0)
	my_putstr("\n", fd, 1);
      else if (i != size - 1)
	my_putstr(" ", fd, 1);
    }
  my_putstr("\n", fd, 1);
}
