/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 29 16:54:32 2013 luc sinet
*/

#include	"operation.h"

int	op_sub(t_process *proc, t_vm *vm)
{
  proc->carry = toggle_val(proc->carry);
  return (1);
}
