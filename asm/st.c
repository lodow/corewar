/*
** st.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 15:51:49 2013 maxime lavandier
** Last update Wed Jan 30 16:13:46 2013 maxime lavandier
*/

int	st_param(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'r')
    {
      registre(param, str, i);
      param->param[1] = 0b01010000;
    }
  else if (str[i] == '%')
    {
      direct(param, str, i, cmd);
      param->param[1] = 0b01100000;
    }
  else
    {
      indirect(param, str, i, cmd);
      param->param[1] = 0b01110000;
    }
}

int	st(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 's')
    param->param[0] = 0x3;
  else
    return (-1);
  while (str[i] != 0 && str[i] != ' ')
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] != 'r')
    return (-1);
  registre(param, str, i);
  while (str[i] != ',' && str[i] != 0)
    i++;
  if (str[i] != ',')
    return (-1);
  i++;
  st_param(str, i, param, cmd);
}
