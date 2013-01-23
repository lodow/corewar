/*
** parse_cmd.h for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 14:20:12 2013 maxime lavandier
** Last update Tue Jan 22 16:12:56 2013 maxime lavandier
*/

#ifndef PARSE_CMD
# define PARSE_CMD

#include "../misc/op.h"
#include "../misc/str_func.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_cmd
{
  char	*opt_label;
  char	*opocode;
  char	*param[MAX_ARGS_NUMBER + 1];
  void	*file;
  int	pc;
}		t_cmd;

int	parse_cmd(char *line, t_header *header, t_cmd *cmd);
int	put_header(t_cmd *cmd, t_header *header);

#endif
