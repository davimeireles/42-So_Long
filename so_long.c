/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:06:50 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/13 17:10:32 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map_and_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->input.map[i])
	{
		ft_printf("%s", data->input.map[i]);
		free(data->input.map[i]);
		i++;
	}
	free(data->input.map);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		validate_file(argv[1]);
		validate_map(argv[1]);
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		data->input.map = fill_input(argv[1], &data->input.lines, 0);
		print_map_and_free(data);
		open_window(data);
	}
	else if (argc < 2)
		write(1, "Too few arguments.\n", 19);
	else
		write(1, "Too much arguments.\n", 20);
}
