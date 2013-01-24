/*
** pars.h for pars in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 23 15:40:32 2013 luc sinet
** Last update Thu Jan 24 20:08:15 2013 luc sinet
*/

#ifndef PARS_H_
# define PARS_H_

typedef struct	s_arg
{
  int		pos;
  int		nb_arg;
  char		dump;
  char		num;
  char		addr;
  int		dump_val;
  int		num_val;
  int		addr_val;
}		t_arg;

int	pars(char **av, int ac)
int	check_dump(char **av, t_arg *parg);
int	check_numproc(char **av, t_arg *parg);
int	check_addr(char **av, t_arg *parg);

#endif
