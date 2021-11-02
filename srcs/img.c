#include "fractol.h"

t_img		*init_img(t_env *env)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		free_all(env);
	img->size_x = env->res.x;
	img->size_y = env->res.y;
	img->bpp = 32;
	img->size_line = (img->bpp / 8) * img->size_x;
	img->endian = 0;
	img->ptr = mlx_new_image(env->mlx, img->size_x, img->size_y);
	img->pixels = mlx_get_data_addr(img->ptr, &(img->bpp),
				&(img->size_line), &(img->endian));
	return (img);
}

void		delete_images(t_img *img, void *mlx_ptr)
{
	if (!img)
		return ;
	if (img)
	{
		mlx_destroy_image(mlx_ptr, img);
		free(img);
	}
}