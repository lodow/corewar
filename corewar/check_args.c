/*
** check_args.c for check_args in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 22 21:57:03 2013 luc sinet
** Last update Wed Jan 23 18:55:02 2013 luc sinet
*/

#include "include.h"

int	is_a_num(char *nb)
{
  int	i;

  i = 0;
  while (nb[i])
    {
      if (nb[i] < '0' || nb[i] > '9')
        return (-1);
    }
  return (1);
}

int	check_champ(char *name)
{
  int	fd;
  char	buf[1];

  if ((fd = open(name, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, buf, 1) == -1)
    {
      close(fd);
      return (-1);
    }
  close(fd);
  return (1);
}

int	check_opt(char **av, char *opt, int *pos, int max)
{
  int	i;
  char	*opt_list[3];

  i = 0;
  opt_list[0] = "-dump";
  opt_list[1] = "-n";
  opt_list[2] = "-a";
  while (i < 3 && my_strcmp(opt_list[i], opt) != 0)
    i++;
  if (i == 3)
    return (-1);
  if (i == 0 && ((*pos + 1) == max || is_a_num(av[*pos + 1]) == -1))
    return (-2);
  else if (i == 0)
    *pos += 1;
  return (1);
}
