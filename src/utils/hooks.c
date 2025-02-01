/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:52:33 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 15:09:32 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Close the window
 *
 * @param data The data structure
 *
 * @note Close the window and exit the program
 *
 * @return void
 */
int	close_window(t_data *data)
{
	cleanup(data);
	exit(EXIT_SUCCESS);
	return (0);
}

/**
 * @brief Handle the key events
 *
 * @param keycode The key code
 * @param data The data structure
 *
 * @note Handle the key events
 *
 * @return void
 */
int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else if (keycode == W || keycode == UP)
		move_player(data, 0, -1);
	else if (keycode == A || keycode == LEFT)
		move_player(data, -1, 0);
	else if (keycode == S || keycode == DOWN)
		move_player(data, 0, 1);
	else if (keycode == D || keycode == RIGHT)
		move_player(data, 1, 0);
	draw_map(data);
	return (0);
}
