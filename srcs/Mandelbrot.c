#include "fractol.h"

int			M_set(t_cmplx z0)
{
	t_cmplx		z;
	double		i;
	double		tmp;

	z.r = 0.0;
	z.i = 0.0;
	i = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && i < MAX_ITER)
	{
		tmp = (z.r * z.r) - (z.i * z.i) + z0.r;
		z.i = (2 * z.r * z.i) + z0.i;
		z.r = tmp;
		i++;
	}
	return (i);
}