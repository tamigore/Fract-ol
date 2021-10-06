#include "fractol.h"

void		zoom(t_env *env, double z, int *valid)
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
	env->view.offx -= ((env->res.x / 2) / env->res.x) * (nw - w);
	env->view.offy -= ((env->res.y / 2) / env->res.y) * (nh - h);
	if (valid)
		*valid = 1;
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
	render(env);
}

int			key(int keycode, t_env *env)
{
	int		valid;

	valid = 0;
	if (keycode == K_ESC)
		free_all(env, 1);
	if (keycode == K_NUM_0)
	{
		reset_view(env);
		valid = 1;
	}
	if (keycode == K_NUM_MULT)
	{
		env->view.max *= 2;
		valid = 1;
	}
	if (keycode == K_NUM_DIV)
		if (env->view.max / 2 >= 2)
		{
			env->view.max /= 2;
			valid = 1;
		}
	if (keycode == K_NUM_PLUS)
		zoom(env, 1 / 1.1, &valid);
	if (keycode == K_NUM_MINUS)
		zoom(env, 1.1, &valid);
	move(keycode, env);
	if (valid)
		render(env);
	return (0);
}

int			expose(t_env *env)
{
	t_img	*img;

	img = init_img(env);
	append_image(&(env->img), img);
	env->img = env->img->next;
	render(env);
	return (0);
}

void		graphic_loop(t_env *env)
{
	mlx_key_hook(env->win, key, env);
	mlx_expose_hook(env->mlx, expose, env);
	mlx_hook(env->win, 4, 1L << 2, mouse_up, 0);
	mlx_hook(env->win, 5, 1L << 3, mouse_down, env);
	mlx_hook(env->win, 6, 1L << 6, mouse_move, env);
	mlx_loop(env->mlx);
}