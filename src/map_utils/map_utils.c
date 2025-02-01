/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:45:41 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 15:06:56 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Check the width of the map
 *
 * @param map The map data
 * @param width The width of the line
 * @param line The line to check
 *
 * @note Check if the width of the line is the same as the previous lines
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/27
 */
void	gnl_map(int fd, char *line, t_map_data *map)
{
	(void)fd;
	line = trim_newline(line);
	check_width(map, ft_strlen(line), line);
	map->map = realloc_map(map->map, map->height + 1);
	if (!map->map)
	{
		free(line);
		error_exit(MEMORY_ALLOC);
	}
	map->map[map->height] = line;
	map->height++;
}
