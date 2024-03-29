/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:06:50 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/15 14:50:01 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*data;

	if (argc == 2)
	{
		validate_file(argv[1]);
		validate_map(argv[1]);
		data = malloc(sizeof(t_map));
		if (!data)
			return (0);
		init_values(data);
		data->map = fill_input(argv[1], &data->lines, 0);
		data->columns = count_columns(data->map[0]);
		window_utilities(data);
	}
	else if (argc < 2)
		write(1, "Too few arguments.\n", 19);
	else
		write(1, "Too much arguments.\n", 20);
}
