/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:59:27 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/05 22:12:36 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*trim_newline(char *line)
{
	int		len;
	char	*trimmed;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	trimmed = ft_strdup(line);
	if (!trimmed)
		error_exit("Memory allocation failed");
	free(line);
	return (trimmed);
}

void	check_width(int *width, int current_width, char **map, int height)
{
	if (*width == 0)
		*width = current_width;
	else if (*width != current_width)
	{
		free_map(map, height);
		error_exit("Map is not rectangular");
	}
}

char	**realloc_map(char **map, int new_height)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * new_height);
	if (!new_map)
	{
		if (map)
			free_map(map, new_height - 1);
		error_exit("Memory allocation failed");
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
	int		fd;
	char	*line;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open map file");
	map = NULL;
	*height = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = trim_newline(line);
		check_width(width, ft_strlen(line), map, *height);
		map = realloc_map(map, *height + 1);
		if (!map)
		{
			free(line);
			error_exit("Memory allocation failed");
		}
		map[*height] = line;
		(*height)++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (map);
}
