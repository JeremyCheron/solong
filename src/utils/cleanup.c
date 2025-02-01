/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:47:27 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 15:07:56 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Free the map
 *
 * @param map The map to free
 * @param height The height of the map
 *
 * @note Free the map and set it to NULL
 *
 * @return void
 */
void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/**
 * @brief Free the lines of the map
 *
 * @param map The map to free
 * @param height The height of the map
 *
 * @note Free the lines of the map and set them to NULL
 *
 * @return void
 */
void	cleanup_lines(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
}

/**
 * @brief Free the map and the images
 *
 * @param data The data structure
 *
 * @note Free the map and the images
 *
 * @return void
 */
void	cleanup(t_data *data)
{
	free_map(data->map, data->map_height);
	data->map = NULL;
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_collectible)
		mlx_destroy_image(data->mlx, data->img_collectible);
	if (data->img_freespace)
		mlx_destroy_image(data->mlx, data->img_freespace);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}
