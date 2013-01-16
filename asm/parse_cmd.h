/*
** parse_cmd.h for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 14:20:12 2013 maxime lavandier
** Last update Wed Jan 16 14:43:57 2013 maxime lavandier
*/

#include "../misc/op.h"

#ifndef PARSE_CMD
# define PARSE_CMD

struct	s_cmd
{
  char	*opt_label;
  char	*opocode;
  char	*param[MAX_ARGS_NUMBER + 1];
}	t_cmd;

#endif
