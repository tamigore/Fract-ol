/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:47:06 by tamigore          #+#    #+#             */
/*   Updated: 2021/11/11 18:20:45 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdio.h>
# include <stdarg.h>
# include "mlx.h"
# include "libmath.h"
# include "libft.h"

# define FAIL -1
# define WIN 1
# define END 0
# define TITLE "Fract-ol"
# define PIXEL_LEN 4
# define ZOOM 1.2

# define MAX_RGB 255
# define TRANS 3
# define RED 2
# define GREEN 1
# define BLUE 0
# define MAX_ITER 50

# define RES_MIN 300
# define RES_DEF 1000
# define MAX_RES_X 1280
# define MAX_RES_Y 770

/*
** t_set = struct for resolution
**
** check : checks if resolution is declared and not duplicated
** size_x: width of the image
** size_y: height of the image
*/

typedef struct s_set
{
	int		m;
	int		j;
	int		b;
	t_cmplx	c;
}			t_set;

/*
** t_res = struct for resolution
**
** check : checks if resolution is declared and not duplicated
** size_x: width of the image
** size_y: height of the image
*/

typedef struct s_res
{
	int	x;
	int	y;
}			t_res;

typedef struct s_mouse
{
	int	x;
	int	y;
}			t_mouse;

typedef struct s_view
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
}			t_view;

/*
** t_env = main struct
**
** sceen = contain the data from the sceen file
** mlx = mlx pointer returned by mlx_init()
** win = mlx pointer to the window screne
** save = bool to get the save option
** res = resolution (width and height) of the window
** amb = ambient light parameters
** nb_cam = number of cameras in the scene
** cam = cameras in the scene
** nb_lgt = number of lights in the scene
** lgt = point lights in the scene
** nb_obj = number of objects in the scene
** obj = objects in the scene
** ray = ray trace throught the scene
** img = rendered images
*/

typedef struct s_env
{
	int				p;
	struct s_set	set;
	void			*mlx;
	void			*win;
	struct s_res	res;
	struct s_img	*img;
	struct s_view	view;
	struct s_mouse	mouse;
}			t_env;

/*
** Image
**
** size_x = width of the image
** size_y = height of the image
** img_ptr = pointer returned by the mlx_new_image() function
** pixels = pointer to image data returned by the mlx_get_data_addr() function
** The 3 following values are obtained using mlx_get_data_addr()
** bpp = bits per pixels
** size_line = the size (char) of a line
** endian = endian type (big : 1 / small : 0)
** next = pointer to next image
*/

typedef struct s_img
{
	int		size_x;
	int		size_y;
	void	*ptr;
	char	*pixels;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

/*
** main.c
*/

t_env		init(char **av);
int			free_all(t_env *env, int x);
void		print(t_env *env);

/*
** graphic_loop.c
*/

void		graphic_loop(t_env *env);
int			next_cam(int keycode, t_env *env);
void		graphic_loop(t_env *env);
void		zoom(t_env *env, double z, int opt);
int			mouse_zoom(int button, int x, int y, t_env *env);

/*
** mlx_img.c
*/

t_img		*init_img(t_env *env);
void		delete_images(t_img *img, void *mlx_ptr);

/*
** init.c
*/

void		init_mouse_view(t_env *env);
void		init_view_set(t_env *env);
void		init_set(char *opt, t_env *env);
void		set(t_env *env, char *opt, int i);
void		init_res(char *set, t_env *env);

/*
** fractal.c
*/

int			j_set(t_cmplx z0, t_env *env);
int			m_set(t_cmplx z0, t_env *env);
int			b_set(t_cmplx z0, t_env *env);

/*
**	render.c
*/

double		pixel_point(t_env *env, int p, char opt);
void		render(t_env *env);

/*
**	color.c
*/

t_v3		palette(int i, int p, t_v3 color);

/*
**	mlx
*/

# ifdef LINUX
#  define BUTTON1				1
#  define BUTTON2				2
#  define BUTTON3				3
#  define BUTTON4				4
#  define BUTTON5				5
#  define KEYPRESS				2
#  define KEYRELEASE			3
#  define BUTTONPRESS			4
#  define BUTTONRELEASE			5
#  define MOTIONNOTIFY			6
#  define ENTERNOTIFY			7
#  define LEAVENOTIFY			8
#  define DESTROYNOTIFY			17
#  define SP_KEY 				32
#  define ESC_KEY 				65307
#  define LEFT_KEY				65361
#  define UP_KEY				65362
#  define RIGHT_KEY				65363
#  define DOWN_KEY				65364
#  define MULTI_KEY				65450
#  define PLUS_KEY				65451
#  define MOINS_KEY				65453
#  define DIV_KEY				65455
# else
#  define BUTTON1				1
#  define BUTTON2				2
#  define BUTTON3				3
#  define BUTTON4				4
#  define BUTTON5				5
#  define KEYPRESS				2
#  define KEYRELEASE			3
#  define BUTTONPRESS			4
#  define BUTTONRELEASE			5
#  define MOTIONNOTIFY			6
#  define ENTERNOTIFY			7
#  define LEAVENOTIFY			8
#  define DESTROYNOTIFY			17
#  define ESC_KEY 				53
#  define SP_KEY 				49
#  define LEFT_KEY				123
#  define UP_KEY				126
#  define RIGHT_KEY				124
#  define DOWN_KEY				125
#  define MULTI_KEY				67
#  define PLUS_KEY				69
#  define MOINS_KEY				78
#  define DIV_KEY				75
# endif

#endif
