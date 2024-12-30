/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:47:27 by jcheron           #+#    #+#             */
/*   Updated: 2024/12/30 17:15:52 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cleanup(t_data *data)
{
	free_map(data->map, data->map_height);
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
	}
}

// void	cleanup(t_data *data)
// {
// 	void	*imgs[5];
// 	int		i;

// 	imgs[0] = data->img_wall;
// 	imgs[1] = data->img_collectible;
// 	imgs[2] = data->img_freespace;
// 	imgs[3] = data->img_exit;
// 	imgs[4] = data->img_player;
// 	i = 0;
// 	while (i < 5)
// 	{
// 		if (imgs[i])
// 			mlx_destroy_image(data->mlx, imgs[i]);
// 		i++;
// 	}
// 	if (data->win)
// 	{
// 		mlx_destroy_window(data->mlx, data->win);
// 	}
// 	if (data->mlx)
// 	{
// 		mlx_destroy_display(data->mlx);
// 		free(data->mlx);
// 	}
// 	free_map(data->map, data->map_height);
// }
