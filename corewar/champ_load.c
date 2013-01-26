/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Jan 26 19:14:46 2013 luc sinet
*/

#include	"include.h"

/*
** Load a champ from a file filename and fill struct champ passed
** return 0 if everything good, negatif value elsewhere
*/

t_champ		*load_champ(int fd, int number)
{
  t_champ	*champ;
  char		*file;
  int		size;

  if (!(((size = get_bin_file(fd, &file)) > (int)sizeof(t_header))
      && (champ = malloc(1 * sizeof(t_champ))) != NULL))
    return (NULL);
  champ->freeme = file;
  if ((champ->header.magic = ((int*)switch_endian(file, sizeof(int)))[0])
      != COREWAR_EXEC_MAGIC)
    return (NULL);
  file = &(file[sizeof(int)]);
  my_strncpy(champ->header.prog_name, file, PROG_NAME_LENGTH);
  file = &(file[PROG_NAME_LENGTH + 4]);
  champ->header.prog_size = ((int*)switch_endian(file, sizeof(int)))[0];
  if (size - (int)sizeof(t_header) != champ->header.prog_size)
    my_putstr("Champ code size differ from size in header\n", 2, -1);
  file = &(file[sizeof(int)]);
  my_strncpy(champ->header.comment, file, COMMENT_LENGTH);
  file = &(file[COMMENT_LENGTH + 4]);
  champ->champcode = file;
  champ->number = number;
  champ->alive = 0;
  return (champ);
}

