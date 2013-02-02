/*
** dump_file.c for dump in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Feb  2 08:05:12 2013 luc sinet
** Last update Sat Feb  2 18:07:44 2013 luc sinet
*/

#include "include.h"

void	write_in_file(t_vmmem *mem, int size, int fd, unsigned char *buf)
{
  int	i;
  int  	inter;
  char	hit;
  char	*hexa;

  hit = 0;
  inter = my_square_root(size);
  i = 0;
  hexa = "0123456789ABCDEF";
  while (hit == 0)
    {
      buf[0] = hexa[mem[i] / 16];
      buf[1] = hexa[mem[i] % 16];
      i++;
      my_put_nbr(my_getnbr_base((char *)buf, hexa), fd);
      if (i % inter == 0)
	{
	  my_putstr("\n", fd, 1);
	  if (i + inter > size)
	    hit = 1;
	}
      else if (i != size - 1)
	my_putstr(" ", fd, 1);
    }
}

int			write_dump(t_vmmem *mem, int size)
{
  int			fd;
  mode_t		mode;
  unsigned char		buf[3];

  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  if ((fd = open("fdf_file.fdf", O_WRONLY | O_CREAT | O_TRUNC, mode)) == -1)
    {
      my_putstr("Can't open the file to dump memory\n", 2, -1);
      return (-1);
    }
  buf[2] = '\0';
  write_in_file(mem, size, fd, buf);
  close(fd);
  return (0);
}
