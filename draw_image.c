/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:57:35 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/15 23:48:45 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_end(t_map *data)
{
	int	end_x;
	int	end_y;

	end_x = data->e_loc[0] * 48;
	end_y = data->e_loc[1] * 48;
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img[3], end_x, end_y);
}

void	load_images(t_map *data)
{
	int	s;

	s = 48;
	data->img = malloc(sizeof(void *) * ENTITIE);
	data->img[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/wall48x.xpm",
			&s, &s);
	data->img[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/player48x.xpm",
			&s, &s);
	data->img[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/colec48x.xpm", 
			&s, &s);
	data->img[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit48x.xpm", 
			&s, &s);
	data->img[4] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/ground48x.xpm", 
			&s, &s);
}

void	render(t_map *data, int i, int j)
{
	while (++i < data->lines)
	{
		j = -1;
		while (++j < data->columns)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img[0], j * 48, i * 48);
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img[1], j * 48, i * 48);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img[2], j * 48, i * 48);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img[3], j * 48, i * 48);
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img[4], j * 48, i * 48);
		}
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
			ft_printf("Congrats, you win!!!\n");
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
