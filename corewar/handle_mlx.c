/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec  8 23:52:15 2012 hugues morisset
*/

#include	"include.h"

void	swap_ptr(void **screen1, void **screen2)
{
  void	*tmp;

  tmp = *screen2;
  *screen2 = *screen1;
  *screen1 = tmp;
}

void	clear_screen(t_init_x *win, t_color *color)
{
  int	i;
  int	j;

  j = win->win_y;
  while (j >= 0)
    {
      i = win->win_x;
      while (i >= 0)
        {
          put_pixel_img(win, i, j, color);
          i--;
        }
      j--;
    }
}

void		draw_screen(t_init_x *win, float fps)
{
  t_color	tmp;

  init_color(0, 0, 0, &tmp);
  mlx_put_image_to_window(win->init , win->windows, win->screen, 0, 0);
  (win->expose)--;
  if ((float)fps > 0.01)
    {
      swap_ptr(&(win->screen), &(win->back_screen));
      clear_screen(win, &tmp);
      (win->nb_frame)++;
      usleep((int)((1.0 / fps) * 1000000.0));
    }
}

int	init_windows(t_init_x *init, int x, int y, void *data)
{
  init->init = mlx_init();
  if (init->init == NULL)
    return (-1);
  init->windows = mlx_new_window(init->init, x, y, "Corewar");
  if (init->windows == NULL)
    return (-1);
  init->win_x = x;
  init->win_y = y;
  init->screen = mlx_new_image(init->init, x, y);
  init->back_screen = mlx_new_image(init->init, x, y);
  init->nb_frame = 0;
  init->data = data;
  if ((init->screen == NULL) || (init->back_screen == NULL))
    return (-1);
  return (0);
}

int	expose(t_init_x *win)
{
/*  do calculation here;*/
  draw_screen(win, FPS);
  return (0);
}
