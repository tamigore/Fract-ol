#ifndef _FRACT_OL_H_
# define _FRACT_OL_H_

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
	struct s_res	res;
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

void		graphic_loop(t_env *env);
int			next_cam(int keycode, t_env *env);
void		graphic_loop(t_env *env);
int			zoom(t_env *env, int opt);

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


void			M_set(t_env *env);

/*
**	mlx
*/

/*
** # define NOEVENTMASK 0L
** # define KEYPRESSMASK (1L<<0)
** # define KEYRELEASEMASK (1L<<1)
** # define BUTTONPRESSMASK (1L<<2)
** # define BUTTONRELEASEMASK (1L<<3)
** # define ENTERWINDOWMASK (1L<<4)
** # define LEAVEWINDOWMASK (1L<<5)
** # define POINTERMOTIONMASK (1L<<6)
** # define POINTERMOTIONHINTMASK (1L<<7)
** # define BUTTON1MOTIONMASK (1L<<8)
** # define BUTTON2MOTIONMASK (1L<<9)
** # define BUTTON3MOTIONMASK (1L<<10)
** # define BUTTON4MOTIONMASK (1L<<11)
** # define BUTTON5MOTIONMASK (1L<<12)
** # define BUTTONMOTIONMASK (1L<<13)
** # define KEYMAPSTATEMASK (1L<<14)
** # define EXPOSUREMASK (1L<<15)
** # define VISIBILITYCHANGEMASK (1L<<16)
** # define STRUCTURENOTIFYMASK (1L<<17)
** # define RESIZEREDIRECTMASK (1L<<18)
** # define SUBSTRUCTURENOTIFYMASK (1L<<19)
** # define SUBSTRUCTUREREDIRECTMASK (1L<<20)
** # define FOCUSCHANGEMASK (1L<<21)
** # define PROPERTYCHANGEMASK (1L<<22)
** # define COLORMAPCHANGEMASK (1L<<23)
** # define OWNERGRABBUTTONMASK (1L<<24)
*/

# define KEYPRESSMASK 1
# define STRUCTURENOTIFYMASK 131072

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24

/*
** Mouse button keycodes
*/

# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define SCROLLLEFT_KEY 6
# define SCROLLRIGHT_KEY 7

/*
** Keyboard keys
*/

/*
** Letters keys
*/

# define A_KEY 97
# define B_KEY 11
# define C_KEY 8
# define D_KEY 100
# define E_KEY 14
# define F_KEY 3
# define G_KEY 5
# define H_KEY 4
# define I_KEY 34
# define J_KEY 38
# define K_KEY 40
# define L_KEY 37
# define M_KEY 46
# define N_KEY 45
# define O_KEY 31
# define P_KEY 35
# define Q_KEY 12
# define R_KEY 15
# define S_KEY 115
# define T_KEY 17
# define U_KEY 32
# define V_KEY 9
# define W_KEY 119
# define X_KEY 7
# define Y_KEY 16
# define Z_KEY 6

/*
** Numbers (not numeric keypad ones)
*/

# define K1_KEY 18
# define K2_KEY 19
# define K3_KEY 20
# define K4_KEY 21
# define K5_KEY 23
# define K6_KEY 22
# define K7_KEY 26
# define K8_KEY 28
# define K9_KEY 25
# define K0_KEY 29

/*
** Special characters
** SP_KEY is the space ( ) key
** BQ_KEY is the back quote (`) and tilde (~) key
** MN_KEY is the minus (-) and underscore (_) key
** PL_KEY is the plus (+) and equal (=) key
** SBO_KEY is the square bracket opening ([) and brace opening ({) key
** SBC_KEY is the square bracket closing (]) and brace closing (}) key
** BSL_KEY is the backslash (\) and pipe (|) key
** SC_KEY is the semicolon (;) and colon (:) key
** SQ_KEY is the simple quote (') and double quote (") key
** CM_KEY is the comma (,) and angle bracket opening (<) key
** PT_KEY is the point (.) and angle bracket closing (>) key
** SL_KEY is the slash (/) and question mark (?) key
*/

# ifdef LINUX
#  define SP_KEY 32
# else
#  define SP_KEY 49
# endif
# define BQ_KEY 50
# define MN_KEY 27
# define PL_KEY 24
# define SBO_KEY 33
# define SBC_KEY 30
# define BSL_KEY 42
# define SC_KEY 41
# define SQ_KEY 39
# define CM_KEY 43
# define PT_KEY 47
# define SL_KEY 44

/*
** Functions keys, you might use fn key to use them
** Seems that did not work. I don't know. Deso pas deso, au pire on les use pas.
*/
/*
# define F1_KEY 122
# define F2_KEY 120
# define F3_KEY 99
# define F4_KEY 118
# define F5_KEY 96
# define F6_KEY 97
# define F7_KEY 98
# define F8_KEY 100
# define F9_KEY 101
# define F10_KEY 109
# define F11_KEY
# define F12_KEY 111
# define F13_KEY 105
# define F14_KEY 107
# define F15_KEY 113
# define F16_KEY 106
# define F17_KEY 64
# define F18_KEY 79
# define F19_KEY 80
*/
/*
** Arrow keys
*/

# define UP_KEY 0xff52
# define DOWN_KEY 0xff54
# define RIGHT_KEY 65363
# define LEFT_KEY 65361

/*
** Special keys
** CL_KEY is the caps lock key
** LSFT_KEY and RLFT_KEY are the left shift and right shift keys
** LCTRL_KEY and RCTRL_KEY are the left control and right control keys
** LOPT_KEY and ROPT_KEY are the left option and right option keys
** LCMD_KEY and RCMD_KEY are the left command and right command keys
** LDEL_KEY and RDEL_KEY are the left delete and right delete keys
** RTN_KEY is the return key
** EJ_KEY is the eject key and doesn't react
** PUP_KEY and PDOWN_KEY are the page up and page down keys
** CLR_KEY is the clear key
*/

# ifdef MACOS
#  define ESC_KEY 53
# else
#  define ESC_KEY 65307
# endif
# define TAB_KEY 48
# define CL_KEY 272
# define LSFT_KEY 65505
# define LCTRL_KEY 256
# define LOPT_KEY 261
# define LCMD_KEY 259
# define LDEL_KEY 51
# define RTN_KEY 36
# define RSFT_KEY 258
# define RCTRL_KEY 269
# define ROPT_KEY 262
# define RCMD_KEY 260
# define EJ_KEY
# define FN_KEY 279
# define RDEL_KEY 117
# define HOME_KEY 115
# define END_KEY 119
# define PUP_KEY 116
# define PDOWN_KEY 121
# define CLR_KEY 71

/*
** Numeric keyboard keys, preceded by NK
** NKEQ_KEY is the equal (=) key
** NKSL_KEY is the slash (/) key
** NKWC_KEY is the wildcard (*) key
** NKMN_KEY is the minus (-) key
** NKPL_KEY is the plus (+) key
** NKPT_KEY is the point (.) key
** NKNTR_KEY is the enter key
*/

# define NK1_KEY 83
# define NK2_KEY 84
# define NK3_KEY 85
# define NK4_KEY 86
# define NK5_KEY 87
# define NK6_KEY 88
# define NK7_KEY 89
# define NK8_KEY 91
# define NK9_KEY 92
# define NK0_KEY 82
# define NKEQ_KEY 81
# define NKSL_KEY 75
# define NKWC_KEY 67
# define NKMN_KEY 78
# define NKPL_KEY 69
# define NKPT_KEY 65
# define NKNTR_KEY 76

#endif