/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:08:02 by jcheron           #+#    #+#             */
/*   Updated: 2025/02/01 15:06:02 by onkeltag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * @brief Free the map and exit with an error message
 *
 * @param map The map to free
 * @param height The height of the map
 * @param msg The error message
 *
 * @note The map is freed and the program exits with an error message in stderr
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/27
 */
void	fill_error_exit(char **map, char **copy, int height, char *msg)
{
	cleanup_lines(copy, height);
	free(copy);
	free_map(map, height);
	error_exit(msg);
}


/**
 * @brief Exit with an error message
 *
 * @param msg The error message
 *
 * @note The program exits with an error message in stderr
 *
 * @return void
 *
 * @author jcheron
 * @date 2025/01/27
 */
void	error_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
