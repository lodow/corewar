/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Mar 26 15:51:11 2013 luc sinet
*/

#ifndef _INCLUDE_H_
# define _INCLUDE_H_

# include	<unistd.h>
# include	"../misc/liste.h"
# include	"../misc/get_file.h"
# include	"../misc/str_func.h"
# include	"../misc/nb_func.h"
# include	"vmstats.h"
# include	"pars.h"
# include	"pre_pars.h"
# include	"op/operation.h"
# include	"pars.h"

# define MAX(x, y) (((x) > (y)) ? (x) : (y))
# define SETFLAG(x, y) ((x) |= (y))
# define UNSETFLAG(x, y) ((x) &= ~(y))
# define SWITCHFLAG(x, y) ((x) ^= (y))
# define GETFLAG(x, y) ((x) & (y))
# define FLAGPOS(x) (1 << (x))

# define UNLIMITEDOPT 0
# define DEBUGOPT 1
# define USEFDFOPT 2
# define BIN_BUFFER 4096

int	get_bin_file(int fd, char **file);
char	*switch_endian(char *var, int varsize);
void	set_numval(t_arg *parg);
void	void_func();
char	*my_uint_strbase(unsigned int nb, char *base);
int	my_swap_char(char *a, char *b);

/*
** FDF STUFF
*/
# include <mlx.h>
# include <unistd.h>

# define COL_INT(x) color_to_int((x)->r, (x)->g, (x)->b)
# define LINE_CALC (coeff * (float)(imin + i) + offset)
# define COL_C (i / ((ABS(imax) - ABS(imin)) + 0.10101))
# define INT_COL interpolate_color(&(p1->color), &(p2->color), COL_C, &(tmp))

# define FPS 120

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
}		t_init_x;

typedef struct	s_color
{
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
}		t_color;

typedef struct	s_screen_point
{
  int		x;
  int		y;
  t_color	color;
}		t_screen_point;

int		init_windows(t_init_x *init, int x, int y, void *data);
int		expose(t_init_x *win);
void		draw_line(t_screen_point *p1, t_screen_point *p2,
                  t_init_x *win);
t_color	*interpolate_color(t_color *color1, t_color *color2,
                           float coeff, t_color *fin_color);
t_color	*init_color(unsigned char r, unsigned char g, unsigned char b,
                    t_color *color);
void		put_pixel_img(t_init_x *win, int x, int y, t_color *color);
void		swap_ptr(void **screen1, void **screen2);
void		fdf_calculations(t_init_x *win);

#endif
