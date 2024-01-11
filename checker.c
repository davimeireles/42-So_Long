/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:25:34 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/11 13:15:43 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_path(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (!(path[len - 1] == 'r' && path[len - 2] == 'e' 
		&& path[len - 3] == 'b' && path[len - 4] == '.'))
		return (false);
	return (true);
}

bool	check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

void	validate_file(char *path)
{
	if (!check_path(path))
		p_error(NO_FILE);
	if (!check_file(path))
		p_error(INPUT);
}

void	validate_map(char *path)
{
	t_map	*input;
	int i = 0;

	input = malloc(sizeof(t_map));
	if (!input)
		return ;
	input->map = fill_input(path, &input->lines);
	input->columns = count_columns(input->map[0]);
	if (input->lines == input->columns || (!check_line_size(input->map)))
		p_error(RECTANGLE);
	if (!check_walls(input))
		p_error(WALL);
	if (!check_entities(input))
		p_error(ENTITIES);
	check_forbidden_entities(input->map);
	check_map_path(input);
	while(input->map[i])
	{
		free(input->map[i]);
		i++;
	}
	free(input);
}

void	p_error(t_error error)
{
	if (error == RECTANGLE)
		ft_printf("Error\nMap is not Rectangular.\n");
	if (error == WALL)
		ft_printf("Error\nNot Enclosed.\n");
	if (error == ENTITIES)
		ft_printf("Error\nInvalid number of coins/starts/exits.\n");
	if (error == NO_FILE)
		ft_printf("Error\nFile cant be opened only .ber accepted.\n");
	if (error == INPUT)
		ft_printf("Error\nFile not found.\n");
	if (error == PATH)
		ft_printf("Error\nInvalid Path\n");
	exit(1);
}
