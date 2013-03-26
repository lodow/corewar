/*
** get_adresse.c for get_adresse in /home/dellam_a/Projet/corewar/asm
**
** Made by dellam_a Login <dellam_a@epitech.eu>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Fri Feb  1 15:30:21 2013 maxime lavandier
**
*/

#include "parse_cmd.h"

void	adress_live(char *line, int *pc)
{
  *pc = *pc + 5;
}

void	adress_ldlld(char *line, int *pc)
{
  int	i;

  i = 0;
  *pc = *pc + 2;
  while (line[i] != ' ' && line[i] != 0)
    i++;
  if (line[i] == 0)
    return ;
  i++;
  if (line[i] == DIRECT_CHAR)
    *pc += T_DIR + 2;
  else if (line[i] == 'r')
    *pc += T_REG + 2;
  else
    *pc += T_IND + 2;
  *pc += T_REG;
}

void	adress_add(char *line, int *pc)
{
  *pc += 2 + T_REG + T_REG + T_REG;
}

void	adress_zjump(char *line, int *pc)
{
  *pc = *pc + 1 + T_IND;
}

void	adress_and(char *line, int *pc)
{
  int	i;

  i = 0;
  *pc = *pc + 2;
  while (line[i] != ' ' && line[i] != 0)
    i++;
  i++;
  if (line[i] == DIRECT_CHAR)
    *pc += T_DIR;
  else if (line[i] == 'r')
    *pc += T_REG;
  else
    *pc += T_IND;
  while (line[i] != SEPARATOR_CHAR && line[i] != 0)
    i++;
  i++;
  if (line[i] == DIRECT_CHAR)
    *pc += T_DIR;
  else if (line[i] == 'r')
    *pc += T_REG;
  else
    *pc += T_IND;
  *pc += T_REG;
}
