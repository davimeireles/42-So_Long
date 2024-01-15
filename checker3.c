/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:49:14 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/15 01:11:26 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_walls(t_map *input)
{
	int	i;

	if (!check_first_last(input->map[0]))
		return (false);
	if (!check_first_last(input->map[input->lines - 1]))
		return (false);
	i = 0;
	while (input->map[i])
	{
		if (input->map[i][0] != '1' || input->map[i][input->columns - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_first_last(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_entities(t_map *input, int i, int j)
{
	input->player = 0;
	input->exit = 0;
	input->coins = 0;
	while (input->map[i])
	{
		j = 0;
		while (input->map[i][j] && input->map[i][j] != '\n')
		{
			if (input->map[i][j] == 'P')
			{
				input->player++;
				input->p_loc[0] = j;
				input->p_loc[1] = i;
			}
			if (input->map[i][j] == 'E')
				input->exit++;
			if (input->map[i][j] == 'C')
				input->coins++;
			j++;
		}
		i++;
	}
	if (input->player != 1 || input->coins < 1 || input->exit != 1)
		return (false);
	return (true);
}

void	find_start(char **map, int *start)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
			{
				start[0] = i;
				start[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	flood_fill(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'G')
		return ;
	map[i][j] = 'G';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
}
