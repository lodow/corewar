/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"include.h"

t_process	*up_champ_t_mem(t_vmmem *mem, t_champ *champ, int pc)
{
  t_process	*champ_proc;
  int		i;

  i = 0;
  if ((champ_proc = malloc(1 * sizeof(t_process))) == NULL)
    return (NULL);
  champ_proc->pc = pc;
  champ_proc->carry = 0;
  champ_proc->nb_cycle_t_next = 0;
  champ_proc->mem = mem;
  while (i < REG_NUMBER)
    {
      my_memset(champ_proc->reg[i], REG_SIZE, 0x00);
      i++;
    }
  champ_proc->reg[0][REG_SIZE - 1] = ((char)(champ->number));
  i = 0;
  while (i < champ->header.prog_size)
    {
      mem[MOD_MEM(pc + i)] = champ->champcode[i];
      i++;
    }
  return (champ_proc);
}
