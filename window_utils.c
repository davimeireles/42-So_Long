#include "so_long.h"

void	free_memory(t_map *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->mlx_ptr);
	free(data);
}

int	close_window(t_map *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_memory(data);
	exit(1);
	return 0;
}

int	handle_key_press(int keysym, t_map *data)
{
	if (keysym == ESC)
		close_window(data);
	if (keysym == U_ARROW || keysym == W_KEY)
		return 1;
	if (keysym == D_ARROW || keysym == S_KEY)
		return 1;
	if (keysym == R_ARROW || keysym == D_KEY)
		return 1;
	if (keysym == L_ARROW || keysym == A_KEY)
		return 1;
	return 0;
}

void	window_utilities(t_map	*data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr,W_SIZE,H_SIZE, "Game Window");
	mlx_hook(data->win_ptr, 2, (1L << 0), handle_key_press, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	test_image(data);
	mlx_loop(data->mlx_ptr);
}
