/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:42:14 by onkeltag          #+#    #+#             */
/*   Updated: 2025/01/05 17:13:51 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	move_player(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + dx;
	new_y = data->player_y + dy;
	if (new_x < 0 || new_x >= data->map_width || new_y >= data->map_height)
		return (0);
	if (data->map[new_y][new_x] == '1')
		return (0);
	if (data->map[new_y][new_x] == 'C')
	{
		data->map[new_y][new_x] = '0';
		data->to_collect -= 1;
	}
	if (data->map[new_y][new_x] == 'E' && data->to_collect == 0)
	{
		ft_printf("WIN");
		close_window(data);
		exit(EXIT_SUCCESS);
	}
	data->map[data->player_y][data->player_x] = '0';
	data->map[new_y][new_x] = 'P';
	data->player_y = new_y;
	data->player_x = new_x;
	return (1);
}
