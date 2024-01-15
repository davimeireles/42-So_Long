# include "so_long.h"

void	open_end(t_map *data)
{
	int	end_x;
	int end_y;

	end_x = data->e_loc[0] * 16;
	end_y = data->e_loc[1] * 16;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[3], end_x, end_y);
}

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
	while (i < data->lines)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0], j * 16, i * 16);
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1], j * 16, i * 16);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[2], j * 16, i * 16);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[4], j * 16, i * 16);
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[4], j * 16, i * 16);
			j++;
		}
		i++;
	}
}

void	refresh(t_map *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return ;
	data->moves++;
	ft_printf("Moves: %d\n", data->moves);
	if (data->map[y][x] == 'C')
	{
		data->map[y][x] = '0';
		data->coins--;
	}
	if (data->map[y][x] == 'E')
	{
		if (data->coins == 0)
		{
			ft_printf("Finish!");
			close_window(data);
		}
	}
	render_old(data);
	data->p_loc[0] = x;
	data->p_loc[1] = y;
	render_new(data);
	if (data->coins == 0)
		open_end(data);
}
