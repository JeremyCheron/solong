/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:07:31 by jcheron           #+#    #+#             */
/*   Updated: 2024/12/30 17:33:40 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	validate_character(char c, int *counts, t_data *data)
{
	if (c == 'E')
		counts[0]++;
	else if (c == 'C')
		counts[1]++;
	else if (c == 'P')
		counts[2]++;
	else if (c != '0' && c != '1')
	{
		cleanup(data);
		error_exit("Invalid character in map");
	}
}

static void	validate_edges(char c, int is_edge, t_data *data)
{
	if (is_edge && c != '1')
	{
		cleanup(data);
		error_exit("Map is not surrounded by walls");
	}
}

void	validate_map(t_data *data)
{
	int	counts[3];
	int	i;
	int	j;

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
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
		error_exit("Invalid map elements");
	}
}
