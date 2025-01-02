/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:16:44 by fakambou          #+#    #+#             */
/*   Updated: 2024/12/31 15:44:19 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_line(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	map->column = 0;
	while (line)
	{
		map->column++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	load_map(t_map *map, char *filename)
{
	int		i;
	int		fd;
	size_t	j;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error:\nCan not open the file", map);
	map->map = malloc(sizeof(char *) * (map->column + 1));
	if (!map->map)
		return ;
	map->map[0] = get_next_line(fd);
	i = 0;
	while (++i < map->column)
	{
		map->map[i] = get_next_line(fd);
		j = ft_strlen(map->map[i]);
		map->map[i][j] = '\0';
	}
	map->map[map->column] = NULL;
	close(fd);
}

void	ft_init(t_map *map)
{
	map->map = NULL;
	map->column = 0;
	map->length = 0;
	map->item = 0;
	map->exit = 0;
	map->start = 0;
	map->new_x = 0;
	map->new_y = 0;
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(char *s, t_map *map)
{
	ft_printf(s);
	if (map->map != NULL)
		free_map(map->map);
	exit(EXIT_FAILURE);
}
