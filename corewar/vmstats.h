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

typedef struct		s_champ
{
  header_t		header;
  unsigned char	*champcode;
  int			number;
  int			alive;
}		t_champ;

typedef unsigned char	t_vmmem;

typedef char	t_reg[REG_SIZE];

typedef struct	s_process
{
  unsigned int	pc;
  int		carry;
  t_reg		reg[REG_NUMBER];
}		t_process;

int	load_champ(const char *filename, t_champ *champ);

#endif
