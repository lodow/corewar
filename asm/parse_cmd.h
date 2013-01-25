/*
** parse_cmd.h for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 14:20:12 2013 maxime lavandier
** Last update Thu Jan 24 20:00:35 2013 Welanor
*/

#ifndef PARSE_CMD
# define PARSE_CMD

# include "../misc/op.h"
# include "../misc/str_func.h"
# include <stdlib.h>
# include <stdio.h>

# define TYPE(x, y) (x == 1 ? y : 1)

typedef	struct	s_tablabel
{
  char		*label;
  int		adress;
}		t_tablabel;

typedef struct	s_cmd
{
  char		*opt_label;
  char		*opocode;
  char		*param[MAX_ARGS_NUMBER + 1];
  void		*file;
  int		sizefile;
  int		pc;
  int		lablengh;
  t_tablabel	*lab;
}		t_cmd;

int	live_ldi_lldi(char *line, int i);
int	ld_st_lld(char *line, int i);
int	add_sub_and_or_xor_sti(char *line, int i);
int	zjmp_fork_lfork(char *line, int i);
int	aff(char *line, int i);
int	check_cmd(char *line);
int	parse_cmd(char *line, t_header *header, t_cmd *cmd);
int	put_header(t_cmd *cmd, t_header *header);
void	my_putstr(char *str, int fd, int lenght);
void	fillcmdfile(t_cmd *cmd, char *line);
int	findlabel(char *line);

#endif
