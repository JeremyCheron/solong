/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:59:27 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 15:09:34 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Trim the newline character at the end of the line
 *
 * @param line The line to trim
 *
 * @note Trim the newline character at the end of the line
 *
 * @return The trimmed line
 */
char	*trim_newline(char *line)
{
	char	*trimmed;
	int		len;

	if (!line)
		error_exit(INVALID_LINE);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == NL)
		line[len - 1] = EOL;
	trimmed = ft_strdup(line);
	if (!trimmed)
	{
		free(line);
		error_exit(MEMORY_ALLOC);
	}
	free(line);
	return (trimmed);
}

/**
 * @brief Check the width of the map
 *
 * @param map_data The map data
 * @param current_width The width of the line
 * @param line The line to check
 *
 * @note Check if the width of the line is the same as the previous lines
 *
 * @return void
 */
void	validate_map_width(
						int expected_width,
						int current_width,
						t_map_data *map_data,
						char *line)
{
	if (expected_width != 0 && expected_width != current_width)
	{
		free(line);
		free_map(map_data->map, map_data->height);
		error_exit(INVALID_MAP_RECT);
	}
}

/**
 * @brief Check the width of the map
 *
 * @param map_data The map data
 * @param width The width of the line
 * @param line The line to check
 *
 * @note Check if the width of the line is the same as the previous lines
 *
 * @return void
 */
void	check_width(
				t_map_data *map_data,
				int current_width,
				char *line)
{
	if (map_data->width == 0)
		map_data->width = current_width;
	else
		validate_map_width(map_data->width, current_width, map_data, line);
}

/**
 * @brief Reallocate the map
 *
 * @param map The map to reallocate
 * @param new_height The new height of the map
 *
 * @note Reallocate the map with a new height
 *
 * @return The reallocated map
 */
char	**realloc_map(char **map, int new_height)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * new_height);
	if (!new_map)
	{
		cleanup_lines(map, new_height - 1);
		error_exit(MEMORY_ALLOC);
	}
	i = 0;
	while (i < new_height - 1)
	{
		new_map[i] = map[i];
		i++;
	}
	free(map);
	return (new_map);
}

/**
 * @brief Read the map from a file
 *
 * @param filename The name of the file
 * @param width The width of the map
 * @param height The height of the map
 *
 * @note Read the map from a file
 *
 * @return The map
 */
char	**read_map(const char *filename, int *width, int *height)
{
	int			fd;
	char		*line;
	t_map_data	map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(FAIL_OPEN_MAP);
	map = (t_map_data){0, 0, NULL};
	line = get_next_line(fd);
	while (line)
	{
		gnl_map(fd, line, &map);
		line = get_next_line(fd);
	}
	close(fd);
	if (map.height == 0)
	{
		free_map(map.map, map.height);
		error_exit(EMPTY_MAP);
	}
	*width = map.width;
	*height = map.height;
	return (map.map);
}
