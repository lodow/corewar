/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"operation.h"

int	sti_get_first_val(t_process *proc, t_vm *vm)
{
  if (GET_TYPE_PARAMX(PARAMBYTE, 0) != 0)
    {
      if (GET_TYPE_PARAMX(PARAMBYTE, 0) == 1)
        return (op_get_reg(proc, vm, 0));
      else if (GET_TYPE_PARAMX(PARAMBYTE, 0) == 2)
        return (op_get_dir(proc, vm, 0));
      else
        return (op_get_ind(proc, vm, 0, 1));
    }
  return (0);
}

void	sti_cpy_val_a_adrr(t_process *proc, t_vm *vm, int val, int adrr)
{
  char	*tmp;

  tmp = (char*)(&(val));
  switch_endian(tmp, sizeof(int));
  vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 0)] = tmp[0];
  vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 1)] = tmp[1];
  vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 2)] = tmp[2];
  vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 3)] = tmp[3];
}

void	sti_re_set_param_byte(t_process *proc)
{
  int	i;
  char	params[4];

  i = 0;
  while (i < 4)
    {
      params[i] = GET_TYPE_PARAMX(PARAMBYTE, i);
      i++;
    }
  if (params[1] == 2)
    params[1] = 3;
  if (params[2] == 2)
    params[2] = 3;
  i = 0;
  PARAMBYTE = 0;
  while (i < 4)
    {
      PARAMBYTE |= params[i] << ((3 - i) * 2);
      i++;
    }
}

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/
int	op_sti(t_process *proc, t_vm *vm)
{
  int	valtstore;
  int	i;
  int	adrr;
  int	tsize;

  i = 1;
  adrr = 0;
  sti_re_set_param_byte(proc);
  tsize = NBPBYTE(PARAMBYTE, 1) + 2;
  valtstore = sti_get_first_val(proc, vm);
  while (i < 3)
    {
      if (GET_TYPE_PARAMX(PARAMBYTE, i) == 1)
        adrr += op_get_reg(proc, vm, i);
      else
        {
          adrr += op_get_ind_as_dir(proc, vm, i);
          tsize += 1;
        }
      tsize += 1;
      i++;
    }
  printf("[%10s] sti (%d -> i@pc+%d)\n", proc->associated_champ->header.prog_name, valtstore, adrr);
  sti_cpy_val_a_adrr(proc, vm, valtstore, adrr);
  return (tsize);
}
