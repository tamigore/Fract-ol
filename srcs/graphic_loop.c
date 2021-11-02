#include "fractol.h"

void		zoom(t_env *env, double z, int opt)
{
	double	w;
	double	h;
	double	nw;
	double	nh;

	w = (env->view.xmax - env->view.xmin) * (env->view.zoom);
	h = (env->view.ymax - env->view.ymin) * (env->view.zoom);
	env->view.zoom *= z;
	if (opt == 1)
	{
		env->view.offx += (3.5 * ((double)env->mouse.x / env->res.x) - 2) * env->view.zoom;
		env->view.offy += (2 * ((double)env->mouse.y / env->res.y) - 1) * env->view.zoom;
	}
	else if (opt == 2)
	{
		env->view.offx -= (3.5 * ((double)env->mouse.x / env->res.x) - 2) * env->view.zoom;
		env->view.offy -= (2 * ((double)env->mouse.y / env->res.y) - 1) * env->view.zoom;
	}
	else
	{
		nw = (env->view.xmax - env->view.xmin) * (env->view.zoom);
		nh = (env->view.ymax - env->view.ymin) * (env->view.zoom);
		env->view.offx -= ((env->res.x / 2) / env->res.x) * (nw - w);
		env->view.offy -= ((env->res.y / 2) / env->res.y) * (nh - h);
	}
}

void	move(int key, t_env *env)
{
	double w;
	double h;

	w = (env->view.xmax - env->view.xmin) * env->view.zoom;
	h = (env->view.ymax - env->view.ymin) * env->view.zoom;
	if (key == UP_KEY)
		env->view.offy -= h * 0.1;
	if (key == DOWN_KEY)
		env->view.offy += h * 0.1;
	if (key == LEFT_KEY)
		env->view.offx -= w * 0.1;
	if (key == RIGHT_KEY)
		env->view.offx += w * 0.1;
}

int			key(int keycode, t_env *env)
{
	if (keycode == ESC_KEY)
		free_all(env);
	if (keycode == MULTI_KEY)
		if (env->view.max < 10000)
			env->view.max *= 2;
	if (keycode == DIV_KEY)
		if (env->view.max / 2 >= 2)
			env->view.max /= 2;
	if (keycode == PLUS_KEY)
		zoom(env, 1 / ZOOM, 0);
	if (keycode == MOINS_KEY)
		zoom(env, ZOOM, 0);
	if (keycode == UP_KEY || keycode == DOWN_KEY || keycode == LEFT_KEY
		|| keycode == RIGHT_KEY)
		move(keycode, env);
	render(env);
	return (0);
}

void		graphic_loop(t_env *env)
{
	mlx_key_hook(env->win, key, env);
	mlx_mouse_hook(env->win, mouse_zoom, env);
	mlx_hook(env->win, 0, DestroyNotify, free_all, env);
	mlx_loop(env->mlx);
}