int	my_swap_char(char *a, char *b)
{
  if (a != b )
    {
      *a = *a + *b;
      *b = *a - *b;
      *a = *a - *b;
    }
  return (0);
}

char	*switch_endian(char *var, int varsize)
{
  int	i;
  int	j;

  i = 0;
  while (i < varsize)
    {
      j = 0;
      while (j < i)
        {
          my_swap_char(&var[i], &var[j]);
          j++;
        }
      i++;
    }
  return (var);
}
