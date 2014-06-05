#ifndef MAOPT_H_
# define MAOPT_H_

void	select_matching(t_all *g_all, t_sel *sel);
char	*my_copie(char *str, char *buf, int s_read);
char	*delete_let(char *str);
void	display_cmd(t_all *g_all, t_sel *sel, char *final, char opt);

#endif
