#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

# include <stdlib.h>
# include <unistd.h>
# include "str_func.h"

# define READ_SIZE 4096
# if READ_SIZE < 0
#  undef READ_SIZE
#  define READ_SIZE 0
# endif

char	*get_next_line(const int fd);

#endif
