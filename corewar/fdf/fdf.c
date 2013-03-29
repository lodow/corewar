/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec  8 21:41:59 2012 Hugues
*/

#include	"include.h"

t_lsc	*get_elem_x(t_lsc *liste, unsigned int pos)
{
  if ((pos > 0) && ((liste->next)->data != NULL))
    return (get_elem_x(liste->next, pos - 1));
  return (liste);
}

void			draw_vert(t_init_x *win, t_transf_data *dat,
				  t_lsc *tmp_list, t_screen_point *p1)
{
  t_screen_point	p2;

  transf_t_scr(get_elem_x(tmp_list, 1)->data, win, dat, &p2);
  if ((p1->x < win->win_x || p2.x < win->win_x
       || p1->y < win->win_y || p2.y < win->win_y)
      && (p1->x > 0 || p2.x > 0
	  || p1->y > 0 || p2.y > 0))
    draw_line(p1, &p2, win);
}

void			draw_hor(t_init_x *win, t_transf_data *dat,
				 t_lsc *tmp_list, t_screen_point *p1)
{
  t_screen_point	p2;
  t_grid_info		*grid;

  grid = dat->grid;
  transf_t_scr(get_elem_x(tmp_list, grid->size_x + 1)->data, win, dat, &p2);
  if ((p1->x < win->win_x || p2.x < win->win_x
       || p1->y < win->win_y || p2.y < win->win_y)
      && (p1->x > 0 || p2.x > 0
	  || p1->y > 0 || p2.y > 0))
    draw_line(p1, &p2, win);
}

void			qadri(t_init_x *win, t_transf_data *dat)
{
  t_screen_point	p1;
  t_grid_info		*grid;
  t_lsc			*tmp_list;
  int			i;

  i = 0;
  grid = dat->grid;
  tmp_list = grid->points;
  while (i < ((grid->size_x + 1) * (grid->size_y)))
    {
      transf_t_scr(tmp_list->data, win, dat, &p1);
      if (dat->shadow)
        hide_face(win, dat, tmp_list);
      if ((((i + 1) % (grid->size_x + 1)) != 0))
	draw_vert(win, dat, tmp_list, &p1);
      if ((i + grid->size_x + 1) < ((grid->size_x + 1) * (grid->size_y)))
	draw_hor(win, dat, tmp_list, &p1);
      tmp_list = get_elem_x(tmp_list, 1);
      i++;
    }
}
