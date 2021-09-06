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
	long		max;
	int			tmp;

	max = 255 * 255 * 255;
	tmp = x * (max / MAX_ITER);
	return (v_init((tmp >> 16), (tmp >> 8), (tmp)));
}

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
			x0 = (1 - 2 * ((px + 0.5) / env->res.x));//(scaled to lie in the Mandelbrot X scale (-2.5, 1))
   			y0 = (1 - 2 * ((py + 0.5) / env->res.y));//(scaled to lie in the Mandelbrot Y scale (-1, 1))
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
			if (i < MAX_ITER)
				i = i + 1 - log(log(((x * x) + (y * y)) / 2) / log(2)) / log(2);
    		color = v_add(v_multi(-1 * (remainder(i, 1.)), palette(floor(i))), v_multi(remainder(i, 1.), palette(floor(i) + 1)));
			put_pixel_to_img(env, rescale_vec(color, 0, MAX_RGB), px, py);
			px++;
		}
		py++;
	}
}