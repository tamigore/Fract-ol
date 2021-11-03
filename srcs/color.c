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

static t_v3	color_p(int i, t_v3 color)
{
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

t_v3	palette(int x)
{
	t_v3	color;
	int		i;

	color = v_init(0, 0, 0);
	if (x < MAX_ITER && x > 0)
	{
		i = x % 16;
		if (i == 0)
			color = v_init(66, 30, 15);
		if (i == 1)
			color = v_init(25, 7, 26);
		if (i == 2)
			color = v_init(9, 1, 47);
		if (i == 3)
			color = v_init(4, 4, 73);
		if (i == 4)
			color = v_init(0, 7, 100);
		if (i == 5)
			color = v_init(12, 44, 138);
		color = color_p(i, color);
	}
	return (color);
}
