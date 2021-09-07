#include "fract-ol.h"

static void		put_pixel_to_img(t_env *env, t_v3 color, int x, int y)
{
	int			i;

	i = (x * PIXEL_LEN + env->img->size_line * y);
	env->img->pixels[i + TRANS] = (unsigned int)0;
	env->img->pixels[i + RED] = (unsigned int)color.x;
	env->img->pixels[i + GREEN] = (unsigned int)color.y;
	env->img->pixels[i + BLUE] = (unsigned int)color.z;
}

static t_v3		rescale_vec(t_v3 vec, int min, int max)
{
	if (vec.x > max)
		vec.x = max;
	if (vec.y > max)
		vec.y = max;
	if (vec.z > max)
		vec.z = max;
	if (vec.x < min)
		vec.x = min;
	if (vec.y < min)
		vec.y = min;
	if (vec.z < min)
		vec.z = min;
	return (vec);
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
/*
static double	get_offset(t_env *env, char opt)
{
	double		offset;
	double		scale_diff;

	offset = 0;
	if (env->img->prev)
	{
		scale_diff = 
		if (opt == 'x')
		{
			env->img->ori_x 
		}
		else if (opt == 'y')
		{

		}
	}
	return (offset);
}
*/
void			M_set(t_env *env)
{
	int			px;
	int			py;
	double		x;
	double		y;
	double		x0;
	double		y0;
	double		i;
	double		tmp;
	t_v3		color;

	py = 0;
	while (py < env->res.y)
	{
		px = 0;
		while (px < env->res.x)
		{
			x0 = ((3.5 * ((px + 0.5) / env->res.x)) - 2.5/*get_offset(env)*/) * (env->res.x / env->res.y) * env->img->scale;//(scaled to lie in the Mandelbrot X scale (-2.5, 1))
   			y0 = ((2 * ((py + 0.5) / env->res.y)) - 1/*get_offset(env)*/) * env->img->scale;//(scaled to lie in the Mandelbrot Y scale (-1, 1))
			x = 0.0;
    		y = 0.0;
			i = 0;
			while ((x * x) + (y * y) <= 4 && i < MAX_ITER)
        	{
				tmp = (x * x) - (y * y) + x0;
    			y = (2 * x * y) + y0;
        		x = tmp;
        		i++;
			}
    		color = palette(i);
			put_pixel_to_img(env, rescale_vec(color, 0, MAX_RGB), px, py);
			px++;
		}
		py++;
	}
}