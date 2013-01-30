/*
** fork.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 17:14:12 2013 maxime lavandier
** Last update Wed Jan 30 17:22:30 2013 maxime lavandier
*/

int	fork(t_param *param, char *str, int i, t_cmd *cmd)
{
  if (str[i] == 'f')
    param->param[0] = 0xc;
  else
    return (-1);
  param->lenght = 1;
  while (str[i] != 0 && str[i] != ' ')
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] == '%')
    i++;
  indirect(param, str, i , cmd);
}
