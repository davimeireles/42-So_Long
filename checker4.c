/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:22 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/15 16:32:22 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_path(t_map *input)
{
	int	i;
	int	j;
	int	start[2];

	i = 0;
	find_start(input->map, start);
	flood_fill(input->map, start[0], start[1]);
	while (input->map[i])
	{
		j = 0;
		while (input->map[i][j] && input->map[i][j] != '\n')
		{
			if (input->map[i][j] != 'G' && input->map[i][j] != '1')
				p_error(PATH, input);
			j++;
		}
		i++;
	}
}

void	check_forbidden_entities(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'P'
					&& data->map[i][j] != 'C' && data->map[i][j] != 'E')
				p_error(PATH, data);
			j++;
		}
		i++;
	}
}

void	find_end(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'E')
			{
				data->e_loc[0] = j;
				data->e_loc[1] = i;
			}
			j++;
		}
		i++;
	}
}

void	find_player(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'P')
			{
				data->p_loc[0] = j;
				data->p_loc[1] = i;
			}
			j++;
		}
		i++;
	}
}

void	free_map(t_map *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
