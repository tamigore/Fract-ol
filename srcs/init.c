/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:59:18 by tamigore          #+#    #+#             */
/*   Updated: 2021/11/05 16:51:24 by user42           ###   ########.fr       */
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
		env->set.m = 1;
	else if (opt[i] == 'J')
	{
		env->set.j = 1;
		i++;
		if (ft_isdigit(opt[i]) || opt[i] == '-')
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
		env->set.b = 1;
}

void	init_set(char *opt, t_env *env)
{
	int	i;

	i = 0;
	env->set.m = 0;
	env->set.j = 0;
	env->set.b = 0;
	env->set.c.r = 0;
	env->set.c.r = 0;
	if (opt[i] == '-')
		set(env, opt, ++i);
	if (!env->set.m && !env->set.j && !env->set.b)
		print(env);
}

void	init_view_set(t_env *env)
{
	if (env->set.m)
	{
		env->view.xmin = -2;
		env->view.xmax = 2;
		env->view.ymin = -1;
		env->view.ymax = 1;
		env->view.offx = -0.25;
	}
	else if (env->set.j)
	{
		env->view.xmin = -1.5;
		env->view.xmax = 1.5;
		env->view.ymin = -1;
		env->view.ymax = 1;
		env->view.offx = 0.25;
	}
	else if (env->set.b)
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
	env->p = 1;
	init_view_set(env);
}
