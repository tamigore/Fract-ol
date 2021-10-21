#include "fractol.h"

int		mouse_zoom(int button, int x, int y, t_env * env)
{
	env->mouse.lastx = env->mouse.x;
	env->mouse.lasty = env->mouse.y;
	env->mouse.x = x;
	env->mouse.y = y;
	if (button == 4)
	{
		zoom(env, 1 / ZOOM, 1);
		render(env);
	}
	else if (button == 5)
	{
		zoom(env, ZOOM, 1);
		render(env);
	}
	if (y < 0)
		return (0);
	return (0);
}