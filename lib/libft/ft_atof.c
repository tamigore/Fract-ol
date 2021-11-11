/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:37:29 by tamigore          #+#    #+#             */
/*   Updated: 2021/11/05 16:54:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_fract(char *str, double nb)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	i--;
	while (i >= 0 && str[i] >= '0' && str[i] <= '9' && str[i] != '.')
		nb = nb / 10 + str[i--] - '0';
	nb = nb / 10;
	return (nb);
}

static int	get_inter(char *str, double *res)
{
	int		i;
	int		neg;
	double	nb;

	i = 0;
	neg = 1;
	nb = 0;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	*res = nb * neg;
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	double	nb;
	double	inter;

	i = 0;
	nb = 0;
	inter = 0;
	i = get_inter(str, &inter);
	if (str[i] == '.')
	{
		i++;
		nb = get_fract(&str[i], nb);
	}
	if (inter > 0)
		nb += (double)inter;
	else
		nb -= (double)inter;
	if (str[0] == '-' && nb > 0)
		nb *= -1;
	return (nb);
}
