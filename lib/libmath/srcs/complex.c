#include "libmath.h"

t_cmplx		c_new(double x, double y)
{
	t_cmplx	z;

	z.real = x;
	z.imag = y;
	return (z);
}

t_cmplx		c_add(t_cmplx z, t_cmplx c)
{
	t_cmplx	add;

	add.real = z.real + c.real;
	add.imag = z.imag + c.imag;
	return (add);
}

t_cmplx		c_dif(t_cmplx z, t_cmplx c)
{
	t_cmplx	dif;

	dif.real = z.real - c.real;
	dif.imag = z.imag - c.imag;
	return (dif);
}

t_cmplx		c_multi(t_cmplx x, t_cmplx y)
{
	t_cmplx	c;

	c.real = (x.real * y.real) - (x.imag * y.imag);
	c.imag = (x.imag * y.real) + (x.real * y.imag);
	return (c);
}

double		c_abs(t_cmplx z)
{
	double	nb;

	nb = sqrt((z.real * z.real) + (z.imag * z.imag));
	return (nb);
}