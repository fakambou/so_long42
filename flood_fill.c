/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:24:53 by fakambou          #+#    #+#             */
/*   Updated: 2024/12/21 21:36:38 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_map *map)
{
	int	i;

	map->cpymap = malloc(sizeof(char *) * (map->column + 1));
	if (!map->cpymap)
		return ;
	i = 0;
	while (i < map->column)
	{
		map->cpymap[i] = ft_strdup(map->map[i]);
		i++;
	}
	map->cpymap[i] = NULL;
}

void	flood_fill(char **map, int x, int y, t_map *m)
{
	if (x < 0 || y < 0 || y >= m->column || x >= m->length
		|| ft_strchr("1FE", map[y][x]))
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, m);
	flood_fill(map, x - 1, y, m);
	flood_fill(map, x, y + 1, m);
	flood_fill(map, x, y - 1, m);
}

void	find_player(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->new_x = x;
				map->new_y = y;
			}
			x++;
		}
		y++;
	}
	if (map->new_x == 0 || map->new_y == 0)
		ft_error("Error:\nPlayer not found", map);
}

void	check_cpymap(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->column)
	{
		x = 0;
		while (x < map->length)
		{
			if (map->cpymap[y][x] == 'C')
				ft_error("Error:\nSome collectable cannot be recovered\n", map);
			if (map->cpymap[y][x] == 'E')
			{
				if (map->cpymap[y + 1][x] != 'F' && map->cpymap[y - 1][x] != 'F'
					&& map->cpymap[y][x + 1] != 'F'
						&& map->cpymap[y][x - 1] != 'F')
					ft_error("Error:\nThe exit is not reachable", map);
			}
			x++;
		}
		y++;
	}
}

