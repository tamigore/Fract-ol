/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:59:41 by tamigore          #+#    #+#             */
/*   Updated: 2021/11/03 16:59:43 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel_to_img(t_env *env, t_v3 color, int x, int y)
{
	int	i;

	i = (x * PIXEL_LEN + env->img->size_line * y);
	env->img->pixels[i + TRANS] = (unsigned int)0;
	env->img->pixels[i + RED] = (unsigned int)color.x;
	env->img->pixels[i + GREEN] = (unsigned int)color.y;
	env->img->pixels[i + BLUE] = (unsigned int)color.z;
}

double	pixel_point(t_env *env, int p, char opt)
{
	double	z;
	double	res;

	if (opt == 'y')
		res = ((2 * ((p + 0.5) / env->res.y)) - 1)
			* env->view.zoom + env->view.offy;
	else
		res = ((3.5 * ((p + 0.5) / env->res.x)) - 2)
			* env->view.zoom + env->view.offx;
	if ((env->res.x / env->res.y) < 1)
	{
		z = env->res.y / env->res.x;
		if (opt == 'y')
			return (z * res);
		else
			return (res);
	}
	else
	{
		z = env->res.x / env->res.y;
		if (opt == 'x')
			return (z * res);
		else
			return (res);
	}
}

static int	find_set(t_env *env, t_cmplx z0)
{
	int	i;

	i = 0;
	if (env->set.m)
		i = m_set(z0, env);
	else if (env->set.j)
		i = j_set(z0, env);
	else if (env->set.b)
		i = b_set(z0, env);
	else
		print(env);
	return (i);
}

void	render(t_env *env)
{
	int		px;
	int		py;
	double	i;
	t_cmplx	z0;
	t_v3	color;

	py = 0;
	while (py < env->res.y)
	{
		px = 0;
		z0.i = pixel_point(env, py, 'y');
		while (px < env->res.x)
		{
			z0.r = pixel_point(env, px, 'x');
			i = find_set(env, z0);
			color = palette(i, env->p, color);
			put_pixel_to_img(env, color, px, py);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr, 0, 0);
}
