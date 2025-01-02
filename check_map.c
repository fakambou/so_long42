/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:04:45 by fakambou          #+#    #+#             */
/*   Updated: 2025/01/02 17:55:57 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lengthline(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		i++;
	}
	return (i);
}

bool	ft_rectangle(t_map *map)
{
	int		i;

	if (!map || !map->map)
		return (false);
	map->length = lengthline(map->map[0]);
	i = 1;
	while (map->map[i])
	{
		if (lengthline(map->map[i]) != map->length)
			ft_error("Error:\n put the map in the right shape", map);
		i++;
	}
	return (true);
}

void	check_wall(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[0][++i] != '\n')
		if (map->map[0][i] != '1')
			ft_error("Error:\nThe map must be surrounded by walls1", map);
	i = -1;
	while (map->map[map->column - 1][++i] != '\0')
		if (map->map[map->column - 1][i] != '1')
			ft_error("Error:\nThe map must be surrounded by walls2", map);
	i = -1;
	while (map->map[++i])
	{
		if (map->map[i][0] != '1')
			ft_error("Error:\nThe map must be surrounded by walls3", map);
		if (map->map[i][map->length - 1] != '1')
			ft_error("Error:\nThe map must be surrounded by walls4", map);
	}
}

void	check_map(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y]){
			if (map->map[x][y] == 'C')
				map->item++;
			else if (map->map[x][y] == 'E')
				map->exit++;
			else if (map->map[x][y] == 'P')
				map->start++;
			else if (map->map[x][y] != '1' && map->map[x][y] != '0' \
				&& map->map[x][y] != '\n')
				ft_error("Error:\nPut only valid characters", map);
		}
	}
	if (map->item < 1)
		ft_error("Error:\nPut at least one collectable", map);
	if (map->exit != 1)
		ft_error("Error:\nPut just one exit", map);
	if (map->start != 1)
		ft_error("Error:\nSet only one starting position", map);
}
