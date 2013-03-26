/*
** check_args.c for check_args in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 22 21:57:03 2013 luc sinet
** Last update Tue Mar 26 15:48:22 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
  char	buf[5];
  int	sread;

  sread = -1;
  if ((fd = open(name, O_RDONLY)) == -1 || (sread = read(fd, buf, 5)) <= 4)
    {
      my_putstr("File ", 2, -1);
      my_putstr(name, 2, -1);
      my_putstr(RDERROR(sread), 2, -1);
      return (-2);
    }
  if (my_strlen(name) <= 4 ||
      my_strcmp(".cor", &(name[my_strlen(name) - 4])) != 0)
    {
      my_putstr(name, 2, -1);
      my_putstr(" is not a corewar executable\n", 2, -1);
      return (-2);
    }
  set_numval(parg);
  parg->opt[1] = -1;
  parg->opt[2] = -1;
  parg->nb_champ += 1;
  close(fd);
  return (1);
}

int	opt_error(char **av, t_arg *parg)
{
  return (-1);
}

int	opt_compare(char **av, t_arg *parg)
{
  int	i;
  char	*opt_list[5];
  int	(*args[6])(char **av, t_arg * parg);

  i = 0;
  args[0] = &check_dump;
  args[1] = &check_numproc;
  args[2] = &check_addr;
  args[3] = &check_adds;
  args[4] = &check_adds;
  args[5] = &opt_error;
  opt_list[0] = "-dump";
  opt_list[1] = "-n";
  opt_list[2] = "-a";
  opt_list[3] = "-unlimited";
  opt_list[4] = "-d";
  while (i < 5 && my_strcmp(opt_list[i], av[parg->pos]) != 0)
    i++;
  return (args[i](av, parg));
}
