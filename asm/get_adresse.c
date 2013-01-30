/*
** get_adresse.c for get_adresse in /home/welanor/Projet/corewar/asm
**
** Made by welanor** Login <welanor@welanor>
**
** Last update Tue Jan 29 18:42:44 2013 Welanor
*/

#include "parse_cmd.h"

void	adress_live(char *line, int *pc)
{
  *pc = *pc + 5;
  printf("%s || %d\n", line, 5);
}

void	adress_ldlld(char *line, int *pc)
{
  int	i;

  i = 0;
  
  int debug = *pc;
  printf("%s", line);

  *pc = *pc + 2;
  while (line[i] != ' ' && line[i] != 0)
    i++;
  i++;
  if (line[i] == DIRECT_CHAR)
    *pc += DIR_SIZE;
  else if (line[i] == 'r')
    *pc += 1;
  else    *pc += IND_SIZE;
  *pc += 1;

  printf(" || %d\n", *pc - debug);

}

void	adress_add(char *line, int *pc)
{
  *pc += 5;
  printf("%s || %d\n", line, 5);  
}

void	adress_zjump(char *line, int *pc)
{
  *pc = *pc + 1 + IND_SIZE;
  printf("%s || %d\n", line, 1 + IND_SIZE);
}

void	adress_and(char *line, int *pc)
{
  int	i;

  int debug = *pc;
  printf("%s", line);

  i = 0;
  *pc = *pc + 2;
  while (line[i] != ' ' && line[i] != 0)
    i++;
  i++;
  if (line[i] == DIRECT_CHAR)
    *pc += DIR_SIZE;
  else if (line[i] == 'r')
    *pc += 1;
  else    *pc += IND_SIZE;
  while (line[i] != SEPARATOR_CHAR && line[i] != 0)
    i++;
  i++;
  if (line[i] == DIRECT_CHAR)
    *pc += DIR_SIZE;
  else if (line[i] == 'r')
    *pc += 1;
  else    *pc += IND_SIZE;
  *pc += 1;
  
  printf(" || %d\n", *pc - debug);
}
