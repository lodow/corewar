#ifndef PARS_H_
# define PARS_H_

# define RDERROR(x) (x >= 0) ? " is empty\n" : " not accessible\n"
# define VTEST(x) (x < 0) ? 0 : x

typedef struct	s_arg
{
  int		pos;
  int		nb_arg;
  char		opt[5];
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
int	check_adds(char **av, t_arg *parg);
int	opt_error(char **av, t_arg *parg);
int	dump_opt(char **av, t_arg *parg);
int	prog_num_opt(char **av, t_arg *parg);
int	addr_opt(char **av, t_arg *parg);
int	adds_opt(char **av, t_arg *parg);
int	opt_compare(char **av, t_arg *parg);
int	check_champ(char *name, t_arg *parg);
int	is_a_num(char *opt);
int	pars_opt(char **av, t_arg *parg);
int	pars_champ(char *name, t_arg *parg);

#endif
