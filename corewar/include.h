/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Jan 23 15:48:17 2013 luc sinet
*/

#ifndef _INCLUDE_H_
# define _INCLUDE_H_

# include	<unistd.h>
# include	"../misc/liste.h"
# include	"../misc/get_file.h"
# include	"../misc/str_func.h"
# include	"vmstats.h"
# include	"pars.h"
# include	"check_args.h"

# define MAX(x, y) (((x) > (y)) ? (x) : (y))

void	my_memset(void *ptr, int osize, char value);
char	*switch_endian(char *var, int varsize);

#endif
