/*
** check_cmd.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 23 19:35:15 2013 maxime lavandier
** Last update Wed Jan 23 20:35:55 2013 maxime lavandier
*/

#include <stdlib.h>
#include "parse_cmd.h"

int	next_label(char *line)
{
  int	i;

  while (line[i] != 0 && line[i] != ' ' && line[i] != ':')
    i++;
  if (line[i] == ' ' || line[i] == 0)
    return (0);
  while (line[i] == ' ' || line[i] == ':')
    i++;
  return (i);
}

void	line_to_instruction(char *line, char *instruction, int i)
{
  int	j;

  j = 0;
  while (line[i] != ' ')
    {
      line[i] = instruction[j];
      i++;
      j++;
    }
  instruction[j] = 0;
}

int	check_type(char *line, char *instruction, int i)
{
  if (TYPE(my_begincmp(instruction, "live"), live_ldi_lldi(line, i)) &&
      TYPE(my_begincmp(instruction, "ld"), ld_st_lld(line, i)) &&
      TYPE(my_begincmp(instruction, "st"), ld_st_lld(line, i)) &&
      TYPE(my_begincmp(instruction, "add"), add_sub_and_or_xor_sti(line, i)) &&
      TYPE(my_begincmp(instruction, "sub"), add_sub_and_or_xor_sti(line, i)) &&
      TYPE(my_begincmp(instruction, "and"), add_sub_and_or_xor_sti(line, i)) &&
      TYPE(my_begincmp(instruction, "or"), add_sub_and_or_xor_sti(line, i)) &&
      TYPE(my_begincmp(instruction, "xor"), add_sub_and_or_xor_sti(line, i)) &&
      TYPE(my_begincmp(instruction, "zjmp"), zjmp_fork_lfork(line, i)) &&
      TYPE(my_begincmp(instruction, "ldi"), live_ldi_lldi(line, i)) &&
      TYPE(my_begincmp(instruction, "sti"), add_sub_and_or_xor_sti(line, i)) &&
      TYPE(my_begincmp(instruction, "fork"), zjmp_fork_lfork(line, i)) &&
      TYPE(my_begincmp(instruction, "lld"), ld_st_lld(line, i)) &&
      TYPE(my_begincmp(instruction, "lldi"), live_ldi_lldi(line, i)) &&
      TYPE(my_begincmp(instruction, "lfork"), zjmp_fork_lfork(line, i)) &&
      TYPE(my_begincmp(instruction, "aff"), aff(line, i)))
    return (0);
  return (-1);
}

/*
** lenght = lenght of instruction
*/

int	check_cmd(char *line)
{
  int	i;
  int	lenght;
  char	*instruction;

  if (line == 0)
    return (-1);
  i = next_label(line);
  lenght = 0;
  while (line[i + lenght] != ' ')
    lenght++;
  if ((instruction = malloc(lenght + 1)) == 0)
    return (-1);
  line_to_instruction(line, instruction, i);
  if (check_type(line, instruction, i) == -1)
    return (-1);
  return (0);
}
