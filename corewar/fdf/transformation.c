/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec  8 21:56:33 2012 Hugues
*/

#include	"include.h"

void		center_fdf(t_transf_data *dat, t_init_x *win)
{
  t_grid_info	*grid;

  grid = dat->grid;
  dat->zoom = (win->win_x / (grid->size_x + 2)
	       + win->win_y / (grid->size_y + 2)) / 2;
  dat->f_zoom = dat->zoom;
  dat->h_zoom = 1.0;
  dat->offset_x = (win->win_x) - (grid->size_x * dat->zoom) / 1;
  dat->offset_y = (win->win_y) + ((grid->size_y / 4) * dat->zoom) / 2;
  dat->cst1 = 0.75;
  dat->cst2 = 0.75;
  dat->shadow = 0;
  dat->colored_shad = 0;
}

t_screen_point	*transf_t_scr(t_3d_point *pt, t_init_x *win,
                              t_transf_data *dat, t_screen_point *res)
{
  float		z;
  float		x;
  float		y;

  z = (((float)(win->nb_frame + 1)) / 10.0) * pt->z;
  if (z > pt->z)
    z = pt->z;
  z = (-z) * (dat->zoom / dat->f_zoom) * dat->h_zoom;
  x = dat->zoom * ((-pt->x) + ((dat->grid)->size_x / 2)) + (dat->offset_x);
  y = dat->zoom * ((pt->y) - ((dat->grid)->size_y / 2)) + (dat->offset_y);
  res->x = -dat->cst1 * x + dat->cst2 * y;
  res->y = z + (dat->cst1 / 2) * x + (dat->cst2 / 2) * y;
  res->color = pt->color;
  return (res);
}

int	is_in_str(char c, char *base)
{
  int	i;

  i = 0;
  while (i < my_strlen(base))
    {
      if (c == base[i])
	return (i);
      i++;
    }
  return (-1);
}
