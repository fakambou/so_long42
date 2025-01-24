/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:13:20 by fakambou          #+#    #+#             */
/*   Updated: 2025/01/24 19:07:02 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	elyeshattab(t_game *game)
{
	static int	move;

	ft_printf("Number of moves : %d\n", move++);
	if (game->map[game->m.new_y][game->m.new_x] == 'C')
	{
		game->map[game->m.new_y][game->m.new_x] = '0';
		game->m.item--;
	}
	if (game->map[game->m.new_y][game->m.new_x] == 'E')
	{
		if (game->m.item == 0)
		{
			mlx_destroy_image(game->mlx_ptr, game->background);
			mlx_destroy_image(game->mlx_ptr, game->player);
			mlx_destroy_image(game->mlx_ptr, game->wall);
			mlx_destroy_image(game->mlx_ptr, game->collectable);
			mlx_destroy_image(game->mlx_ptr, game->exit);
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
			free_map(game->m.map);
			exit(0);
		}
	}
}
