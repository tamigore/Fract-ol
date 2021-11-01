#include "fractol.h"

static void	init_res(char *set, t_env *env)
{
	int         i;

	i = 0;
	if (set == NULL)
	{
		env->res.check = 1;
		env->res.x = RES_DEF + RES_DEF / 2;
		env->res.y = RES_DEF;
		return ;
	}
	while (set[i] &&set[i] != 'r')
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
		env->res.x = RES_DEF;
	if (env->res.y < RES_MIN)
		env->res.y = RES_DEF;
	env->res.check = 1;
}

static void	set(t_env *env, char *opt, int i)
{
	if (opt[i] == 'M')
		env->set.M = 1;
	else if (opt[i] == 'J')
	{
		env->set.J = 1;
		i++;
		ft_putstr("in\n");
		if (opt[i + 1] >= '0' && opt[i + 1] <= '9')
		{
			ft_putstr("in atof\n");
			env->set.c.r = ft_atof(&opt[i]);
			while(opt[i] && opt[i] >= '0' && opt[i] <= '9')
				i++;
			if (opt[i] == ':')
			{
				i++;
				env->set.c.i = ft_atof(&opt[i]);
			}
		}
		else
		{
			env->set.c.r = 0;
			env->set.c.i = 0;
		}
	}
}

static void	init_set(char *opt, t_env *env)
{
	int			i;

	i = 0;
	if (opt == NULL || opt[i] != '-')
	{
		env->set.M = 1;
		env->set.J = 0;
		env->set.c.r = 0;
		env->set.c.r = 0;
		env->set.radius = 0;
		return ;
	}
	env->set.M = 0;
	env->set.J = 0;
	if (opt[i] == '-')
		set(env, opt, ++i);
	if (env->set.J)
		env->set.radius = 2;
	printf("c.r = %f || c.i = %f\n", env->set.c.r, env->set.c.i);
	if (env->set.M > 0 && env->set.J > 0)
		env->set.J = 0;
}

static	void	init_mouse_view(t_env *env)
{
	if (env->set.M)
	{
		env->view.xmin = -2;
		env->view.xmax = 2;
		env->view.ymin = -1;
		env->view.ymax = 1;
		env->view.offx = -0.5;
	}
	else
	{
		env->view.xmin = -2;
		env->view.xmax = 2;
		env->view.ymin = -1;
		env->view.ymax = 1;
		env->view.offx = 0;
	}
	env->mouse.x = 0;
	env->mouse.y = 0;
	env->mouse.lastx = 0;
	env->mouse.lasty = 0;
	env->view.zoom = 1;
	env->view.offy = 0;
	env->view.max = MAX_ITER;
}

t_env           *init(int ac, char **av)
{
	t_env		*env;
	int			x;
	int			y;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		free_all(env, 0);
	if (ac == 1)
	{
		init_res(NULL, env);
		init_set(NULL, env);
	}
	else
	{
		init_set(av[1], env);
		init_res(av[1], env);
	}
	env->mlx = mlx_init();
	if (!env->mlx)
		free_all(env, 0);
	mlx_get_screen_size(env->mlx, &x, &y);
	if (env->res.x > x)
		env->res.x = x;
	if (env->res.y > y)
		env->res.y = y;
	env->win = mlx_new_window(env->mlx, env->res.x, env->res.y, "fractol");
	if (!env->win)
		free_all(env, 0);
	env->img = init_img(env);
	init_mouse_view(env);
	print(1, env);
	return (env);
}