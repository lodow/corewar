/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun Jan 27 17:02:38 2013 luc sinet
*/

#ifndef _INCLUDE_H_
# define _INCLUDE_H_

# include	<unistd.h>
# include	"../misc/liste.h"
# include	"../misc/get_file.h"
# include	"../misc/str_func.h"
# include	"../misc/nb_func.h"
# include	"vmstats.h"
# include	"pars.h"
# include	"op/operation.h"
# include	"pars.h"

# define MAX(x, y) (((x) > (y)) ? (x) : (y))

# define BIN_BUFFER 4096

int	get_bin_file(int fd, char **file);
char	*switch_endian(char *var, int varsize);

#endif
