/*
** match.c for match in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Jan 18 14:33:14 2013 luc sinet
** Last update Sat Jan 19 01:40:23 2013 luc sinet
*/

#include <stdlib.h>
#include "match.h"

void	init_postab(t_ma *ma)
{
  int	i;

  i = 0;
  ma->pos = 0;
  while (i < 1000)
    {
      ma->hit[i] = -1;
      i += 1;
    }
}

int	star(char *s1, char *s2, t_ma *ma)
{
  if (s2[ma->x] == '*')
    {
      init_postab(ma);
      while (s2[ma->x] == '*')
	ma->x += 1;
      while (ma->i == 0 || s1[ma->i - 1])
	{
	  if (s2[ma->x] == s1[ma->i])
	    {
	      ma->hit[ma->pos] = ma->i;
	      ma->pos += 1;
	    }
	  ma->i += 1;
	}
      if (ma->hit[0] == -1)
	return (0);
      ma->pos = 0;
      ma->i = ma->hit[ma->pos];
      return (1);
    }
  return (0);
}

int	new_pos(t_ma *ma)
{
  ma->pos += 1;
  if (ma->hit[ma->pos] == -1)
    return (0);
  ma->i = ma->hit[ma->pos] + 1;
  return (1);
}

int	test_value(t_ma *ma, char *s1, char *s2)
{
  while (s1[ma->i] || s2[ma->x])
    {
      if (s1[ma->i] != s2[ma->x])
	{
	  if (s2[ma->x] != '*' && ma->hit[ma->pos] == -1)
	    return (0);
	  else if (s2[ma->x] == '*')
	    {
	      if (star(s1, s2, ma) == 0)
		return (0);
	    }
	  else if (ma->hit[ma->pos] != -1 && new_pos(ma) == 0)
	    return (0);
	}
      else
	{
	  if (s1[ma->i])
	    ma->i++;
	  if (s2[ma->x])
	    ma->x++;
	}
    }
  return (1);
}

int	my_match(char *s1, char *s2)
{
  t_ma	*ma;
  int	res;

  if (s1 == NULL || s2 == NULL || (ma = malloc(sizeof(*ma))) == NULL ||
      (ma->hit = malloc(sizeof(int *) * 1000)) == NULL)
    return (0);
  ma->i = 0;
  ma->x = 0;
  init_postab(ma);
  res = test_value(ma, s1, s2);
  free(ma->hit);
  free(ma);
  if (!res)
    return (0);
  return (1);
}
