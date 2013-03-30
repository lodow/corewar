/*
** my_getnbr.c for my_getnbr in /home/sinet_l//ratrapage
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Oct 20 11:27:34 2012 luc sinet
** Last update Wed Jan 16 12:50:57 2013 luc sinet
*/

#include <stdlib.h>

int	my_getnbr(char *s1)
{
  int	nb;
  int	i;
  int	sign;

  nb = 0;
  i = 0;
  sign = 1;
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
  return (nb * sign);
}

int	my_put_nbr(int nb, int output)
{
  if (nb == -2147483648)
    {
      my_putstr("-2147483648", output);
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-', output);
      nb = -nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10, output);
  my_putchar(nb % 10 + 48, output);
  return (0);
}

int     my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while ((s1[i] || s2[i]) && i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
