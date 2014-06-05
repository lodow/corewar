#ifndef PRE_H_
# define PRE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

# define MASK 0170000
# define ISDIR 0040000
# define ISFILE 0100000

typedef struct	s_sel
{
  char		**new_args;
  char		**sel_tab;
  char		*sel_res;
  int		fd[2];
  int		pid;
  int		read_size;
}		t_sel;

char	*renew_folder(char *folder);
char	**change_args(char **args, char *folder, t_sel *spt);
int	tab_size(char **tab);
char	**launch_select(char **args, char **env, char *folder);
char	**pre_pars(char **args, char **env);

#endif
