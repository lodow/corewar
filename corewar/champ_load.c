/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"include.h"

/*
**Load a champ from a file filename and fill struct champ passed
** return 0 if everything good, negatif value elsewhere
*/
int	load_champ(const char *filename, t_champ *champ)
{
  char	*file;
  int	size;

  if ((size = get_bin_file(filename, &file)) <= ((int)sizeof(t_header)))
    return (-1);
  champ->freeme = file;
  if ((champ->header.magic = ((int*)switch_endian(file, sizeof(int)))[0])
      != COREWAR_EXEC_MAGIC)
    return (-2);
  file = &(file[sizeof(int)]);
  my_strncpy(champ->header.prog_name, file, PROG_NAME_LENGTH);
  file = &(file[PROG_NAME_LENGTH + 4]);
  champ->header.prog_size = ((int*)switch_endian(file, sizeof(int)))[0];
  file = &(file[sizeof(int)]);
  my_strncpy(champ->header.comment, file, COMMENT_LENGTH);
  file = &(file[COMMENT_LENGTH + 4]);
  champ->champcode = file;
  file = &(file[champ->header.prog_size]);
  return (0);
}

