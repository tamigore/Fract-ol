/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:58:39 by tamigore          #+#    #+#             */
/*   Updated: 2021/11/03 16:58:42 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_v3	color_p1(int i, t_v3 color)
{
	if (i == 4)
		color = v_init(0, 7, 100);
	if (i == 5)
		color = v_init(12, 44, 138);
	if (i == 6)
		color = v_init(24, 82, 177);
	if (i == 7)
		color = v_init(57, 125, 209);
	if (i == 8)
		color = v_init(134, 181, 229);
	if (i == 9)
		color = v_init(211, 236, 248);
	if (i == 10)
		color = v_init(241, 233, 191);
	if (i == 11)
		color = v_init(248, 201, 95);
	if (i == 12)
		color = v_init(255, 170, 0);
	if (i == 13)
		color = v_init(204, 128, 0);
	if (i == 14)
		color = v_init(153, 87, 0);
	if (i == 15)
		color = v_init(106, 52, 3);
	return (color);
}

static t_v3	color_p(int i, t_v3 color)
{
	if (i == 0)
		color = v_init(66, 30, 15);
	if (i == 1)
		color = v_init(25, 7, 26);
	if (i == 2)
		color = v_init(9, 1, 47);
	if (i == 3)
		color = v_init(4, 4, 73);
	color = color_p1(i, color);
	return (color);
}

static t_v3	color_b1(int i, t_v3 color)
{
	if (i == 4)
		color = v_init(20, 50, 0);
	if (i == 5)
		color = v_init(40, 100, 13);
	if (i == 6)
		color = v_init(45, 111, 60);
	if (i == 7)
		color = v_init(233, 54, 135);
	if (i == 8)
		color = v_init(61, 254, 213);
	if (i == 9)
		color = v_init(201, 115, 222);
	if (i == 10)
		color = v_init(95, 202, 107);
	if (i == 11)
		color = v_init(235, 72, 127);
	if (i == 12)
		color = v_init(230, 219, 171);
	if (i == 13)
		color = v_init(249, 128, 141);
	if (i == 14)
		color = v_init(201, 69, 57);
	if (i == 15)
		color = v_init(135, 59, 100);
	return (color);
}

static t_v3	color_b(int i, t_v3 color)
{
	if (i == 0)
		color = v_init(104, 163, 255);
	if (i == 1)
		color = v_init(81, 182, 141);
	if (i == 2)
		color = v_init(217, 104, 34);
	if (i == 3)
		color = v_init(131, 140, 169);
	color = color_b1(i, color);
	return (color);
}

t_v3	palette(int i, int p, t_v3 color)
{
	color = v_init(0, 0, 0);
	if (i < MAX_ITER && i > 0)
	{
		i = i % 16;
		if (p == 1)
			color = color_p(i, color);
		else
			color = color_b(i, color);
	}
	return (color);
}
