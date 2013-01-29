/*
** asm.h for asm in /home/dellam_a//Projet/corewar/asm
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Fri Jan 18 16:00:21 2013 adrien dellamaggiora
** Last update Tue Jan 29 14:43:51 2013 Welanor
*/

#ifndef _ASM_H_
# define _ASM_H_

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int	parse(char **file, char *name);
void	changepc(char *line, int *pc);
int	my_instructcmp(char *s1, char *s2, char sep);
void	instruc(char *line, int *pc);
void	adress_live(char *line, int *pc);
void	adress_ldlld(char *line, int *pc);
void	adress_add(char *line, int *pc);
void	adress_zjump(char *line, int *pc);
void	adress_and(char *line, int *pc);
void	adress_sti(char *line, int *pc);
void	adress_ldi(char *line, int *pc);
void	adress_fork(char *line, int *pc);
void	adress_aff(char *line, int *pc);

#endif
