#include "so_long.h"

void	free_memory(t_data *data)
{
	int	i;

	i = 0;
	while (data->input.map[i])
	{
		free(data->input.map[i]);
		i++;
	}
	free(data->input.map);
	free(data->mlx_ptr);
	free(data);
}

void	close_window(void *input)
{
	t_data *data = (t_data *)input;

	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_memory(data);
	exit(1);
}

void handle_key_press(XKeyEvent *event, t_data *data)
{
	if (XLookupKeysym(event, 0) == ESC_KEY)
		close_window(data);
}

void	window_utilities(t_data	*data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr,800,600, "Game Window");
	mlx_hook(data->win_ptr, 17, 0, (int (*)())close_window, data);
	mlx_hook(data->win_ptr, 2, 0, (int (*)())&handle_key_press, data);
	mlx_loop(data->mlx_ptr);
}
