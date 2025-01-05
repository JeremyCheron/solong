/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:37:25 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/05 16:57:03 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_null(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->img_wall = NULL;
	data->img_collectible = NULL;
	data->img_freespace = NULL;
	data->img_exit = NULL;
	data->img_player = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 2)
		error_exit("Usage: ./so_long <map_file.ber>\n");
	init_null(&data);
	data.map = read_map(av[1], &data.map_width, &data.map_height);
	validate_map(&data);
	ft_printf("Player position, x : %d, y: %d", data.player_x, data.player_y);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		free_map(data.map, data.map_height);
		return (EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.map_width * TILE_SIZE,
			data.map_height * TILE_SIZE, "so_long");
	initialize_graphics(&data);
	draw_map(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
