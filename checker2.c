/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:30:44 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/11 13:22:04 by dmeirele         ###   ########.fr       */
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

bool	check_line_size(char **input)
{
	int		i;
	size_t	f_line;

	i = 1;
	f_line = ft_strlen_nl(input[0]);
	while (input[i])
	{
		if (ft_strlen_nl(input[i]) != f_line)
			return (false);
		i++;
	}
	return (true);
}

char	**fill_input(char *path, int *t_lines)
{
	int		fd;
	int		i;
	char	**lines;
	char	*str;
	
	i = 0;
	*t_lines = count_lines(path);
	lines = malloc((sizeof(char *) * (*t_lines + 1)));
	if (!lines)
		return (NULL);
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

