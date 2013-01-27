/*
** pars_champ.c for pars_champ in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Jan 24 13:30:51 2013 luc sinet
** Last update Sun Jan 27 16:25:56 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include.h"

/*
** This function will set the process number
** (if no arguments were entered)
** to the next not already chosen number.
*/

void	set_numval(t_arg *parg)
{
  int	i;
  char	hit;

  hit = 1;
  if (parg->num_used[0] == -1)
    {
      parg->num_pos += 1;
      parg->num_used[0] += 1;
      parg->num_val = parg->num_used[0];
      return ;
    }
  parg->num_val = parg->num_used[parg->num_pos - 1];
  while (hit == 1)
    {
      i = 0;
      hit = 0;
      parg->num_val += 1;
      while (parg->num_used[i] != parg->num_val && parg->num_used[i] != -1)
	i += 1;
      if (parg->num_used[i] == parg->num_val)
	hit = 1;
    }
  parg->num_used[(parg->num_pos)++] = parg->num_val;
}

void	set_addrval(t_arg *parg)
{

}

void	check_value(t_arg *parg)
{
  if (parg->num == -1)
    set_numval(parg);
  if (parg->addr == -1)
    set_addrval(parg);
}

int	pars_champ(char *name, t_arg *parg)
{
  int	fd;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (-1);
  check_value(parg);
  parg->num = -1;
  parg->addr = -1;
  return (0);
}
