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
** Print that the champs is alive
*/
void	op_live_print_alive(t_champ *champ)
{
  my_putstr("le joueur ", 1, 10);
  my_put_nbr(champ->number, 1);
  my_putstr("(", 1, 1);
  my_putstr(champ->header.prog_name, 1, -1);
  my_putstr(") est en vie\n", 1, 13);
}

void	op_live_set_alive(t_vm *vm, int number)
{
  int	i;

  i = 0;
  while (vm->champs[i] != NULL)
    {
      if (((vm->champs[i])->number == number) && ((vm->champs[i])->alive >= 0))
        {
          (vm->champs[i])->alive = 1;
          op_live_print_alive(vm->champs[i]);
        }
      i++;
    }
}

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/
int	op_live(t_process *proc, t_vm *vm)
{
  int	i;
  int	j;
  char	*tmp;
  int	number;

  i = 0;
  tmp = ((char*)(&number));
  j = sizeof(int) - 1;
  while (i < sizeof(int))
    {
      tmp[i] = VM_MEM(proc->pc + 1 + j);
      j--;
      i++;
    }
  vm->nbr_live++;
  op_live_set_alive(vm, number);
  return (5);
}
