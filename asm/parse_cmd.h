/*
** parse_cmd.h for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 14:20:12 2013 maxime lavandier
** Last update Wed Mar 20 18:33:56 2013 Adrien
*/

#ifndef PARSE_CMD_H
# define PARSE_CMD_H

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
  int		fd;
  int		nb;
  int		pc;
  int		lablengh;
  t_tablabel	*lab;
}		t_cmd;

typedef struct	s_param
{
  unsigned char	*param;
  int		lenght;
}		t_param;

void	params(char *str, int i, t_param *param, t_cmd *cmd);
int	parse(char **file, char *name);
int	parsing(char *str, t_cmd *cmd);
int	next_label(char *line);
int	parsing(char *str, t_cmd *cmd);
int	live_ldi_lldi(char *line, int i, t_param *param);
int	ld_st_lld(char *line, int i, t_param *param);
int	add_sub_and_or_xor_sti(char *line, int i, t_param *param);
int	zjmp_fork_lfork(char *line, int i, t_param *param);
int	aff(char *line, int i, t_param *param);
int	check_cmd(char *line, t_param *param);
int	parse_cmd(char *line, t_header *header, t_cmd *cmd);
int	put_header(t_header *header, t_cmd *cmd, char *name);
void	my_putstr(char *str, int fd, int lenght);
t_cmd	*addlabel(char *line, t_cmd *cmd);
void	fillcmdfile(t_cmd *cmd, char *line);
int	findlabel(char *line);
void	fillfile(t_header *header, t_cmd *cmd, char *name);
char	*sub_space(char *line);
t_cmd	*recuplabel(t_cmd *cmd, char **file);
char	*getname(char *name);
void	registre(t_param *param, char *str, int i, int line);
void	direct(t_param *param, char *str, int i, t_cmd *cmd);
void	indirect(t_param *param, char *str, int i, t_cmd *cmd);
int	chose_func(t_param *param, char *str, int i, t_cmd *cmd);
int	add_sub(char *str, int i, t_param *param, t_cmd *cmd);
int	laff(char *str, int i, t_param *param, t_cmd *cmd);
int	and_or_xor(char *str, int i, t_param *param, t_cmd *cmd);
int	lfork(char *str, int i, t_param *param, t_cmd *cmd);
int	ld(char *str, int i, t_param *param, t_cmd *cmd);
int	ldi_lldi(char *str, int i, t_param *param, t_cmd *cmd);
int	live(char *str, int i, t_param *param, t_cmd *cmd);
int	st(char *str, int i, t_param *param, t_cmd *cmd);
int	sti(char *str, int i, t_param *param, t_cmd *cmd);
int	zjump(char *str, int i, t_param *param, t_cmd *cmd);
int	next(char *str, int i);
int	my_cmp(char *str1, char *str2);
void	freelabel(t_cmd cmd);

#endif
