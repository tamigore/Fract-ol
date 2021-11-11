/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:58:59 by tamigore          #+#    #+#             */
/*   Updated: 2021/11/03 16:59:01 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int button, int x, int y, t_env *env)
{
	env->mouse.x = x;
	env->mouse.y = y;
	if (button == 5)
	{
		zoom(env, 1 / ZOOM, 1);
		render(env);
	}
	else if (button == 4)
	{
		zoom(env, ZOOM, 2);
		render(env);
	}
	if (y < 0)
		return (0);
	return (0);
}

void	zoom(t_env *env, double z, int opt)
{
	double	w;
	double	h;

	env->view.zoom *= z;
	if (opt > 0)
	{
		env->view.offx = pixel_point(env, env->mouse.x, 'x');
		env->view.offy = pixel_point(env, env->mouse.y, 'y');
	}
	else
	{
		w = (env->view.xmax - env->view.xmin) * (env->view.zoom);
		h = (env->view.ymax - env->view.ymin) * (env->view.zoom);
		env->view.offx -= ((env->res.x / 2) / env->res.x)
			* ((env->view.xmax - env->view.xmin) * (env->view.zoom) - w);
		env->view.offy -= ((env->res.y / 2) / env->res.y)
			* ((env->view.ymax - env->view.ymin) * (env->view.zoom) - h);
	}
}

void	move(int key, t_env *env)
{
	double	w;
	double	h;

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

int	key(int keycode, t_env *env)
{
	if (keycode == ESC_KEY)
		free_all(env, EXIT_SUCCESS);
	if (keycode == MULTI_KEY)
		if (env->view.max < 1000)
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
	if (keycode == SP_KEY)
	{
		if (env->p == 1)
			env->p = 0;
		else
			env->p = 1;
	}
	render(env);
	return (0);
}

void	graphic_loop(t_env *env)
{
	mlx_key_hook(env->win, key, env);
	mlx_mouse_hook(env->win, mouse_zoom, env);
	mlx_hook(env->win, 0, DESTROYNOTIFY, free_all, env);
	mlx_loop(env->mlx);
}
