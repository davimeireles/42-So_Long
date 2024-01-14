# include "so_long.h"

void	load_images(t_map *data)
{
	int s;

	s = 16;
	data->img = malloc(sizeof(void *) * ENTITIE);
	data->img[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/w.xpm", &s, &s);
	data->img[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/p.xpm", &s, &s);
	data->img[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/c.xpm", &s, &s);
	data->img[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/e.xpm", &s, &s);
	data->img[4] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/g.xpm", &s, &s);
}

void	render(t_map *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0], j * 16, i * 16);
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1], j * 16, i * 16);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[2], j * 16, i * 16);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[3], j * 16, i * 16);
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[4], j * 16, i * 16);
			j++;
		}
		i++;
	}
}