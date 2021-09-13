#include "fractol.h"

void		zoom(t_env *env, int x, int y, double z)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (env->view.xmax - env->view.xmin) * (env->view.zoom);
	h = (env->view.ymax - env->view.ymin) * (env->view.zoom);
	nw = (env->view.xmax - env->view.xmin) * (env->view.zoom * z);
	nh = (env->view.ymax - env->view.ymin) * (env->view.zoom * z);
	env->view.zoom *= z;
	env->view.offx -= ((double)x / env->res.x) * (nw - w);
	env->view.offy -= ((double)y / env->res.y) * (nh - h);
}

void	move(int key, t_env *env)
{
	double w;
	double h;

	w = (env->view.xmax - env->view.xmin) * env->view.zoom;
	h = (env->view.ymax - env->view.ymin) * env->view.zoom;
	if (key == K_UP)
		env->view.offy -= h * 0.05f;
	if (key == K_DOWN)
		env->view.offy += h * 0.05f;
	if (key == K_LEFT)
		env->view.offx -= w * 0.05f;
	if (key == K_RIGHT)
		env->view.offx += w * 0.05f;
	if (key == K_L)
		env->mouse.lock = 1 - env->mouse.lock;
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

int			key(int keycode, t_env *env)
{
	if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == K_NUM_0)
		reset_view(env);
	if (keycode == K_NUM_MULT)
		env->view.max *= 2;
	if (keycode == K_NUM_DIV)
		if (env->view.max / 2 >= 2)
			env->view.max /= 2;
	if (keycode == K_NUM_PLUS)
		zoom(env, env->res.x / 2, env->res.y / 2, 1 / 1.1);
	if (keycode == K_NUM_MINUS)
		zoom(env, env->res.x / 2, env->res.y / 2, 1.1);
	return (0);
}

int			expose(t_env *env)
{
	render(env);
	return (0);
}

void		graphic_loop(t_env *env)
{
	env->win = mlx_new_window(env->mlx, env->res.x, env->res.y, "fract-ol");
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr, 0, 0);
	mlx_key_hook(env->win, key, env);
	mlx_expose_hook(env->mlx, expose, env);
	mlx_hook(env->win, 4, 1L << 2, mouse_up, 0);
	mlx_hook(env->win, 5, 1L << 3, mouse_down, env);
	mlx_hook(env->win, 6, 1L << 6, mouse_move, env);
	mlx_loop(env->mlx);
}