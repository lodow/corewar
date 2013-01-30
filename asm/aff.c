/*
** aff.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 17:49:25 2013 maxime lavandier
** Last update Wed Jan 30 17:53:47 2013 maxime lavandier
*/

int	aff(char *str, int i, t_param *param, t_cmd *cmd)
{
  param->lenght = 1;
  param->param[0] = 0x10;
  while (str[i] != 0 && str[i] != ' ')
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] != 'r')
    return (-1);
  registre(param, str, i);
  return (0);
}
