
#include "so_long.h"

void	render_old(t_map *data)
{
	int	old_x;
	int	old_y;
	char **map;

	old_x = data->p_loc[0];
	old_y = data->p_loc[1];
	map = data->map;
	if (map[old_y][old_x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[4], old_x * 16, old_y * 16);
	if (map[old_y][old_x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[3], old_x * 16, old_y * 16);
}

void	render_new(t_map *data)
{
	int	x;
	int	y;
	char **map;

	x = data->p_loc[0];
	y = data->p_loc[1];
	map = data->map;
	if (map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[3], x * 16, y * 16);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1], x * 16, y * 16);
}