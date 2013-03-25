/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Mar 25 17:34:35 2013 luc sinet
*/

#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction or the new adresse to jump to !
*/

void	debug_zjump(t_process *proc, short off_addr)
{
  my_putstr("\t", 1, 1);
  my_putstr(proc->associated_champ->header.prog_name);
  my_putstr(" zjump (", 1, -1);
  my_put_nbr(off_adrr % IDX_MOD, 1);
  my_putstr(") carry = ", 1, -1);
  my_put_nbr(proc->carry);
  my_putstr("\n", 1 , -1);
}

int	op_zjmp(t_process *proc, t_vm *vm)
{
  int	i;
  int	j;
  short	off_adrr;
  char	*tmp;

  i = 0;
  tmp = ((char*)(&off_adrr));
  j = IND_SIZE - 1;
  while (i < IND_SIZE)
    {
      tmp[i] = VM_MEM(proc->pc + 1 + j);
      j--;
      i++;
    }
  printf("[%10s] zjmp (%d) carry = %d\n", proc->associated_champ->header.prog_name, off_adrr % IDX_MOD, proc->carry);
  if (proc->carry == 1)
    return (off_adrr % IDX_MOD);
  return (1 + IND_SIZE);
}
