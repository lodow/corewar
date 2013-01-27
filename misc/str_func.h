/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun Jan 27 17:11:43 2013 luc sinet
*/

#ifndef _STR_FUNC_H_
# define _STR_FUNC_H_

# include <unistd.h>
# include <stdlib.h>

int	my_strlen(char *str);
void	my_putstr(char *str, int fd, int strlen);
char	*my_strncpy(char *dest, char *src, int n);
int	my_strcmp(char *s1, char *s2);
int	my_begincmp(char *str1, char *str2);
void	*my_memsetc(void *ptr, int size, char value);
void	*my_memseti(void *ptr, int size, char value);
char	*my_strdup(char *str);
char	*switch_endian(char *var, int varsize);

#endif
