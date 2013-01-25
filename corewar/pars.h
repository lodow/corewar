/*
** pars.h for pars in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 23 15:40:32 2013 luc sinet
** Last update Fri Jan 25 15:51:30 2013 luc sinet
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
  int		nb_champ;
  int		dump_val;
  int		num_val;
  int		addr_val;
  int		*num_used;
}		t_arg;

int	pars(char **av, int ac);
int	check_dump(char **av, t_arg *parg);
int	check_numproc(char **av, t_arg *parg);
int	check_addr(char **av, t_arg *parg);
int	opt_compare(char **av, t_arg *parg);
int	check_champ(char *name, t_arg *parg);
int	is_a_num(char *opt);

#endif
