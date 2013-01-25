/*
** check_args.c for check_args in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 22 21:57:03 2013 luc sinet
** Last update Fri Jan 25 00:59:48 2013 luc sinet
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
      i += 1;
    }
  return (1);
}

int	check_champ(char *name, t_arg *parg)
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
  if (my_strlen(name) < 4 ||
      my_strcmp(".cor", &(name[my_strlen(name) - 4])) != 0)
    {
      my_putstr("Bad file extension\n", 2, -1);
      return (-2);
    }
  parg->num = 0;
  parg->addr = 0;
  return (1);
}


int	opt_compare(char **av, t_arg *parg)
{
  int	i;
  char	*opt_list[3];

  i = 0;
  opt_list[0] = "-dump";
  opt_list[1] = "-n";
  opt_list[2] = "-a";
  while (i < 3 && my_strcmp(opt_list[i], av[parg->pos]) != 0)
    i++;
  if (i == 3)
    return (-1);
  if (i == 0)
    return (check_dump(av, parg));
  else if (i == 1)
    return (check_numproc(av, parg));
  else
    return (check_addr(av, parg));
}
