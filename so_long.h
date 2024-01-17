/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:09:30 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/15 16:32:22 by dmeirele         ###   ########.fr       */
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

// Key Code
# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define R_ARROW 65363
# define L_ARROW 65361
# define U_ARROW 65362
# define D_ARROW 65364

// Window Size
# define ENTITIE 5

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
	void	*mlx_ptr;
	void	*win_ptr;
	void	**img;
	char	**map;
	int		p_loc[2];
	int		e_loc[2];
	int		moves;
	int		lines;
	int		columns;
	int		coins;
	int		player;
	int		exit;
}		t_map;

/* checker */
bool	check_path(char *path);
bool	check_file(char *path);
void	validate_file(char *path);
void	p_error(t_error error, t_map *data);
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
bool	check_entities(t_map *input, int i, int j);
void	find_start(char **map, int *start);
void	flood_fill(char **map, int i, int j);

/* checker 4 */
void	check_map_path(t_map *input);
void	check_forbidden_entities(t_map *data);
void	find_end(t_map *data);
void	find_player(t_map *data);
void	free_map(t_map *data);

/* window utils */
void	window_utilities(t_map	*data);
int		close_window(t_map *data);
int		handle_key_press(int keysym, t_map *data);
void	free_memory(t_map *data);

/* Draw Image */
void	load_images(t_map *data);
void	render(t_map *data, int i, int j);
void	open_end(t_map *data);
void	refresh(t_map *data, int i, int j);

/* Draw Image 2 */
void	render_old(t_map *data);
void	render_new(t_map *data);
void	init_values(t_map *data);

#endif