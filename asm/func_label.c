/*
** func_label.c for func_label in /home/welanor/Projet/corewar/asm
** 
** Made by Welanor
** Login   <welanor@welanor>
** 
** Started on  Wed Jan 30 15:50:52 2013 Welanor
** Last update Wed Jan 30 15:52:46 2013 Welanor
*/

#include "parse_cmd.h"
#include "asm.h"

extern	t_op	op_tab[];

int	my_instructcmp(char *s1, char *s2, char sep)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s2[i] != 0 && s1[i] != 0)
    i++;
  if (s2[i] == 0 && s1[i] == sep)
    return (1);
  return (0);
}

void	adress(int i, char *line, int *pc)
{
  void	(*ptr[16])(char *line, int *pc);

  ptr[0] = adress_live;
  ptr[1] = adress_ldlld;
  ptr[2] = instruc;
  ptr[3] = adress_add;
  ptr[4] = adress_add;
  ptr[5] = adress_and;
  ptr[6] = adress_and;
  ptr[7] = adress_and;
  ptr[8] = adress_zjump;
  ptr[9] = adress_ldi;
  ptr[10] = adress_sti;
  ptr[11] = adress_fork;
  ptr[12] = adress_ldlld;
  ptr[13] = adress_ldi;
  ptr[14] = adress_fork;
  ptr[15] = adress_aff;
  ptr[i](line, pc);
}

void	changepc(char *line, int *pc)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (findlabel(line) == 1)
    {
      while (line[i] != ' ' && line[i] != '\0')
        i++;
      i++;
    }
  while (my_instructcmp(&line[i], op_tab[j].mnemonique, ' ') == 0 && j < 15)
    j++;
  adress(j, &line[i], pc);
}
