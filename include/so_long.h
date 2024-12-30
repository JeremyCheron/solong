/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:41:24 by jcheron           #+#    #+#             */
/*   Updated: 2024/12/30 17:28:11 by jcheron          ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_collectible;
	void	*img_freespace;
	void	*img_exit;
	void	*img_player;
	char	**map;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
}	t_data;

void	cleanup(t_data *data);
int		key_hook(int keycode, t_data *data);
void	error_exit(const char *msg);
void	error_clean_exit(const char *msg);
char	**read_map(const char *filename, int *width, int *height);
int		close_window(t_data *data);
void	draw_map(t_data *data);
void	validate_map(t_data *data);
void	initialize_graphics(t_data *data);
void	free_map(char **map, int height);

#endif
