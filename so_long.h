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
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>

#define ESC_KEY XK_Escape

typedef enum error
{
	RECTANGLE,
	WALL,
	ENTITIES,
	NO_FILE,
	INPUT,
	PATH
}			t_error;

typedef struct s_map
{
	char	**map;
	int		lines;
	int		columns;
	int		coins;
	int		player;
	int		exit;
}		t_map;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	input;
}		t_data;

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
char	**fill_input(char *path, int *t_lines, int i);
bool	check_line_size(char **input);

/* checker 3 */

bool	check_walls(t_map *input);
bool	check_first_last(char *str);
bool	check_entities(t_map *input);
void	find_start(char **map, int *start);
void	flood_fill(char **map, int i, int j);

/* checker 4 */
void	check_map_path(t_map *input);
void	check_forbidden_entities(char **map);

/* window utils */
void	window_utilities(t_data	*data);
void	close_window(void *input);
void	handle_key_press(XKeyEvent *event, t_data *data);

/* random functions */
void	free_memory(t_data *data);
#endif