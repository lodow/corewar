/*
** nb_func.h for nb_func in /home/sinet_l//corewar/misc
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 23 14:46:28 2013 luc sinet
** Last update Sat Feb  2 17:47:20 2013 luc sinet
*/

#ifndef NB_H_
# define NB_H_

int	my_getnbr(char *);
void	my_put_nbr(int nb, int fd);
void	print_hexa(char *mem, int nb);
int	my_power_rec(int nb, int pow);
int	my_getnbr_base(char *nb, char *base);
int	my_square_root(int nb);

#endif
