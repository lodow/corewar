/*
** my_getnbr.c for my_getnbr in /home/sinet_l//ratrapage
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Oct 20 11:27:34 2012 luc sinet
** Last update Sat Feb  2 20:23:02 2013 luc sinet
*/

#include <stdlib.h>
#include "str_func.h"
#include "nb_func.h"

int	my_getnbr(char *s1)
{
  int	nb;
  int	i;
  int	sign;

  nb = 0;
  i = 0;
  sign = 1;
  if (s1 != NULL)
    {
      while (s1[i] == '-' || s1[i] == '+')
        {
          if (s1[i] == '-')
            sign = -sign;
          i++;
        }
      while (s1[i] >= '0' && s1[i] <= '9')
        {
          if (((nb * 10) / 10) != nb)
            return (0);
          nb = nb * 10 + (s1[i] - 48);
          i++;
        }
    }
  return (nb * sign);
}

void	my_put_nbr(int nb, int fd)
{
  char	res;

  if (nb == -2147483648)
    {
      my_putstr("-2147483648", fd, 11);
      return ;
    }
  if (nb < 0)
    {
      my_putstr("-", fd, 1);
      nb = -nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10, fd);
  res = nb % 10 + 48;
  my_putstr(&res, fd, 1);
}

int	my_getnbr_base(char *calc, char *base)
{
  int   pic;
  int   lenb;
  int   lenc;
  int   pib;
  int   res;

  pic = 0;
  res = 0;
  lenb = my_strlen(base);
  lenc = my_strlen(calc) - 1;
  while (calc[pic])
    {
      pib = 0;
      while (calc[lenc - pic] != base[pib] && base[pib])
        pib += 1;
      res += pib * my_power_rec(lenb, pic);
      pic += 1;
    }
  return (res);
}

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  else if (power > 0)
    return (nb * my_power_rec(nb, power - 1));
  else
    return (0);
}

int     my_square_root(int nb)
{
  int   i;
  int   count;
  int   nb_c;

  i = 1;
  count = 1;
  nb_c = 1;
  while (nb_c < nb)
    {
      i = i + 2;
      count = count + 1;
      nb_c = nb_c + i;
    }
  if (nb_c == nb)
    return (count);
  return (count);
}
