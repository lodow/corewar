/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 15 17:02:37 2013 adrien dellamaggiora
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != 0)
    while (str[i] != 0)
      write(1, &str[i++], 1);
}

int	main(int argc, char **argv, char **envp)
{
  my_putstr("Hello World !!\n");
  return (0);
}
