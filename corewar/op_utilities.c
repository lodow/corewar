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

/*
** Return the reg nbr
** \param[in] mem The vmmemory
** \param[in] pc The program counter
** \param[in] off_pos offset from the pc to the value in memory
** \return value Reg nbr (Must be free)
*/
char	*get_reg_nb(t_vmmem *mem, int pc, int off_pos)
{
  char	*value;
  int	i;

  i = 0;
  value = NULL;
  value = malloc(1);
  if (value != NULL)
    while (i < 1)
      {
        value[i] = mem[MOD_MEM(pc + off_pos + i)];
        i++;
      }
  return (value);
}

/*
** Return the indirect value
** \param[in] mem The vmmemory
** \param[in] pc The program counter
** \param[in] off_pos offset from the pc to the value in memory
** \return value indirect value (Must be free)
*/
char	*get_ind_value(t_vmmem *mem, int pc, int off_pos)
{
  char	*value;
  int	i;

  i = 0;
  value = NULL;
  value = malloc(IND_SIZE);
  if (value != NULL)
    {
      while (i < IND_SIZE)
        {
          if (mod)
            value[i] = mem[MOD_MEM(pc + off_pos + i)];
          else
            value[i] = mem[MOD_MEM(pc + off_pos + i)];
          i++;
        }
    }
  return (value);
}

/*
** Return a direct value
** \param[in] mem The vmmemory
** \param[in] pc The program counter
** \param[in] off_pos offset from the pc to the value in memory
** \return value Direct value of the param (Must be free)
*/
char	*get_dir_value(t_vmmem *mem, int pc, int off_pos)
{
  char	*value;
  int	i;

  i = 0;
  value = NULL;
  value = malloc(DIR_SIZE);
  if (value != NULL)
    while (i < DIR_SIZE)
      {
        value[i] = mem[MOD_MEM(pc + off_pos + i)];
        i++;
      }
  return (value);
}

/*
** \param[in] type param type
** \return Size of the param type
*/
int	op_param_size(char type)
{
  return (((type == T_REG) * 2) + ((type == T_DIR) * DIR_SIZE)
          + ((type == T_IND) * IND_SIZE));
}

/*
** Return a value depending of the param type
** \param[in] type param type
** \param[in] off_pos offset from the pc to the value in memory
** \param[in] proc the current process
** \return value value of the param (Must be free)
*/
char	* get_value_f_param_type(char type, int off_pos, t_process *proc)
{
  char	*(*tabf[MAX(MAX(T_REG, T_DIR), T_IND) + 1])(t_vmmem*, int, int);

  tabf[T_REG] = &get_reg_nb;
  tabf[T_DIR] = &get_dir_value;
  tabf[T_IND] = &get_ind_value;
  if ((type == T_REG) || (type == T_DIR) || (type == T_IND))
    return (tabf[(int)type](proc->mem, proc->pc, off_pos));
  else
    return (NULL);
}
