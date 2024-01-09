
#include "so_long.h"

bool	check_walls(t_map input)
{
	int i;

	if (!check_first_last(input.map[0]))
		return (false);
	if (!check_first_last(input.map[input.lines - 1]))
		return (false);
	i = 0;
	while (input.map[i])
	{
		if (input.map[i][0] != '1' || input.map[i][input.columns - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_first_last(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_entities(t_map input)
{
	int i;
	int j;

	i = 0;
	input.player = 0;
	input.exit = 0;
	input.coins = 0;
	while (input.map[i])
	{
		j = 0;
		while (input.map[i][j] && input.map[i][j] != '\n')
		{
			if (input.map[i][j] == 'P')
				input.player++;
			if (input.map[i][j] == 'E')
				input.exit++;
			if (input.map[i][j] == 'C')
				input.coins++;
			j++;
		}
		i++;
	}
	if (input.player != 1 || input.coins < 1 || input.exit != 1)
		return (false);
	return (true);
}