/*
** match_opt.h for match_opt in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Jan 19 01:15:09 2013 luc sinet
** Last update Sat Jan 19 01:23:50 2013 luc sinet
*/

#ifndef MAOPT_H_
# define MAOPT_H_

void	select_matching(t_all *g_all, t_sel *sel);
char	*my_copie(char *str, char *buf, int s_read);
char	*delete_let(char *str);
void	display_cmd(t_all *g_all, t_sel *sel, char *final, char opt);

#endif
