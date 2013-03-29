/*
** include.h for include in /home/moriss_h//projets/minilibx
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Thu Oct 25 12:28:07 2012 hugues morisset
** Last update Sat Dec  8 22:53:03 2012 hugues morisset
*/

#ifndef INCLUDE_H_
# define INCLUDE_H_

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"

# define GX dat->grid->size_x
# define CAST_3D (t_3d_point*)
# define LINE_CALC (coeff * (float)(imin + i) + offset)
# define COL_C (i / ((ABS(imax) - ABS(imin)) + 0.10101))
# define INTER_COL interpolate_color(&(p1->color), &(p2->color), COL_C, &(tmp))
# define COL_INT(x) color_to_int((x)->r, (x)->g, (x)->b)
# define MAX(x, y) (((x) > (y)) ? (x) : (y))
# define MIN(x, y) (((x) < (y)) ? (x) : (y))
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define ESC 65307
# define PLUS 65451
# define MOINS 65453
# define UP 65366
# define DOWN 65365
# define AUP 65362
# define ADOWN 65364
# define ARIGHT 65363
# define ALEFT 65361
# define KM 109
# define KL 108
# define KR 114
# define KT 116
# define KG 103

typedef struct	s_init_x
{
  void		*init;
  void		*windows;
  void		*screen;
  void		*back_screen;
  int		expose;
  int		win_x;
  int		win_y;
  int		nb_frame;
  void		*data;
} t_init_x;

typedef struct	s_color
{
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
} t_color;

typedef struct	s_screen_point
{
  int		x;
  int		y;
  t_color	color;
} t_screen_point;

typedef struct	s_3d_point
{
  float		x;
  float		y;
  float		z;
  t_color	color;
} t_3d_point;

typedef struct	s_lsc
{
  void		*data;
  struct s_lsc	*next;
} t_lsc;

typedef struct	s_grid_info
{
  t_lsc		*points;
  int		size_x;
  int		size_y;
} t_grid_info;

typedef struct	s_transf_data
{
  float		cst1;
  float		cst2;
  float		zoom;
  float		f_zoom;
  float		h_zoom;
  float		offset_x;
  float		offset_y;
  int		shadow;
  int		colored_shad;
  t_grid_info	*grid;
} t_transf_data;

typedef	struct		s_face
{
  t_screen_point	*p1;
  t_screen_point	*p2;
  t_screen_point	*p3;
  t_screen_point	*p4;
} t_face;

void		qadri(t_init_x *win, t_transf_data *dat);
t_screen_point	*transf_t_scr(t_3d_point *pt, t_init_x *win,
                              t_transf_data *dat, t_screen_point *res);
t_lsc		*get_elem_x(t_lsc *liste, unsigned int pos);
t_grid_info	*Get_point_f_file(int fd);
void		int_to_color(int color, unsigned char *r,
			     unsigned char *g, unsigned char *b);
int		is_in_str(char c, char *base);
int		my_strlen(char *str);
int		my_getnbr(char *str);
void		put_pixel_img(t_init_x *win, int x, int y, t_color *color);
void		draw_line(t_screen_point *p1, t_screen_point *p2,
			  t_init_x *win);
int		expose(t_init_x *win);
t_screen_point	*draw_lineshad(t_screen_point *p1, t_screen_point *p2,
			       int i, t_color *color);
void		free_all_and_exit(t_init_x *win);
void		swap_ptr(void **screen1, void **screen2);

#endif
