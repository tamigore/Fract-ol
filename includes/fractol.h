#ifndef _FRACTOL_H_
# define _FRACTOL_H_

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

# define LINUX 1

# define FAIL -1
# define WIN 1
# define END 0
# define TITLE "Fractol"
# define PIXEL_LEN 4

# define MAX_RGB 255
# define TRANS 3
# define RED 2
# define GREEN 1
# define BLUE 0
# define MAX_ITER 1000

# define ABS(x) (x < 0 ? -x : x)
# define RES_MIN 300
# define RES_DEF 1000

/*
** t_set = struct for resolution
**
** check : checks if resolution is declared and not duplicated
** size_x: width of the image
** size_y: height of the image
*/

typedef struct		s_set
{
	int				M;
	int				J;
    int             a;
    int             c;
}					t_set;

/*
** t_res = struct for resolution
**
** check : checks if resolution is declared and not duplicated
** size_x: width of the image
** size_y: height of the image
*/

typedef struct		s_res
{
	int				check;
	int				x;
	int				y;
}					t_res;

typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
	int			lock;
}					t_mouse;

typedef struct		s_view
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
	t_cmplx		mouse;
}					t_view;

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

typedef struct		s_env
{
	struct s_set	set;
	void			*mlx;
	void			*win;
	struct s_view	view;
	struct s_res	res;
	struct s_mouse	mouse;
	struct s_img	*img;
}					t_env;

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

typedef struct		s_img
{
	int				size_x;
	int				size_y;
	void			*ptr;
	char			*pixels;
	int				bpp;
	int				size_line;
	int				endian;
	double			scale;
	int				ori_x;
	int				ori_y;
	struct s_img	*prev;
	struct s_img	*next;
}					t_img;

/*
** main.c
*/

void        free_all(t_env *env, int opt);
void        print(int opt, t_env *env);

/*
** graphic_loop.c
*/

void		zoom(t_env *env, double z, int *valid);
void		move(int key, t_env *env);
int			key(int keycode, t_env *env);
int			expose(t_env *env);
void		graphic_loop(t_env *env);

/*
** mouse.c
*/

int			mouse_move(int x, int y, t_env *env);
int			mouse_up(int button, int x, int y, t_env *env);
int			mouse_down(int button, int x, int y, t_env * env);

/*
** mlx_img.c
*/

t_img		*init_img(t_env *env);
void		append_image(t_img **imgs, t_img *new);
void		delete_images(t_img **imgs, void *mlx_ptr);

/*
** init.c
*/

t_env           *init(int ac, char **av);

/*
** fractol.c
*/

double			M_set(t_env *env, int px, int py);

/*
** render.c
*/

void			put_pixel_to_img(t_env *env, t_v3 color, int x, int y);
t_v3			palette(int	x);
void       		render(t_env *env);

/*
**	view.c
*/

void			init_view(t_env * env);
void			reset_view(t_env *env);
void			view_scale(t_env *env);

/*
**	mlx
*/

# ifdef __linux__
#  define K_ESC 65307
#  define K_NUM_MULT 65450
#  define K_NUM_DIV 65455
#  define K_NUM_PLUS 65451
#  define K_NUM_MINUS 65453
#  define K_NUM_ENTER 65421
#  define K_NUM_0 65438
#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363
#  define K_DIGIT_1 49
#  define K_L 108
# else
#  define K_ESC 53
#  define K_NUM_MULT 67
#  define K_NUM_DIV 75
#  define K_NUM_PLUS 69
#  define K_NUM_MINUS 78
#  define K_NUM_ENTER 76
#  define K_NUM_0 82
#  define K_UP 126
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_RIGHT 124
#  define K_DIGIT_1 18
#  define K_L 37
# endif

#endif