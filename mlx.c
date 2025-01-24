/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:20:44 by fakambou          #+#    #+#             */
/*   Updated: 2025/01/24 19:06:22 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, char **map)
{
	int	height;
	int	width;

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit(EXIT_FAILURE);
	game->map = map;
	height = 0;
	while (map[height])
		height++;
	width = lengthline(map[0]);
	game->win_ptr = mlx_new_window(game->mlx_ptr, width * 64,
			height * 64, "So_long");
	mlx_hook(game->win_ptr, 17, 0, close_window, game);
}

int	close_window(t_game *game)
{
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	int			x;
	int			y;

	y = game->m.new_y;
	x = game->m.new_x;
	if (keycode == ESC_KEY)
		close_window(game);
	else if (keycode == W_KEY)
		y--;
	else if (keycode == S_KEY)
		y++;
	else if (keycode == A_KEY)
		x--;
	else if (keycode == D_KEY)
		x++;
	else
		return (1);
	if (game->map[y][x] == '1')
		return (1);
	game->m.new_x = x;
	game->m.new_y = y;
	elyeshattab(game);
	draw_map(game, &game->m);
	return (0);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	game->background = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/sol.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/wall2.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/luffy.xpm", &width, &height);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/gomu3.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"xpm/sunny.xpm", &width, &height);
	if (!game->background || !game->wall || !game->player || !game->collectable
		|| !game->exit)
	{
		ft_printf("Error:\nxpm file is not available\n");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(EXIT_FAILURE);
	}
}

void	draw_map(t_game *game, t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->background, x * 64, y * 64);
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->wall, x * 64, y * 64);
			if (map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->exit, x * 64, y * 64);
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->collectable, x * 64, y * 64);
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player,
		map->new_x * 64, map->new_y * 64);
}
