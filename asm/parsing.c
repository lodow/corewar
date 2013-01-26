/*
** parsing.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Fri Jan 25 16:45:04 2013 maxime lavandier
** Last update Sat Jan 26 16:05:19 2013 maxime lavandier
*/

char	put_to_param(char param, char str)
{
  if (str[i] == 'r')
    {
      param <<= 2;
      param += 1;
      /*
	registre
       */
    }
  else if (str[i] == '%')
    {
      param <<= 2;
      param += 2;
      //direct
    }
  else
    {
      param <<= 2;
      param += 3;
      //indirect
    }
  return (param);
}

char	params(char *str, int i)
{
  char	param;
  int	j;

  j = 3;
  param = 0;
  while (str[i] != 0)
    {
      param = put_to_param(param, str[i])
      while (str[i] != 0 && str[i] != ',')
	i++;
      if (str[i] != 0)
	i++;
      j--;
    }
  param <<= (2 * j);
  return (param)
}

void	parsing(char *str)
{
  int	i;

  if (str == 0)
    return (0);
  i = next_label(str);
  if (str[i] == ' ')
    i++;

  /*
  ** recupéré le type de commande
  */
}
