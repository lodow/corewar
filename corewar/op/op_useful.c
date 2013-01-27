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
** \param[in] vm A ptr on the vm
** \param[in] pos The pos in vm memory wher to start to cpy
** \param[in] size The size to be copied
** \return res The copied memory, NULL otherwise.
*/
char	*cpy_mem_value(t_vm *vm, int pos, int size)
{
  char	*res;
  int	j;
  int	i;

  i = size - 1;
  j = 0;
  if ((res = malloc(size * sizeof(char))) == NULL)
    return (NULL);
  while ((i >= 0) && (j < size))
    {
      res[j] = vm->mem[MOD_MEM(pos + i)];
      j++;
      i--;
    }
  return (res);
}

/*
** Retrieve
** \param[in] vm A ptr on the vm
** \param[in] pos The pos in vm memory wher to start to cpy
** \param[in] pc The value relative from the adress wanted
** \param[in] modidx Use idxmode or not !
** \return res The copied memory from the the value at pos, NULL otherwise.
*/
char	*resolve_ind_value(t_vm *vm, int pos, int pc, int modidx)
{
  char	*res;
  short	ind_ptr;
  int	i;
  int	j;

  i = REG_SIZE - 1;
  j = 0;
  if ((res = malloc(IND_SIZE * sizeof(char))) == NULL)
    return (NULL);
  res[0] = vm->mem[MOD_MEM(pos + 1)];
  res[1] = vm->mem[MOD_MEM(pos + 0)];
  ind_ptr = (*((short*)res));
  if (modidx)
    ind_ptr %= IDX_MOD;
  free(res);
  if ((res = malloc(REG_SIZE * sizeof(char))) == NULL)
    return (NULL);
  while ((i >= 0) && (j < REG_SIZE))
    {
      res[j] = vm->mem[MOD_MEM(pc + ind_ptr + i)];
      j++;
      i--;
    }
  return (res);
}