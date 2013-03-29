/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec  8 21:47:38 2012 Hugues
*/

#include	"include.h"

void	get_color_fh(t_color *color, int h)
{
  char	cr[5];
  char	cg[5];
  char	cb[5];

  cr[0] = 255;
  cg[0] = 255;
  cb[0] = 255;
  cr[1] = 0;
  cg[1] = 0;
  cb[1] = 255;
  cr[2] = 0;
  cg[2] = 255;
  cb[2] = 0;
  cr[3] = 255;
  cg[3] = 255;
  cb[3] = 0;
  cr[4] = 255;
  cg[4] = 0;
  cb[4] = 0;
  h = h / 20;
  if (h > 4)
    h = 4;
  color->r = cr[h];
  color->g = cg[h];
  color->b = cb[h];
}

char	*get_file_color(t_color *color, char *file)
{
  char	nb;
  char	nb2;
  int	i;

  i = 0;
  if ((my_strlen(file) < 4) || (file[0] != ',')
      || (file[1] != '0') || (file[2] != 'x'))
    return (file);
  file = &(file[3]);
  color->r = 0;
  color->g = 0;
  color->b = 0;
  while ((nb = is_in_str(file[0], "0123456789abcdef")) != -1)
    {
      if ((nb2 = is_in_str(file[1], "0123456789abcdef") == -1))
	return (&(file[1]));
      nb = nb * 16 + nb2;
      file = &(file[2]);
      color->r = color->r + nb * (((i + 1) % 3) % 2);
      color->g = color->g + nb * (((i + 2) % 4) % 2);
      color->b = color->b + nb * (((i + 4) % 5) % 4);
      i++;
    }
  return (file);
}

void	add_3d_point(t_lsc *start, t_3d_point *point)
{
  while (start->next != NULL)
    {
      start = start->next;
    }
  start->next = malloc(1 * sizeof(t_lsc));
  start->data = point;
  if (start->next != NULL)
    {
      start = start->next;
      start->next = NULL;
      start->data = NULL;
    }
}

int		get_3d_point(char *buffer, t_lsc *liste, int y)
{
  t_3d_point	*tmp;
  int		x;

  x = 0;
  while (buffer[0] != '\0')
    {
      tmp = malloc(1 * sizeof(t_3d_point));
      if ((is_in_str(buffer[0], " 0123456789") == -1) || (tmp == NULL))
	buffer = &buffer[1];
      if (tmp != NULL)
        {
	  tmp->x = x;
	  tmp->y = y;
	  tmp->z = my_getnbr(buffer);
	  get_color_fh(&(tmp->color), tmp->z);
	  while (is_in_str(buffer[0], "0123456789") != -1)
	    buffer = &buffer[1];
	  buffer = get_file_color(&(tmp->color), buffer);
	  while (buffer[0] == ' ')
	    buffer = &buffer[1];
        }
      x++;
      add_3d_point(liste, tmp);
    }
  return (x);
}

t_grid_info	*Get_point_f_file(int fd)
{
    t_lsc	*liste;
    t_grid_info	*grid;
    char	*line;
    int		y;

    y = 0;
    if (!((fd >= 0) && ((grid = malloc(1 * sizeof(t_grid_info))) != NULL)
	  && ((liste = malloc(1 * sizeof(t_lsc))) != NULL)))
      return (NULL);
    liste->next = NULL;
    line = get_next_line(fd);
    grid->points = liste;
    grid->size_x = 0;
    while ((line != NULL) && (line[0] != '\0'))
      {
        grid->size_x = get_3d_point(line, liste, y) - 1;
        liste = get_elem_x(liste, grid->size_x);
        free(line);
        line = get_next_line(fd);
        y++;
      }
    free(line);
    grid->size_y = y;
    close(fd);
    return (grid);
}
