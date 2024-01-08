/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:25:34 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/08 23:36:20 by dmeirele         ###   ########.fr       */
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

void	validate_file(char *path)
{
	if (!check_path(path))
		p_error("Input");
	if (!check_file(path))
		p_error("File");
}
void	p_error(char *str)
{
	if (ft_strcmp(str, "Rectangle") == 0)
		ft_printf("The map is not Rectangular\n");
	if (ft_strcmp(str, "Wall") == 0)
		ft_printf("Not Enclosed\n");
	if (ft_strcmp(str, "Entities") == 0)
		ft_printf("Invalid number of coins/starts/exits\n");
	if (ft_strcmp(str, "End") == 0)
		ft_printf("No way to reach end\n");
	if (ft_strcmp(str, "File") == 0)
		ft_printf("File Couldn't be opened only .ber accepted\n");
	if (ft_strcmp(str, "Unknown") == 0)
		ft_printf("Forbidden entity in map\n");
	if (ft_strcmp(str, "Input") == 0)
		ft_printf("Wrong number of arguments\n");
	if (ft_strcmp(str, "Coins") == 0)
		ft_printf("No way to reach all coins\n");
	exit(1);
}
