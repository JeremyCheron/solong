/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:52:33 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/05 17:07:06 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	close_window(t_data *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 119 || keycode == 65362)
		move_player(data, 0, -1);
	else if (keycode == 97 || keycode == 65361)
		move_player(data, -1, 0);
	else if (keycode == 115 || keycode == 65364)
		move_player(data, 0, 1);
	else if (keycode == 100 || keycode == 65363)
		move_player(data, 1 ,0);
	draw_map(data);
	return (0);
}
