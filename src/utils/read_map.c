/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:59:27 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/27 10:57:08 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
	validate_access(map.map, map.width, map.height);
	*width = map.width;
	*height = map.height;
	return (map.map);
}
