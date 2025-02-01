/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:07:31 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 15:10:22 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Validate the character
 *
 * @param c The character to validate
 * @param counts The counts of the characters
 * @param data The data structure
 *
 * @note Validate the character and update the counts
 *
 * @return void
 */
static void	validate_character(char c, int *counts, t_data *data)
{
	if (c == EXIT)
		counts[0]++;
	else if (c == COLLECTIBLE)
		counts[1]++;
	else if (c == PLAYER)
		counts[2]++;
	else if (c != FREESPACE && c != WALL)
	{
		cleanup(data);
		error_exit(INVALID_CHAR);
	}
	data->to_collect = counts[1];
	init_player_position(data);
}

/**
 * @brief Validate the edges
 *
 * @param c The character to validate
 * @param is_edge The edge flag
 * @param data The data structure
 *
 * @note Validate the edges of the map
 *
 * @return void
 */
static void	validate_edges(char c, int is_edge, t_data *data)
{
	if (is_edge && c != WALL)
	{
		cleanup(data);
		error_exit(INVALID_MAP_WALLS);
	}
}

/**
 * @brief Validate the map
 *
 * @param data The data structure
 *
 * @note Validate the map elements and access to the collectibles and the exit
 *
 * @return void
 */
void	validate_map(t_data *data)
{
	int	counts[3];
	int	i;
	int	j;

	ft_bzero(counts, sizeof(int) * 3);
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			validate_character(data->map[i][j], counts, data);
			validate_edges(data->map[i][j], i == 0 || i == data->map_height - 1
				|| j == 0 || j == data->map_width - 1, data);
			j++;
		}
		i++;
	}
	if (counts[0] != 1 || counts[1] < 1 || counts[2] != 1)
	{
		cleanup(data);
		error_exit(INVALID_MAP_ELEM);
	}
	validate_access(data->map, data->map_width, data->map_height);
}
