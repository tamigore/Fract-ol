#include "libmath.h"

t_cmplx		c_new(double x, double y)
{
	t_cmplx	z;

	z.r = x;
	z.i = y;
	return (z);
}

t_cmplx		c_add(t_cmplx z, t_cmplx c)
{
	t_cmplx	add;

	add.r = z.r + c.r;
	add.i = z.i + c.i;
	return (add);
}

t_cmplx		c_dif(t_cmplx z, t_cmplx c)
{
	t_cmplx	dif;

	dif.r = z.r - c.r;
	dif.i = z.i - c.i;
	return (dif);
}

t_cmplx		c_multi(t_cmplx x, t_cmplx y)
{
	t_cmplx	c;

	c.r = (x.r * y.r) - (x.i * y.i);
	c.i = (x.i * y.r) + (x.r * y.i);
	return (c);
}

double		c_abs(t_cmplx z)
{
	double	nb;

	nb = sqrt((z.r * z.r) + (z.i * z.i));
	return (nb);
}