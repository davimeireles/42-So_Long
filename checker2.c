/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:30:44 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/09 19:33:27 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *path)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	lines = 0;
	while ((line = get_next_line(fd)))
	{
		lines++;
		free(line);
	}
	close(fd);
	return (lines);
}

int	count_columns(char *line)
{
	int	columns;

	columns = 0;
	while (line[columns] && line[columns] != '\n')
		columns++;
	return (columns);
}

size_t	ft_strlen_nl(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	validate_map(char *path)
{
	t_map	input;

	input.map = fill_input(path, &input.lines);
	input.columns = count_columns(input.map[0]);
	if (input.lines == input.columns || (!check_line_size(input.map)))
		p_error(RECTANGLE);
	if (!check_walls(input))
		p_error(WALL);
	if (!check_entities(input))
		p_error(ENTITIES);
}

char	**fill_input(char *path, int *t_lines)
{
	int		fd;
	int		i;
	char	**lines;
	char	*str;
	
	i = 0;
	*t_lines = count_lines(path);
	lines = ft_calloc((*t_lines + 1), sizeof(char *));
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(lines);
		return (NULL);
	}
	while ((str = get_next_line(fd)))
		lines[i++] = str;
	lines[i] = NULL;
	close(fd);
	return (lines);
}

