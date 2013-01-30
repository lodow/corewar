/*
** pars.h for pars in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 23 15:40:32 2013 luc sinet
** Last update Tue Jan 29 17:11:21 2013 luc sinet
*/

#ifndef PARS_H_
# define PARS_H_

# define RDERROR(x) (x >= 0) ? " is empty\n" : " not accessible\n"
# define VTEST(x) (x < 0) ? 0 : x

typedef struct	s_arg
{
  int		pos;
  int		nb_arg;
  char		dump;
  char		num;
  char		addr;
  int		added_champ;
  int		nb_champ;
  int		dump_val;
  int		*num_used;
  int		*addr_used;
  int		addr_pos;
  int		num_pos;
  t_vm		*vm;
}		t_arg;

int	pars(char **av, int ac, t_vm *vm);
int	check_dump(char **av, t_arg *parg);
int	check_numproc(char **av, t_arg *parg);
int	check_addr(char **av, t_arg *parg);
int	opt_compare(char **av, t_arg *parg);
int	check_champ(char *name, t_arg *parg);
int	is_a_num(char *opt);
int	pars_opt(char **av, t_arg *parg);
int	pars_champ(char *name, t_arg *parg);

#endif
