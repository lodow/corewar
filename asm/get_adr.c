/*
** get_adr.c for get_adr in /home/dellam_a/Projet/corewar/asm
**
** Made by Adrien
** Login   <dellam_a@epitech.eu>
**
** Started on  Mon Jan 28 19:35:17 2013 Adrien
** Last update Wed Mar 27 10:54:00 2013 Adrien Della Maggiora
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
  if (line[i++] == 0)
    return ;
  while (line[i] != 0 && line[i] != SEPARATOR_CHAR)
    i++;
  if (line[i++] == 0)
    return ;
  while (line[i] != 0 && line[i] != SEPARATOR_CHAR)
    i++;
  if (line[i++] == 0)
    return ;
  if (line[i] == DIRECT_CHAR)
    *pc += DIR_SIZE;
  else if (line[i] == 'r')
    *pc += 1;
  else
    *pc += IND_SIZE;
}

void	adress_sti(char *line, int *pc)
{
  int	i;

  i = 0;
  while (line[i] != 0 && line[i] != ' ')
    i++;
  if (line[i++] == 0)
    return ;
  if (line[i] == DIRECT_CHAR)
    *pc += DIR_SIZE + 2;
  else if (line[i] == 'r')
    *pc += 1 + 2;
  else
    *pc += IND_SIZE + 2;
  if ((i = next(line, i)) == -1)
    return ;
  if (line[i] == 'r')
    *pc += 1;
  else
    *pc += IND_SIZE;
  if ((i = next(line, i)) == -1)
    return ;
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
  *pc += 3;
}

void	instruc(char *line, int *pc)
{
  int   i;

  *pc += 2;
  i = 0;
  while (line[i] != ' ' && line[i] != '\0')
    i++;
  if (line[i] == 0)
    return ;
  i++;
  while (line[i] != SEPARATOR_CHAR && line[i] != 0)
    i++;
  if (line[i] == 0)
    return ;
  i++;
  if (line[i] == DIRECT_CHAR)
    *pc += DIR_SIZE;
  else if (line[i] == 'r')
    *pc += 1;
  else
    *pc += IND_SIZE;
  *pc += 1;
}
