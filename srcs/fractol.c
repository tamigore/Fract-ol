#include "fractol.h"

double			M_set(t_env *env, int px, int py)
{
	double		x;
	double		y;
	t_cmplx		z;
	double		i;
	double		tmp;

	z.r = (((double)px / env->res.x) * (env->view.xmax - env->view.xmin)) * env->view.zoom + env->view.xmin + env->view.offx;
   	z.i = (((double)py / env->res.y) * (env->view.ymax - env->view.ymin)) * env->view.zoom + env->view.ymin + env->view.offy;
	x = 0.0;
    y = 0.0;
	i = 0;
	while ((x * x) + (y * y) <= 4 && i < MAX_ITER)
    {
		tmp = (x * x) - (y * y) + z.r;
    	y = (2 * x * y) + z.i;
    	x = tmp;
   		i++;
	}
	return (i);
}