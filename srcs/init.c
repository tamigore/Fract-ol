#include "fractol.h"

static t_res	init_res(char *set, t_env *env)
{
    int         i;
	t_res		res;

    i = 0;
	if (set == NULL)
	{
		res.check = 1;
		res.x = RES_DEF + RES_DEF / 2;
		res.y = RES_DEF;
		return (res);
	}
    while (set[i])
    {
        if (set[i] == 'r')
        {
        	env->res.x = ft_atoi(&set[i]);
			env->res.y = ft_atoi(&set[i]);
        }
        i++;
    }
	if (env->res.x < RES_MIN)
		env->res.x = RES_DEF;
	if (env->res.y < RES_MIN)
		env->res.y = RES_DEF;
	res.check = 1;
	return (res);
}

static t_set	init_set(char *opt)
{
	int			i;
	t_set		set;

	i = 0;
	if (opt == NULL)
	{
		set.M = 1;
		set.J = 0;
		set.a = 0;
		return (set);
	}
	set.M = 0;
	set.J = 0;
	set.a = 0;
	while (opt[i])
	{
		if (opt[i] == 'M')
			set.M = 1;
		else if (opt[i] == 'J')
		{
			if (opt[i + 1] >= 0 && opt[i + 1] <= '9')
				set.J = ft_atoi(&opt[++i]);
			else
				set.J = 1;
		}
		i++;
	}
	if (set.M > 0 && set.J > 0)
		set.J = 0;
	return (set);
}

static void		init_mouse(t_env *env)
{
	env->mouse.isdown = 0;
	env->mouse.lastx = 0;
	env->mouse.lasty = 0;
	env->mouse.x = 0;
	env->mouse.y = 0;
	if (env->set.M)
		env->mouse.lock = 0;
	else if (env->set.J)
		env->mouse.lock = 1;
	else
		env->mouse.lock = 0;
}

void		reset_view(t_env *env)
{
	env->view.offx = 0;
	env->view.offy = 0;
	view_scale(env);
	env->view.max = 32;
	env->view.zoom = 1.0f;
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
		env->res = init_res(NULL, env);
		env->set = init_set(NULL);
	}
    else
	{
		env->set = init_set(av[1]);
		env->res = init_res(av[1], env);
	}
    env->mlx = mlx_init();
    env->win = NULL;
	mlx_get_screen_size(env->mlx, &x, &y);
	if (env->res.x > x)
		env->res.x = x;
	if (env->res.y > y)
		env->res.y = y;
    env->img = init_img(env);
	reset_view(env);
	init_mouse(env);
	print(1, env);
    return (env);
}