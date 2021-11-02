#include "fractol.h"

static void		put_pixel_to_img(t_env *env, t_v3 color, int x, int y)
{
	int			i;

	i = (x * PIXEL_LEN + env->img->size_line * y);
	env->img->pixels[i + TRANS] = (unsigned int)0;
	env->img->pixels[i + RED] = (unsigned int)color.x;
	env->img->pixels[i + GREEN] = (unsigned int)color.y;
	env->img->pixels[i + BLUE] = (unsigned int)color.z;
}

static t_v3		palette(int	x)
{
	t_v3		color;
	int			i;

	color = v_init(0, 0, 0);
	if (x < MAX_ITER && x > 0)
	{
		i = x % 16;
		if (i == 0)
			color = v_init(66, 30, 15);
		if (i == 1)
			color = v_init(25, 7, 26);
		if (i == 2)
			color = v_init(9, 1, 47);
		if (i == 3)
			color = v_init(4, 4, 73);
		if (i == 4)
			color = v_init(0, 7, 100);
		if (i == 5)
			color = v_init(12, 44, 138);
		if (i == 6)
			color = v_init(24, 82, 177);
		if (i == 7)
			color = v_init(57, 125, 209);
		if (i == 8)
			color = v_init(134, 181, 229);
		if (i == 9)
			color = v_init(211, 236, 248);
		if (i == 10)
			color = v_init(241, 233, 191);
		if (i == 11)
			color = v_init(248, 201, 95);
		if (i == 12)	
			color = v_init(255, 170, 0);
		if (i == 13)
			color = v_init(204, 128, 0);
		if (i == 14)
   			color = v_init(153, 87, 0);
		if (i == 15)
			color = v_init(106, 52, 3);
		return (color);
	}
	return (color);
}

double		pixel_point(t_env *env, int p, char opt)
{
	double	z;
	double	res;


	if ((env->res.x / env->res.y) < 1)
		z = env->res.y / env->res.x;
	else
		z = env->res.x / env->res.y;
//	if (env->set.M)
//	{
		if (opt == 'y')
			res = ((2 * ((p + 0.5) / env->res.y)) - 1) * env->view.zoom + env->view.offy;
		else	
			res = ((3.5 * ((p + 0.5) / env->res.x)) - 2) * env->view.zoom + env->view.offx;
//	}
//	else
//	{
//		if (opt == 'y')
//			res = (2 * env->set.radius * ((p + 0.5) - env->res.y) / 2) * env->view.zoom + env->view.offy;
//		else
//			res = (3 * env->set.radius * ((p + 0.5) - env->res.x) / 2) * env->view.zoom + env->view.offx;
//	}
	if ((env->res.x / env->res.y) < 1)
	{
		z = env->res.y / env->res.x;
		if (opt == 'y')
			return (z * res);
		else
			return (res);
	}
	else
	{
		z = env->res.x / env->res.y;
		if (opt == 'x')
			return (z * res);
		else
			return (res);
	}
}

void 		render(t_env *env)
{
	int 	px;
	int 	py;
	double 	i;
	t_cmplx	z0;
	t_v3 	color;

	py = 0;
	while (py < env->res.y)
	{
		px = 0;
		z0.i = pixel_point(env, py, 'y');
		while (px < env->res.x)
		{
			z0.r = pixel_point(env, px, 'x');
			if (env->set.M)
				i = M_set(z0);
			else
				i = J_set(env, z0);
			color = palette(i);
			put_pixel_to_img(env, color, px, py);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr, 0, 0);
}
