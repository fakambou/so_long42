/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:04:45 by fakambou          #+#    #+#             */
/*   Updated: 2025/01/24 19:12:26 by fakambou         ###   ########.fr       */
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

void	check_map(t_map *m)
{
	int	x;
	int	y;

	x = -1;
	while (m->map[++x])
	{
		y = -1;
		while (m->map[x][++y])
		{
			if (m->map[x][y] == 'C')
				m->item++;
			else if (m->map[x][y] == 'E')
				m->exit++;
			else if (m->map[x][y] == 'P')
				m->start++;
			else if (m->map[x][y] != '1' && m->map[x][y] != '0'
				&& m->map[x][y] != '\n')
				ft_error("Error:\nPut only valid characters", m);
		}
	}
	if (m->item < 1)
		ft_error("Error:\nPut at least one collectable", m);
	if (m->exit != 1 || m->start != 1)
		ft_error("Error:\nPut just one exit, or check starting position", m);
	//if (m->start != 1)
		//ft_error("Error:\nSet only one starting position", m);
}
