/*
** exec_select.c for exec_s in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Mar 19 18:07:33 2013 luc sinet
** Last update Tue Mar 26 14:18:23 2013 luc sinet
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include "pre_pars.h"
#include "../misc/str_func.h"

int		count_file(char *folder)
{
  DIR		*dirp;
  struct dirent	*dp;
  int		nb_file;

  nb_file = 0;
  if ((dirp = opendir(folder)) == NULL)
    return (0);
  while ((dp = readdir(dirp)) != NULL)
    nb_file++;
  closedir(dirp);
  return (nb_file);
}

char	*concat_path_file(char *path, char *file)
{
  char	*fullpath;

  if ((fullpath = malloc(my_strlen(path) + my_strlen(file) + 1)) == NULL)
    {
      my_putstr("Malloc error\n", 2, -1);
      return (NULL);
    }
  fullpath[0] = '\0';
  my_strcat(fullpath, path);
  my_strcat(fullpath, file);
  return (fullpath);
}

char		**get_file_form_folder(char *folder, int nb_file, char **file)
{
  DIR		*dirp;
  struct stat	s;
  struct dirent	*dp;
  char		*fullname;

  if ((nb_file = count_file(folder)) == 0 ||
      (file = malloc(sizeof(char *) * (nb_file + 2))) == NULL)
    return (NULL);
  if ((file[0] = my_strdup("my_select")) == NULL ||
      (dirp = opendir(folder)) == NULL)
    return (NULL);
  nb_file = 1;
  while ((dp = readdir(dirp)) != NULL)
    {
      if ((fullname = concat_path_file(folder, dp->d_name)) == NULL ||
	  stat(fullname, &s) == -1)
	return (NULL);
      if ((s.st_mode & MASK) == ISFILE)
	if ((file[nb_file++] = my_strdup(fullname)) == NULL)
	  return (NULL);
      free(fullname);
    }
  file[nb_file] = '\0';
  closedir(dirp);
  return (file);
}

char	**exec_child(char **args, char **env, char *folder, t_sel *spt)
{
  char	**sel_args;
  char	*real_folder;

  close(spt->fd[0]);
  dup2(spt->fd[1], 1);
  close(spt->fd[1]);
  if ((real_folder = renew_folder(folder)) == NULL ||
      (sel_args = get_file_form_folder(real_folder, 0, NULL)) == NULL)
    exit(0);
  free(real_folder);
  if (execve("./my_select", sel_args, env) == -1)
    {
      my_putstr("failed to execute my_select", 2, -1);
      exit(0);
    }
  return (sel_args);
}

char	**launch_select(char **args, char **env, char *folder)
{
  t_sel	spt;

  if (pipe(spt.fd) == -1 || (spt.sel_res = malloc(1024)) == NULL)
    return (NULL);
  if ((spt.pid = fork()) == -1)
    return (NULL);
  if (spt.pid == 0)
    {
      if (exec_child(args, env, folder, &spt) == NULL)
	return (args);
    }
  else
    {
      waitpid(spt.pid, NULL, 0);
      close(spt.fd[1]);
      if ((spt.read_size = read(spt.fd[0], spt.sel_res, 1023)) == -1)
	return (args);
      spt.sel_res[spt.read_size] = '\0';
    }
  return (spt.sel_res[0] == '\0' ? args : change_args(args, folder, &spt));
}
