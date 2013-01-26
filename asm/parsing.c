/*
** parsing.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Fri Jan 25 16:45:04 2013 maxime lavandier
** Last update Sat Jan 26 17:49:40 2013 maxime lavandier
*/

void	put_to_param(t_param *param, char *str, int i)
{
  if (str[i] == 'r')
    {
      param->param[1] <<= 2;
      param->param[1] += 1;

      /*
	registre
       */
    }
  else if (str[i] == '%')
    {
      param->param[1] <<= 2;
      param->param[1] += 2;
      if (str[i + 1] == ':');
      //fuuuuuuuuuuuuuuu
      //ragequit
      //fuck you
      //sucide yourself (jock hugues)

      //direct
    }
  else
    {
      param->param[1] <<= 2;
      param->param[1] += 3;
      //indirect
    }
}

char	params(char *str, int i, t_param *param)
{
  int	j;

  j = 3;
  param->param[1] = 0;
  while (str[i] != 0)
    {
      put_to_param(param, str, i)
      while (str[i] != 0 && str[i] != ',')
	i++;
      if (str[i] != 0)
	i++;
      j--;
    }
  param.param[1] <<= (2 * j);
}

void		parsing(char *str)
{
  int		i;
  t_param	param;

  if ((param.param = malloc(2)) == 0)
    exit(0);
  if (str == 0)
    return (0);
  i = next_label(str);
  if (str[i] == ' ')
    i++;
  params(str, i, param)

}
