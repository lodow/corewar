#ifndef _OPERATION_H_
# define _OPERATION_H_

# include "../include.h"

# define NBPBYTE(x, y) calc_instr_len_f_param_byte((x), (y))
# define PARAMBYTE proc->params_next_instr.params[0]

int	op_add(t_process *proc, t_vm *vm);
int	op_aff(t_process *proc, t_vm *vm);
int	op_and(t_process *proc, t_vm *vm);
int	op_fork(t_process *proc, t_vm *vm);
int	op_ldi(t_process *proc, t_vm *vm);
int	op_lfork(t_process *proc, t_vm *vm);
int	op_live(t_process *proc, t_vm *vm);
int	op_lld(t_process *proc, t_vm *vm);
int	op_lldi(t_process *proc, t_vm *vm);
int	op_ld(t_process *proc, t_vm *vm);
int	op_or(t_process *proc, t_vm *vm);
int	op_st(t_process *proc, t_vm *vm);
int	op_sti(t_process *proc, t_vm *vm);
int	op_store(t_process *proc, t_vm *vm);
int	op_sub(t_process *proc, t_vm *vm);
int	op_xor(t_process *proc, t_vm *vm);
int	op_zjmp(t_process *proc, t_vm *vm);
int	is_byte_zero(char *src, int size);
int	op_get_dir(t_process *proc, t_vm *vm, int param);
int	op_get_ind(t_process *proc, t_vm *vm, int param, int idx_mod);
int	op_get_reg(t_process *proc, t_vm *vm, int param);
int	op_get_ind_as_dir(t_process *proc, t_vm *vm, int param);
char	*get_paramx(t_vm *vm, t_process *proc, char parambyte, int x);
int	calc_instr_len_f_param_byte(char type, int nbmax);

#endif
