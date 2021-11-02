#include "libft.h"

double	ft_atof(char *str)
{
	int				i;
	double			nb;
	long long int	fract;
	long long int	inter;

	i = 0;
	nb = 0;
	fract = 0;
	while ((str[i] <= '\r' && str[i] >= '\t') || str[i] == ' ')
		i++;
	inter = ft_superatoi(&str[i]);
	while (str[i] && str[i] != '.')
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
	if (ft_strchr(str, '-') && nb > 0)
		nb *= -1;
	return (nb);
}
