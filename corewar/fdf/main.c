/*
** main.c for mini in /home/moriss_h//projets/minilibx
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Thu Oct 25 12:30:58 2012 hugues morisset
** Last update Sat Dec  8 23:46:35 2012 hugues morisset
*/

#include	"include.h"

int	loop(t_init_x *win)
{
  if ((win->nb_frame < 10) || (win->expose))
    expose(win);
  usleep(500);
  return (0);
}

void	print_help()
{
  write(1, "Usage is ./fdf file\n"
	"\nKey are: \n"
	"Up arrow: Move up\n"
	"Down arrow: Move down\n"
	"Left arrow: Move left\n"
	"Right arrow: Move right\n"
	"+ key: zoom in\n"
	"- key: zoom out\n"
	"Up key: move z up\n"
	"Down key: move z down\n"
	"M key: toggle hidden faces\n"
	"L key: toggle colored hidden faces\n"
	"T key: Rotate up ??\n"
	"G key: Rotate down ??\n"
	"Esc key: Quit\n", 306);
}

int		key2(int keycode, t_init_x *win)
{
  t_transf_data	*dat;

  dat = (t_transf_data*)(win->data);
  if (keycode == KM)
    dat->shadow = ((dat->shadow + 1) % 2);
  else if (keycode == KL)
    dat->colored_shad = ((dat->colored_shad + 1) % 2);
  else if (keycode == KR)
    center_fdf(dat, win);
  else if (keycode == KT)
    {
      dat->cst1 = (dat->cst1 + 0.01);
      dat->cst2 = (dat->cst2 - 0.01);
    }
  else if (keycode == KG)
    {
      dat->cst1 = (dat->cst1 - 0.01);
      dat->cst2 = (dat->cst2 + 0.01);
    }
}

int		key(int keycode, t_init_x *win)
{
  t_transf_data	*dat;

  dat = (t_transf_data*)(win->data);
  if (keycode == ESC)
    free_all_and_exit(win);
  else if (keycode == PLUS)
    dat->zoom = dat->zoom * 1.1;
  else if (keycode == MOINS)
    dat->zoom = dat->zoom / 1.1;
  else if (keycode == UP)
    dat->h_zoom = dat->h_zoom + 0.1;
  else if (keycode == DOWN)
    dat->h_zoom = dat->h_zoom - 0.1;
  else if (keycode == AUP)
    dat->offset_x = dat->offset_x + dat->zoom * 4;
  else if (keycode == ADOWN)
    dat->offset_x = dat->offset_x - dat->zoom * 4;
  else if (keycode == ARIGHT)
    dat->offset_y = dat->offset_y - dat->zoom * 4;
  else if (keycode == ALEFT)
    dat->offset_y = dat->offset_y + dat->zoom * 4;
  else
    key2(keycode, win);
  win->expose = 1;
  return (0);
}

int		main(int c, char **v)
{
  t_init_x	win;
  t_transf_data	*data;

  if (c > 1)
    {
      if ((data = malloc(1 * sizeof(t_transf_data))) == NULL)
	return (-1);
      data->grid = Get_point_f_file(open(v[1], O_RDONLY));
      if (data->grid != NULL)
	{
	  if (init_windows(&win, 1024, 768, data) == -1)
            return (-1);
	  center_fdf(data, &win);
	  mlx_expose_hook(win.windows, &expose, &win);
	  mlx_key_hook(win.windows, &key, &win);
	  mlx_loop_hook(win.init, &loop, &win);
	  mlx_loop(win.init);
	  free_all_and_exit(&win);
	}
    }
  else
    print_help();
  return (0);
}
