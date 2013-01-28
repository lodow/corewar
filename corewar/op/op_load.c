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

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/
int	op_load(t_process *proc, t_vm *vm)
{
/*Cette instruction prend 2 paramètres le deuxième est forcement
un registre (pas le PC). Elle load la valeur du premier paramètre
dans le registre. Cette opération modifie le carry. ld 34,r3 charge
les REG_SIZE octets a partir de l’adresse (PC + (34 %
IDX_MOD)) dans le registre r3.*/
  return (1);
}
