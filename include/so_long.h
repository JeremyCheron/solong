/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:41:24 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/28 07:49:45 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define WIN_WITDH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 32
# define TITLE "so_long"
# define COL_NOT_REACHABLE "Collectible is not reachable"
# define EXIT_NOT_REACHABLE "Exit is not reachable"
# define INVALID_MAP "Invalid map"
# define INVALID_MAP_SIZE "Invalid map size"
# define INVALID_MAP_CONTENT "Invalid map content"
# define INVALID_MAP_RECT "Map is not rectangular"
# define INVALID_MAP_WALLS "Map is not surrounded by walls"
# define INVALID_MAP_PLAYER "Player is missing"
# define INVALID_MAP_COLLECTIBLE "Collectible is missing"
# define INVALID_MAP_EXIT "Exit is missing"
# define MEMORY_ALLOC "Memory allocation failed"
# define FAIL_LOAD_IMG "Failed to load image(s)"
# define INVALID_LINE "Invalid line input"
# define FAIL_OPEN_MAP "Failed to open map file"
# define EMPTY_MAP "Map file is empty"
# define INVALID_CHAR "Invalid character in map"
# define INVALID_MAP_ELEM "Invalid map elements"
# define USAGE "Usage: ./so_long <map_file.ber>"
# define NO_PLAYER "Player not found"
# define NL '\n'
# define EOL '\0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define FREESPACE '0'
# define WALL '1'
# define EXIT 'E'
# define PLAYER_ON_EXIT 'X'
# define VISITED 'V'
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363
# define ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_collectible;
	void	*img_freespace;
	void	*img_exit;
	void	*img_player;
	void	*img_player_on_exit;
	char	**map;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		to_collect;
	int		moves;
}	t_data;

typedef struct s_map_data
{
	int		width;
	int		height;
	char	**map;
}	t_map_data;

void	cleanup(t_data *data);
int		key_hook(int keycode, t_data *data);
void	fill_error_exit(char **map, char **copy, int height, char *msg);
void	error_exit(char *msg);
void	error_clean_exit(const char *msg);
char	**read_map(const char *filename, int *width, int *height);
int		close_window(t_data *data);
void	draw_map(t_data *data);
void	validate_map(t_data *data);
void	initialize_graphics(t_data *data);
void	free_map(char **map, int height);
void	init_player_position(t_data *data);
void	move_player(t_data *data, int dx, int dy);
void	cleanup_lines(char **map, int height);
void	validate_access(char **map, int width, int height);
void	gnl_map(int fd, char *line, t_map_data *map);
char	*trim_newline(char *line);
void	check_width(t_map_data *map_data, int current_width, char *line);
char	**realloc_map(char **map, int new_height);

#endif
