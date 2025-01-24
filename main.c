/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:09:12 by fakambou          #+#    #+#             */
/*   Updated: 2025/01/24 20:35:42 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *s)
{
	size_t	s_size;

	s_size = ft_strlen(s);
	if (ft_strncmp(s + s_size - 4, ".ber", 100))
	{
		write(2, "Error:\nbad extension", 20);
		exit(1);
	}
}

int	check_files(char *s, t_map *map)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error:\nNo such file", map);
		return (-1);
	}
	return (0);
}

void	so_long(t_map *map, t_game *game)
{
	ft_rectangle(map);
	check_wall(map);
	check_map(map);
	find_player(map);
	copy_map(map);
	flood_fill(map->cpymap, map->new_x, map->new_y, map);
	check_cpymap(map);
	init_map(game, map->map);
	load_textures(game);
	draw_map(game, map);
	free_map(map->cpymap);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask,
		close_window, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_init(&game.m);
	if (ac != 2)
		ft_error("Error:\nOnly one argument is required", &game.m);
	check_ber(av[1]);
	check_files(av[1], &game.m);
	ft_count_line(av[1], &game.m);
	load_map(&game.m, av[1]);
	so_long(&game.m, &game);
}
