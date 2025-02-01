/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:37:25 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 15:11:04 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Initialize the data structure to NULL
 *
 * @param data The data structure
 *
 * @note Initialize the data structure to NULL
 *
 * @return void
 */
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

/**
 * @brief Main function
 *
 * @param ac The number of arguments
 * @param av The arguments
 *
 * @note The main function
 *
 * @note calls the functions to initialize the data structure, read the map,
 * validate the map, initialize the graphics, draw the map, and handle the
 * key events and close the window
 *
 * @return The exit status
 */
int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 2)
		error_exit(USAGE);
	init_null(&data);
	data.map = read_map(av[1], &data.map_width, &data.map_height);
	validate_map(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		free_map(data.map, data.map_height);
		return (EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.map_width * TILE_SIZE,
			data.map_height * TILE_SIZE, TITLE);
	initialize_graphics(&data);
	draw_map(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
