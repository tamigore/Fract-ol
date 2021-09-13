#include "fractol.h"

int		mouse_down(int button, int x, int y, t_env * env)
{
	if (button == 4)
	{
		zoom(env, x, y, 1 / 1.1);
		render(env);
	}
	else if (button == 5)
	{
		zoom(env, x, y, 1.1);
		render(env);
	}
	if (y < 0)
		return (0);
	env->mouse.isdown |= 1 << button;
	return (0);
}

int		mouse_up(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	env->mouse.isdown &= ~(1 << button);
	return (0);
}

int		mouse_move(int x, int y, t_env *env)
{
	double w;
	double h;

	env->mouse.lastx = env->mouse.x;
	env->mouse.lasty = env->mouse.y;
	env->mouse.x = x;
	env->mouse.y = y;
	if (!env->mouse.lock)
	{
		env->mouse.x = (((double)x / env->res.x) * (env->view.xmax - env->view.xmin)) * env->view.zoom
			+ env->view.xmin + env->view.offx;
		env->mouse.y = (((double)y / env->res.y) * (env->view.ymax - env->view.ymin)) * env->view.zoom
			+ env->view.ymin + env->view.offy;
	}
	if (env->mouse.isdown & (1 << 1))
	{
		w = (env->view.xmax - env->view.xmin) * env->view.zoom;
		h = (env->view.ymax - env->view.ymin) * env->view.zoom;
		env->view.offx += (double)(env->mouse.lastx - env->mouse.x) / env->res.x * w;
		env->view.offy += (double)(env->mouse.lasty - env->mouse.y) / env->res.y * h;
	}
	if (env->mouse.isdown || (!env->mouse.lock))
		render(env);
	return (0);
}