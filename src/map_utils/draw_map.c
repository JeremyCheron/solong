/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:11:41 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 15:06:34 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Draw a tile on the window
 *
 * @param data The data structure
 * @param i The row of the tile
 * @param j The column of the tile
 *
 * @note Draw the tile at the position (i, j) on the window
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/28
 */
static void	draw_tile(t_data *data, int i, int j)
{
	void	*img;

	img = NULL;
	if (data->map[i][j] == WALL)
		img = data->img_wall;
	else if (data->map[i][j] == COLLECTIBLE)
		img = data->img_collectible;
	else if (data->map[i][j] == FREESPACE)
		img = data->img_freespace;
	else if (data->map[i][j] == EXIT)
		img = data->img_exit;
	else if (data->map[i][j] == PLAYER)
		img = data->img_player;
	else if (data->map[i][j] == PLAYER_ON_EXIT)
		img = data->img_player;
	if (img)
		mlx_put_image_to_window(data->mlx,
			data->win, img, j * TILE_SIZE, i * TILE_SIZE);
}

/**
 * @brief Draw the map on the window
 *
 * @param data The data structure
 *
 * @note Draw the map on the window
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/28
 */
void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			draw_tile(data, i, j);
			j++;
		}
		i++;
	}
}

/**
 * @brief Initialize the graphics
 *
 * @param data The data structure
 *
 * @note Load the images for the tiles
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/28
 */
void	initialize_graphics(t_data *data)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "./sprites/wall.xpm",
			&data->img_width, &data->img_height);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx,
			"./sprites/collectible.xpm", &data->img_width, &data->img_height);
	data->img_freespace = mlx_xpm_file_to_image(data->mlx,
			"./sprites/free_space.xpm", &data->img_width, &data->img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "./sprites/exit.xpm",
			&data->img_width, &data->img_height);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "./sprites/player.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_wall || !data->img_collectible || !data->img_freespace
		|| !data->img_exit || !data->img_player)
		error_exit(FAIL_LOAD_IMG);
}
