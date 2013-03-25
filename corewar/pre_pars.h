/*
** pre_pars.h for pre_pars in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Mar 19 18:05:46 2013 luc sinet
** Last update Thu Mar 21 14:23:50 2013 luc sinet
*/

#ifndef PRE_H_
# define PRE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

# define MASK 0170000
# define ISDIR 0040000
# define ISFILE 0100000

typedef struct	s_sel
{
  char		**new_args;
  char		**sel_tab;
  char		*sel_res;
  int		fd[2];
  int		pid;
  int		read_size;
}		t_sel;

char	*renew_folder(char *folder);
char	**change_args(char **args, char *folder, t_sel *spt);

#endif
