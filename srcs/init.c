/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:59:18 by tamigore          #+#    #+#             */
/*   Updated: 2021/11/03 16:59:20 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_res(char *set, t_env *env)
{
	int	i;

	i = 0;
	env->res.x = RES_DEF + RES_DEF / 2;
	env->res.y = RES_DEF;
	if (!set)
		return ;
	while (set[i] && set[i] != 'r')
		i++;
	if (set[i] == 'r')
	{
		i++;
		env->res.x = ft_atoi(&set[i]);
		while (set[i] && set[i] != '.')
			i++;
		i++;
		env->res.y = ft_atoi(&set[i]);
	}
	if (env->res.x < RES_MIN)
		env->res.x = RES_DEF + RES_DEF / 2;
	if (env->res.y < RES_MIN)
		env->res.y = RES_DEF;
}

void	set(t_env *env, char *opt, int i)
{
	if (opt[i] == 'M')
		env->set.M = 1;
	else if (opt[i] == 'J')
	{
		env->set.J = 1;
		i++;
		if (ft_isdigit(opt[i]))
		{
			env->set.c.r = ft_atof(&opt[i]);
			while (opt[i] && (opt[i] != ':'))
				i++;
			if (opt[i] == ':')
				env->set.c.i = ft_atof(&opt[++i]);
		}
		else
		{
			env->set.c.r = -0.8;
			env->set.c.i = 0.125;
		}
	}
	else if (opt[i] == 'B')
		env->set.B = 1;
}

void	init_set(char *opt, t_env *env)
{
	int	i;

	i = 0;
	env->set.M = 0;
	env->set.J = 0;
	env->set.B = 0;
	env->set.c.r = 0;
	env->set.c.r = 0;
	if (opt[i] == '-')
		set(env, opt, ++i);
	if (!env->set.M && env->set.J && env->set.B)
		print(env);
}

void	init_view_set(t_env *env)
{
	if (env->set.M)
	{
		env->view.xmin = -2;
		env->view.xmax = 2;
		env->view.ymin = -1;
		env->view.ymax = 1;
		env->view.offx = -0.25;
	}
	else if (env->set.J)
	{
		env->view.xmin = -2;
		env->view.xmax = 2;
		env->view.ymin = -1;
		env->view.ymax = 1;
		env->view.offx = 0.25;
	}
	else if (env->set.B)
	{
		env->view.xmin = -2;
		env->view.xmax = 2;
		env->view.ymin = -1;
		env->view.ymax = 1;
		env->view.offy = -0.5;
		env->view.offx = -0.1;
	}
}

void	init_mouse_view(t_env *env)
{
	env->mouse.x = 0;
	env->mouse.y = 0;
	env->view.zoom = 1;
	env->view.offy = 0;
	env->view.offx = 0;
	env->view.max = MAX_ITER;
	init_view_set(env);
}
