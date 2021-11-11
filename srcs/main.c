/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:59:28 by tamigore          #+#    #+#             */
/*   Updated: 2021/11/11 14:15:53 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	init(char **av)
{
	t_env	env;
	int		x;
	int		y;

	init_set(av[1], &env);
	init_res(av[1], &env);
	env.mlx = mlx_init();
	if (!env.mlx)
		free_all(&env, EXIT_FAILURE);
	x = MAX_RES_X;
	y = MAX_RES_Y;
	if (env.res.x > x)
		env.res.x = x;
	if (env.res.y > y)
		env.res.y = y;
	env.win = mlx_new_window(env.mlx, env.res.x, env.res.y, "fractol");
	if (!env.win)
		free_all(&env, EXIT_FAILURE);
	env.img = init_img(&env);
	init_mouse_view(&env);
	return (env);
}

int	free_all(t_env *env, int x)
{
	if (!env)
		exit(EXIT_FAILURE);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->img)
		delete_images(env->img, env->mlx);
	exit(x);
}

void	print(t_env *env)
{
	ft_putstr("Usage :./fract-ol -M:Mandelbrot set || -B:Burning Ship ||");
	ft_putstr("-J:Julia set(\"J1.02:0.5\")\n");
	ft_putstr("You can add r:resolution(\"r500.800\")\n");
	free_all(env, EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2 || !av[1])
		print(NULL);
	env = init(av);
	render(&env);
	graphic_loop(&env);
	free_all(&env, EXIT_SUCCESS);
	return (0);
}
