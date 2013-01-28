/*
** get_adr.c for get_adr in /home/dellam_a/Projet/corewar/asm
** 
** Made by Adrien
** Login   <dellam_a@epitech.eu>
** 
** Started on  Mon Jan 28 19:35:17 2013 Adrien
** Last update Mon Jan 28 20:17:39 2013 Welanor
*/

#include "parse_cmd.h"
#include "../misc/op.h"

void	adress_ldi(char *line, int *pc)
{
  int	i;

  i = 0;
  *pc += IND_SIZE + IND_SIZE + 2;
  while (line[i] != 0 && line[i] != ' ')
    i++;
  i++;
  while (line[i] != 0 && line[i] != SEPARATOR_CHAR)
    i++;
  i++;
  while (line[i] != 0 && line[i] != SEPARATOR_CHAR)
    i++;
  i++;
  if (line[i] == DIRECT_CHAR)
    *pc += DIR_SIZE;
  if (line[i] == 'r')
    *pc += 1;
  else
    *pc += IND_SIZE;
}

void	adress_sti(char *line, int *pc)
{
  int	i;

  i = 0;
  *pc += IND_SIZE + IND_SIZE + 2;
  while (line[i] != 0 && line[i] != ' ')
    i++;
  if (line[i] == 0)
    return ;
  i++;
  if (line[i] == DIRECT_CHAR)
      *pc += DIR_SIZE;
  if (line[i] == 'r')
    *pc += 1;
  else
    *pc += IND_SIZE;
}

void	adress_fork(char *line, int *pc)
{
  *pc += 1 + IND_SIZE;
}

void	adress_aff(char *line, int *pc)
{
  *pc += 2;
}
