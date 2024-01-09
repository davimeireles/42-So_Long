/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:25:34 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/09 10:35:56 by dmeirele         ###   ########.fr       */
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
	{
		return (false);
		close(fd);
	}
	close(fd);
	return (true);
}
bool	check_line_size(char **input)
{
	int	i;
	int	f_line;

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
void	validate_file(char *path)
{
	if (!check_path(path))
		p_error(INPUT);
	if (!check_file(path))
		p_error(FILE);
}
void	p_error(t_error error)
{
	if (error == RECTANGLE)
		ft_printf("The map is not Rectangular\n");
	if (error == WALL)
		ft_printf("Not Enclosed\n");
	if (error == ENTITIES)
		ft_printf("Invalid number of coins/starts/exits\n");
	if (error == END)
		ft_printf("No way to reach end\n");
	if (error == FILE)
		ft_printf("File Couldn't be opened only .ber accepted\n");
	if (error == FORBIDDEN)
		ft_printf("Forbidden entity in map\n");
	if (error == INPUT)
		ft_printf("Wrong number of arguments\n");
	if (error == COINS)
		ft_printf("No way to reach all coins\n");
	exit(1);
}
