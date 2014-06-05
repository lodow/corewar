#ifndef _GET_FILE_H_
# define _GET_FILE_H_

# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	"get_next_line.h"

# define LINEB_SIZE 2048
# if LINEB_SIZE < 1
#  undef LINEB_SIZE
#  define LINEB_SIZE 1
# endif
# define MAFS (str = malloc((tlen + 1) * sizeof(char)))

char	*get_file(const char *file);
char	**get_data_ffile(int fd);
char	*tab_file_tstr(char **tab_file);

#endif
