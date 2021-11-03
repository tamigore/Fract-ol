/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:58:50 by tamigore          #+#    #+#             */
/*   Updated: 2021/11/03 16:58:52 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	m_set(t_cmplx z0, t_env *env)
{
	t_cmplx		z;
	double		i;
	double		tmp;

	z.r = 0.0;
	z.i = 0.0;
	i = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && i < env->view.max)
	{
		tmp = (z.r * z.r) - (z.i * z.i) + z0.r;
		z.i = (2 * z.r * z.i) + z0.i;
		z.r = tmp;
		i++;
	}
	return (i);
}

int	j_set(t_cmplx z0, t_env *env)
{
	t_cmplx		z;
	double		i;
	double		tmp;

	z.r = z0.r;
	z.i = z0.i;
	i = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && i < env->view.max)
	{
		tmp = (z.r * z.r) - (z.i * z.i) + env->set.c.r;
		z.i = (2 * z.r * z.i) + env->set.c.i;
		z.r = tmp;
		i++;
	}
	return (i);
}

static double	ft_abs(double x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

int	b_set(t_cmplx z0, t_env *env)
{
	t_cmplx		z;
	double		i;
	double		tmp;

	z.r = 0;
	z.i = 0;
	i = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && i < env->view.max)
	{
		tmp = (z.r * z.r) - (z.i * z.i) + z0.r;
		z.i = (2 * ft_abs(z.r) * ft_abs(z.i)) + z0.i;
		z.r = tmp;
		i++;
	}
	return (i);
}
