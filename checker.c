/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:25:34 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/15 16:33:16 by dmeirele         ###   ########.fr       */
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
		p_error(NO_FILE, NULL);
	if (!check_file(path))
		p_error(INPUT, NULL);
}

void	validate_map(char *path)
{
	t_map	*input;

	input = malloc(sizeof(t_map));
	if (!input)
		return ;
	init_values(input);
	input->map = fill_input(path, &input->lines, 0);
	if (input->lines == 0)
		p_error(PATH, input);
	input->columns = count_columns(input->map[0]);
	if (input->lines == input->columns || (!check_line_size(input->map)))
		p_error(RECTANGLE, input);
	if (!check_walls(input))
		p_error(WALL, input);
	if (!check_entities(input, 0, 0))
		p_error(ENTITIES, input);
	check_forbidden_entities(input);
	check_map_path(input);
	free_map(input);
	free(input);
}

void	p_error(t_error error, t_map *data)
{
	free_map(data);
	free(data);
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
