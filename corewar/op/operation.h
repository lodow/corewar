/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#ifndef _OPERATION_H_
# define _OPERATION_H_

# include "../include.h"

int	op_add(t_process *proc, t_vm *vm);
int	op_aff(t_process *proc, t_vm *vm);
int	op_and(t_process *proc, t_vm *vm);
int	op_fork(t_process *proc, t_vm *vm);
int	op_ldi(t_process *proc, t_vm *vm);
int	op_lfork(t_process *proc, t_vm *vm);
int	op_live(t_process *proc, t_vm *vm);
int	op_lld(t_process *proc, t_vm *vm);
int	op_lldi(t_process *proc, t_vm *vm);
int	op_load(t_process *proc, t_vm *vm);
int	op_or(t_process *proc, t_vm *vm);
int	op_st(t_process *proc, t_vm *vm);
int	op_sti(t_process *proc, t_vm *vm);
int	op_store(t_process *proc, t_vm *vm);
int	op_sub(t_process *proc, t_vm *vm);
int	op_xor(t_process *proc, t_vm *vm);
int	op_zjmp(t_process *proc, t_vm *vm);
char	*get_none_direct_value(char *value, char type, t_process *proc, int mod);
char	* get_value_f_param_type(char type, int off_pos, t_process *proc);
char	*get_reg_nb(t_vmmem *mem, int pc, int off_pos);
char	*get_ind_value(t_vmmem *mem, int pc, int off_pos);
char	*get_dir_value(t_vmmem *mem, int pc, int off_pos);
int	op_param_size(char type);

#endif
