/*
** get_adr.c for get_adr in /home/dellam_a/Projet/corewar/asm
** 
** Made by Adrien
** Login   <dellam_a@epitech.eu>
** 
** Started on  Mon Jan 28 19:35:17 2013 Adrien
** Last update Wed Jan 30 12:57:18 2013 Welanor
*/

#include "parse_cmd.h"
#include "../misc/op.h"

void	adress_ldi(char *line, int *pc)
{
  int	i;

  int debug = *pc;
  printf("%s", line);
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
  printf(" || %d\n", *pc - debug);
}

void	adress_sti(char *line, int *pc)
{
  int	i;

  i = 0;

  int debug = *pc;
  printf("%s", line);

  *pc += IND_SIZE + IND_SIZE + 2;
  while (line[i] != 0 && line[i] != ' ')
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
  printf(" || %d\n", *pc - debug);
}

void	adress_fork(char *line, int *pc)
{
  int debug = *pc;
  printf("%s", line);

  *pc += 1 + IND_SIZE;
  printf(" || %d\n", *pc - debug);
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
}

