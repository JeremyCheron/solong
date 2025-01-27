/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:45:41 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/27 10:57:41 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
