#include "fractol.h"

void		init_view(t_env * env)
{
	env->view.xmax = 1;
	env->view.xmin = -2;
	env->view.ymax = 1;
	env->view.ymin = -1;
	env->view.offx = 0;
	env->view.offy = 0;
	view_scale(env);
	env->view.max = 32;
	env->view.zoom = 1.0f;
}

void		reset_view(t_env *env)
{
	env->view.offx = 0;
	env->view.offy = 0;
	view_scale(env);
	env->view.max = 32;
	env->view.zoom = 1.0f;
}

void		view_scale(t_env *env)
{
	double w;
	double h;

	w = env->view.xmax - env->view.xmin;
	h = env->view.ymax - env->view.ymin;
	if (w / h >= (float)(env->res.x / env->res.y))
	{
		env->view.ymin = -(w * (env->res.x / env->res.y) / 2);
		env->view.ymax = w * (env->res.x / env->res.y) / 2;
	}
	else
	{
		env->view.xmin = -(h * (env->res.x / env->res.y) / 2);
		env->view.xmax = (h * (env->res.x / env->res.y) / 2);
	}
}