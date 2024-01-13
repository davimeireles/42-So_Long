# include "so_long.h"

void	test_image(t_map *data)
{
	t_img *img;

	img = malloc(sizeof(t_img));
	if (!img)
		return ;
	img->width = 800;
	img->height = 600;
	img->img = mlx_xpm_file_to_image(data->mlx_ptr, "background.xpm",&img->width,&img->height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img,0,0);
}

/*
void	image_to_window(t_map *data, t_utils *utils)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr,data->win_ptr,);
		}
	}
}*/
