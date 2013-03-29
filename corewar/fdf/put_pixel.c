/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec  8 21:38:18 2012 Hugues
*/

#include	"include.h"

t_color	*init_color(unsigned char r, unsigned char g, unsigned char b,
                    t_color *color)
{
  color->r = r;
  color->g = g;
  color->b = b;
  return (color);
}

t_color		*interpolate_color(t_color *color1, t_color *color2,
                             float coeff, t_color *fin_color)
{
  fin_color->r = ((float)(color1->r) * coeff)
                 + ((float)(color2->r) * (1.0 - coeff));
  fin_color->g = ((float)(color1->g) * coeff)
                 + ((float)(color2->g) * (1.0 - coeff));
  fin_color->b = ((float)(color1->b) * coeff)
                 + ((float)(color2->b) * (1.0 - coeff));
  return (fin_color);
}

int	color_to_int(unsigned char r, unsigned char g, unsigned char b)
{
  int	color;

  color = r << 16 | g << 8 | b;
  return (color);
}

void			put_pixel_img(t_init_x *win, int x, int y,
                        t_color *color)
{
  int			size_line;
  int			bpp;
  int			endian;
  char			*screen;
  unsigned int		fin_color;

  screen = mlx_get_data_addr(win->screen , &bpp, &size_line, &endian);
  bpp = (bpp / 8);
  if (((x > -1) && (x <= win->win_x - 1) && (y > -1) && (y <= win->win_y)))
    if ((bpp == 4) && (!endian))
      {
        fin_color = mlx_get_color_value(win->init, COL_INT(color));
        size_line = size_line / bpp;
        (((int*)screen)[y * size_line + x]) = fin_color;
      }
}
