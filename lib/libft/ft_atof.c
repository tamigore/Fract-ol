#include "libft.h"

double	ft_atof(char *str)
{
	int				i;
	double			nb;
	long long int	fract;
	long long int	inter;

	i = 0;
	nb = 0;
	while ((str[i] <= '\r' && str[i] >= '\t') || str[i] == ' ')
		i++;
	inter = ft_superatoi(&str[i]);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		fract = ft_superatoi(&str[i]);
		nb = (double)fract;
		while (nb >= 1)
			nb /= 10;
	}
	nb += (double)inter;
	return (nb);
}
