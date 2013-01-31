/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu Jan 31 03:36:17 2013 luc sinet
*/

#include	"include.h"

/*
** Load a champ from a file filename and fill struct champ passed
** return 0 if everything good, negatif value elsewhere
*/
char	*loading_error(int error, char *name)
{
  my_putstr(name, 2, -1);
  my_putstr(" has a", 2, -1);
  if (error == 0)
    my_putstr("n incorrect header size\n", 2, -1);
  else if (error == 1)
    my_putstr("n incorrect magic number\n", 2, -1);
  else
    my_putstr(" size different from the size indicated in the file\n", 2, -1);
  return (NULL);
}

t_champ		*load_champ(int fd, int number, char *name)
{
  t_champ	*champ;
  char		*file;
  int		size;

  if (!(((size = get_bin_file(fd, &file)) > (int)sizeof(t_header))
      && (champ = malloc(sizeof(t_champ))) != NULL))
    return (loading_error(0, name));
  champ->freeme = file;
  if ((champ->header.magic = ((int*)switch_endian(file, sizeof(int)))[0])
      != COREWAR_EXEC_MAGIC)
    return (loading_error(1, name));
  file = &(file[sizeof(int)]);
  my_strncpy(champ->header.prog_name, file, PROG_NAME_LENGTH);
  file = &(file[PROG_NAME_LENGTH + 4]);
  champ->header.prog_size = ((int*)switch_endian(file, sizeof(int)))[0];
  if (size - (int)sizeof(t_header) != champ->header.prog_size)
    return (loading_error(2, name));
  file = &(file[sizeof(int)]);
  my_strncpy(champ->header.comment, file, COMMENT_LENGTH);
  file = &(file[COMMENT_LENGTH + 4]);
  champ->champcode = file;
  champ->number = number;
  champ->alive = 0;
  return (champ);
}
