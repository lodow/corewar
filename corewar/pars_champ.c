/*
** pars_champ.c for pars_champ in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Jan 24 13:30:51 2013 luc sinet
** Last update Sat Jan 26 18:05:33 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include.h"

int	pars_champ(char *name, t_arg *parg)
{
  int	fd;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (-1);

  parg->num = -1;
  parg->addr = -1;
  return (0);
}
