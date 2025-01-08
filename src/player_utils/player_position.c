/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:42:14 by onkeltag          #+#    #+#             */
/*   Updated: 2025/01/05 21:48:36 by onkeltag         ###   ########.fr       */
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
				data->moves = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	_move_player(t_data *data, int new_x, int new_y)
{

	data->map[data->player_y][data->player_x] = '0';
	data->map[new_y][new_x] = 'P';
	data->player_y = new_y;
	data->player_x = new_x;
}

void	move_player(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + dx;
	new_y = data->player_y + dy;
	if (new_x < 0 || new_x >= data->map_width || new_y >= data->map_height
		|| (data->map[new_y][new_x] == 'E' && data->to_collect != 0)
		|| data->map[new_y][new_x] == '1')
		return ;
	if (data->map[new_y][new_x] == 'C')
	{
		data->map[new_y][new_x] = '0';
		data->to_collect -= 1;
	}
	data->moves += 1;
	ft_printf("moves : %d\n", data->moves);
	if (data->map[new_y][new_x] == 'E' && data->to_collect == 0)
	{
		ft_printf("WIN with %d moves\n", data->moves);
		close_window(data);
		exit(EXIT_SUCCESS);
	}
	_move_player(data, new_x, new_y);
}
