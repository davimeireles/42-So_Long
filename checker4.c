
#include "so_long.h"

void	check_map_path(t_map input)
{
	int 	i;
	int		j;
	int		start[2];

	i = 0;
	find_start(input.map, start);
	flood_fill(input.map,start[0],start[1]);
	while (input.map[i])
	{
		j = 0;
		while (input.map[i][j] && input.map[i][j] != '\n')
		{
			if (input.map[i][j] != 'G' && input.map[i][j] != '1')
				p_error(PATH);
			j++;
		}
		i++;
	}
}