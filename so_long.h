/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:09:30 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/13 16:58:09 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdio.h>

typedef enum	error
{
	RECTANGLE,
	WALL,
	ENTITIES,
	END,
	NO_FILE,
	FORBIDDEN,
	INPUT,
	COINS
}			t_error;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
}		t_data;

typedef struct s_map
{
	char **map;
	int	lines;
	int	columns;
	int	coins;
	int	player;
	int	exit;
}		t_map;

/* checker */

bool	check_path(char *path);
bool	check_file(char *path);
void	validate_file(char *path);
void	p_error(t_error error);
void	validate_map(char *path);

/* checker 2 */

size_t	ft_strlen_nl(char *line);
int		count_columns(char *line);
int		count_lines(char *path);
char	**fill_input(char *path, int *t_lines);
bool	check_line_size(char **input);

/* checker 3 */

bool	check_walls(t_map input);
bool	check_first_last(char *str);
bool	check_entities(t_map input);


#endif