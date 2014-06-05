#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c, int output)
{
  if (write(output, &c, 1) == -1)
    if (write(2, "Write error\n", 12) == -1)
      exit(0);
}

void	my_putstr(char *s1, int output)
{
  int	i;

  i = 0;
  if (s1 != NULL)
    while (s1[i])
      my_putchar(s1[i++], output);
}

char	*my_strdup(char *src)
{
  int   lenght;
  char  *dest;
  int   i;

  i = 0;
  lenght = my_strlen(src);
  if ((dest = malloc(lenght + 1)) == NULL)
    return (NULL);
  while (i < lenght)
    dest[i] = src[i++];
  dest[i] = '\0';
  return (dest);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  int	i1;
  int	i2;

  i1 = 0;
  i2 = 0;
  while (dest[i1])
    i1++;
  while (src[i2])
    {
      dest[i1] = src[i2];
      i1++;
      i2++;
    }
  dest[i1] = '\0';
  return (dest);
}
