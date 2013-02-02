/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Feb  2 20:27:11 2013 luc sinet
*/

#ifndef _VMSTATS_H_
# define _VMSTATS_H_

# include "../misc/op.h"

# define ABS(x) ((x) > 0 ? (x) : -(x))
# define GET_INSTR (vmstat->mem[MOD_MEM(proc->pc)]) - 1
# define MOD_MEM(x) ((ABS(x)) % MEM_SIZE)
# define VM_MEM(x) vm->mem[MOD_MEM((x))]
# define GET_TYPE_PARAMX(x, y) (((x) >> ((MAX_ARGS_NUMBER - 1 - (y)) * 2)) & 3)
# define SHORTCUT vmstat->instr_nb_cycle[(int)proc->instr]
# define CHECK_INST_CYCLE(x) (x >= 0 && x <= 15) ? SHORTCUT : x

typedef struct	s_champ
{
  char		*freeme;
  t_header	header;
  char		*champcode;
  int		number;
  int		alive;
}		t_champ;

typedef char	t_vmmem;
typedef int	t_reg;

typedef struct	s_params
{
  char	params[MAX_ARGS_NUMBER * 4 + 1];
}	t_params;

typedef struct		s_process
{
  int		pc;
  int		carry;
  t_champ	*associated_champ;
  t_reg		reg[REG_NUMBER];
  int		nb_cycle_t_next;
  char		instr;
  t_params	params_next_instr;
}		t_process;

typedef struct	s_vm
{
  int		instr_nb_cycle[16];
  int		(*f[16])(t_process *proc, struct s_vm *vm);
  t_champ	**champs;
  t_list	*process_list;
  t_vmmem	*mem;
  char		flag;
  int		cycle_count;
  int		nbr_live;
  int		cycle_to_die;
  int		cycle_to_dump;
}		t_vm;

void		delete_instr_params(t_params *params);
void		init_instr_params(t_params *params);
int		delete_process(void *ptr);
t_champ		**add_champ_t_tab(t_champ **tab, t_champ *add);
t_vm		*init_vm_stats(int cycle_t_die, int cycle_t_dump, t_vm *vm);
t_champ		*load_champ(int fd, int number, char *name);
int		op_param_size(char type);
t_process	*up_champ_t_mem(t_vm *vm, t_champ *champ, int pc);
t_process	*create_new_process(t_vm *vm, t_process *src, int pc);
char		*get_value_f_param_type(char type, int off_pos, t_process *proc);
int		exe_process(void *ptrproc, void *ptrvm);
void		fill_param_struct(t_vm *vm, t_process *proc);
int		handle_game(t_vm *vm, char **env);
void		dump_memory(t_vmmem *mem, int size, char **env);
int		write_dump(t_vmmem *mem, int size, char **env);

#endif
