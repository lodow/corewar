/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu Jan 24 19:29:07 2013 luc sinet
*/

#include	"include.h"

t_vm		*init_vm_stats(int cycle_t_die, int cycle_t_dump, t_vm *vm)
{
  vm->process_list = NULL;
  vm->champs = NULL;
  vm->cycle_count = 0;
  vm->cycle_to_die = cycle_t_die;
  vm->cycle_to_dump = cycle_t_dump;
  if ((vm->mem = malloc(MEM_SIZE * sizeof(char))) == NULL)
    return (NULL);
  my_memset(vm->mem, MEM_SIZE, 0x0);
  return (vm);
}

t_champ		**add_champ_t_tab(t_champ **tab, t_champ *add)
{
  t_champ	**newtab;
  int		i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      i++;
  if ((newtab = malloc((i + 2) * sizeof(t_champ))) == NULL)
    return (NULL);
  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
        newtab[i] = tab[i];
        i++;
      }
  newtab[i] = add;
  newtab[i + 1] = NULL;
  return (newtab);
}

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

