#include "fractol.h"

void        free_all(t_env *env, int opt)
{
    if (env)
    {
        if (env->img)
            free(env->img);
		free(env);
    }
    if (!opt)
        exit(EXIT_FAILURE);
    else
        exit(EXIT_SUCCESS);
}

void        print(int opt, t_env *env)
{
    if (opt == 0)
        printf("Usage :./fract-ol -(options: M(Mandelbrot set), J(Julia set :\"J6\"), r(resolution :\"r500.800\")\n");
    else if (opt == 1)
    {
        printf("Parameters:\n");
        if (env->set.M > 0)
			printf("Mandelbrot set\n");
		else if (env->set.J > 0)
			printf("Julia set: z0 = %d\n", env->set.J);
        printf("Resolution: %d.x | %d.y\n", env->res.x, env->res.y);
    }
}

int         main(int ac, char **av)
{
    t_env   *env;

	env = NULL;
    if (ac < 1 || ac > 2)
    {
        print(0, NULL);
        exit(EXIT_FAILURE);
    }
    env = init(ac, av);
	render(env);
	graphic_loop(env);
    free_all(env, 1);
    return (0);
}