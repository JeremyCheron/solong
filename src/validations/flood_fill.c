/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:35:52 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 15:09:28 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Copy the map
 *
 * @param dest The destination map
 * @param src The source map
 * @param height The height of the map
 *
 * @note Copy the map from the source to the destination
 *
 * @return void
 */
void	copy_map(
				char **dest,
				char **src,
				int height
)
{
	int	i;

	i = 0;
	while (i < height)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
		{
			cleanup_lines(dest, i);
			error_exit(MEMORY_ALLOC);
		}
		i++;
	}
	dest[i] = NULL;
}

/**
 * @brief Flood fill algorithm
 *
 * @param map The map
 * @param x The x coordinate
 * @param y The y coordinate
 *
 * @note Fill the map with the visited cells
 *
 * @return void
 */
void	flood_fill(
				char **map,
				int x,
				int y
)
{
	if (x < 0 || y < 0 || map[y][x] == WALL)
		return ;
	if (map[y][x] != COLLECTIBLE && map[y][x] != EXIT
		&& map[y][x] != PLAYER && map[y][x] != FREESPACE)
		return ;
	map[y][x] = VISITED;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

/**
 * @brief Find the player on the map
 *
 * @param copy The map copy
 * @param width The width of the map
 * @param height The height of the map
 *
 * @note Find the player on the map
 *
 * @return The coordinates of the player
 */
static int	*find_player(
					char **copy,
					int width,
					int height
)
{
	int	x;
	int	y;
	int	*coords;

	coords = malloc(sizeof(int) * 2);
	if (!coords)
		error_exit(MEMORY_ALLOC);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (copy[y][x] == PLAYER)
			{
				coords[0] = y;
				coords[1] = x;
				return (coords);
			}
			x++;
		}
		y++;
	}
	error_exit(NO_PLAYER);
	return (NULL);
}

/**
 * @brief Validate the map elements
 *
 * @param map The map
 * @param copy The map copy
 * @param width The width of the map
 * @param height The height of the map
 *
 * @note Validate the map elements
 *
 * @return void
 */
static void	validate_map_elements(
								char **map,
								char **copy,
								int width,
								int height
)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == COLLECTIBLE && copy[y][x] != VISITED)
				fill_error_exit(map, copy, height, COL_NOT_REACHABLE);
			if (map[y][x] == EXIT && copy[y][x] != VISITED)
				fill_error_exit(map, copy, height, EXIT_NOT_REACHABLE);
			x++;
		}
		y++;
	}
}

/**
 * @brief Validate the access to the collectibles and the exit
 *
 * @param map The map
 * @param width The width of the map
 * @param height The height of the map
 *
 * @note Validate the access to the collectibles and the exit
 *
 * @return void
 */
void	validate_access(
					char **map,
					int width,
					int height)
{
	char	**copy;
	int		*coords;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error_exit(MEMORY_ALLOC);
	copy_map(copy, map, height);
	coords = find_player(copy, width, height);
	flood_fill(copy, coords[1], coords[0]);
	free(coords);
	validate_map_elements(map, copy, width, height);
	cleanup_lines(copy, height);
	free(copy);
}
