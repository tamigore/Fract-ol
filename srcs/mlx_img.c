#include "fract-ol.h"

t_img		*init_img(t_env *env)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		free_all(env, 0);
	img->size_x = env->res.x;
	img->size_y = env->res.y;
	img->bpp = 32;
	img->size_line = (img->bpp / 8) * img->size_x;
	img->endian = 0;
	img->ptr = mlx_new_image(env->mlx, img->size_x, img->size_y);
	img->pixels = mlx_get_data_addr(img->ptr, &(img->bpp),
				&(img->size_line), &(img->endian));
	img->ori_x = 0;
	img->ori_y = 0;
	img->scale = 1;
	img->prev = NULL;
	img->next = NULL;
	return (img);
}

void		append_image(t_img **imgs, t_img *new)
{
	t_img	*tmp;

	if (!imgs || !new)
		return ;
	if (*imgs)
	{
		tmp = *imgs;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	else
		*imgs = new;
}

void		delete_images(t_img **imgs, void *mlx_ptr)
{
	t_img	*cursor;
	t_img	*head;

	if (!imgs)
		return ;
	if (*imgs)
	{
		head = *imgs;
		while (*imgs)
		{
			cursor = *imgs;
			*imgs = (*imgs)->next;
			mlx_destroy_image(mlx_ptr, cursor);
			free(cursor);
			if (*imgs == head)
				*imgs = NULL;
		}
	}
}