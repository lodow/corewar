/*
** parse_cmd.h for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 14:20:12 2013 maxime lavandier
** Last update Mon Jan 21 17:12:46 2013 adrien dellamaggiora
*/

#ifndef PARSE_CMD
# define PARSE_CMD

#include "../misc/op.h"
#include "../misc/str_func.h"
#include <stdlib.h>
#include <stdio.h>

int	parse_cmd(char *line, t_header *header);

struct	s_cmd
{
  char	*opt_label;
  char	*opocode;
  char	*param[MAX_ARGS_NUMBER + 1];
}	t_cmd;

#endif
