/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#ifndef _VMSTATS_H_
# define _VMSTATS_H_

# include "../misc/op.h"

# define MOD_MEM(x) ((x) % MEM_SIZE)
# define GET_TYPE_PARAMX(x, y) (((x) >> ((MAX_ARGS_NUMBER - (y)) * 2)) & 3)

typedef struct		s_champ
{
  char		*freeme;
  t_header	header;
  char		*champcode;
  int		number;
  int		alive;
}		t_champ;

typedef char	t_vmmem;

typedef char	t_reg[REG_SIZE];

typedef struct	s_process
{
  int	pc;
  int	carry;
  t_reg	reg[REG_NUMBER];
  int	nb_cycle_t_next;
  t_vmmem	*mem;
}	t_process;

int	get_bin_file(const char *filename, char **file);
int	load_champ(const char *filename, t_champ *champ);
int	op_param_size(char type);
char	*get_value_f_param_type(char type, int off_pos, t_process *proc);

#endif
