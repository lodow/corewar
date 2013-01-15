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

# define MEM_SIZE		(6 * 1024)
# define IDX_MOD		512
/*
** Registres
*/
# define REG_NUMBER		16
/*
** size in Bytes
*/
# define IND_SIZE		2
# define REG_SIZE		4
# define DIR_SIZE		REG_SIZE
/*
** Cycle things
*/
# define CYCLE_TO_DIE	1536
# define CYCLE_DELTA	5
# define NBR_LIVE		40

typedef char	t_reg[REG_SIZE];

typedef struct	s_process
{
  unsigned int	pc;
  t_reg		reg[REG_NUMBER];
}		t_process;

#endif
