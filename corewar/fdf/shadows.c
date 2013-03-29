/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec  8 21:50:18 2012 Hugues
*/

#include	"include.h"

void	rasterize_tri(t_screen_point *p1, t_screen_point *p2,
                      t_screen_point *p3 , t_init_x *win)
{
  int	maxx;
  int	minx;
  int	maxy;
  int	miny;
  int	x;
  int	y;

  maxx = MAX(MAX(p1->x, p2->x), p3->x);
  maxy = MAX(MAX(p1->y, p2->y), p3->y);
  minx = MIN(MIN(p1->x, p2->x), p3->x);
  miny = MIN(MIN(p1->y, p2->y), p3->y);
  y = miny - 1;
  while (((y++) || 1) && ((x = minx) == minx) && (y < maxy))
    while (x < maxx)
      {
	if ((p1->x - p2->x) * (y - p1->y) - (p1->y - p2->y) * (x - p1->x) > 0
	    && (p2->x - p3->x) * (y - p2->y)
	    - (p2->y - p3->y) * (x - p2->x) > 0
	    && (p3->x - p1->x) * (y - p3->y)
	    - (p3->y - p1->y) * (x - p3->x) > 0)
	  put_pixel_img(win, x, y, &(p1->color));
	x++;
      }
}

void			hide_tri(t_face *face, t_init_x *win)
{
  t_screen_point	*ps1;
  t_screen_point	*ps2;
  t_screen_point	*ps3;

  ps1 = face->p1;
  ps2 = face->p2;
  ps3 = face->p3;
  if ((ps1->x < win->win_x || ps2->x < win->win_x || ps3->x < win->win_x
       || ps1->y < win->win_y || ps2->y < win->win_y || ps3->y < win->win_y)
      && (ps1->x > 0 || ps2->x > 0 || ps3->x > 0
	  || ps1->y > 0 || ps2->y > 0 || ps3->y > 0))
    rasterize_tri(ps1, ps2, ps3 , win);
}

void		hide_square(t_face *face, t_init_x *win)
{
  t_face	face1;
  t_face	face2;

  face1.p1 = face->p3;
  face1.p2 = face->p2;
  face1.p3 = face->p1;
  face2.p1 = face->p2;
  face2.p2 = face->p3;
  face2.p3 = face->p4;
  face1.p1->color = face->p1->color;
  face2.p1->color = face->p2->color;
  hide_tri(&face1, win);
  hide_tri(&face2, win);
  draw_line(face->p2, face->p3, win);
}

void			hide_face(t_init_x *win, t_transf_data *dat,
				  t_lsc *tmp_list)
{
  t_face		face;
  t_screen_point	ps1;
  t_screen_point	ps2;
  t_screen_point	ps3;
  t_screen_point	ps4;

  transf_t_scr(CAST_3D(get_elem_x(tmp_list, 0)->data), win, dat, &ps1);
  transf_t_scr(CAST_3D(get_elem_x(tmp_list, 1)->data), win, dat, &ps2);
  transf_t_scr(CAST_3D(get_elem_x(tmp_list, GX + 1)->data), win, dat, &ps3);
  transf_t_scr(CAST_3D(get_elem_x(tmp_list, GX + 2)->data), win, dat, &ps4);
  face.p1 = &ps1;
  face.p2 = &ps2;
  face.p3 = &ps3;
  face.p4 = &ps4;
  if (dat->colored_shad == 0)
    {
      face.p1->color.r = 0;
      face.p1->color.g = 0;
      face.p1->color.b = 0;
      face.p2->color.r = 0;
      face.p2->color.g = 0;
      face.p2->color.b = 0;
    }
  hide_square(&face, win);
}
