#include "so_long.h"

void	open_window(t_data	*data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr,800,600, "Game Window");
	mlx_loop_hook(data->win_ptr,NULL,data->win_ptr);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr,data->win_ptr);
}
