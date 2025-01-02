/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:09:12 by fakambou          #+#    #+#             */
/*   Updated: 2025/01/02 19:00:45 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *s)
{
	size_t	s_size;

	s_size = ft_strlen(s);
	if (ft_strncmp(s + s_size - 4, ".ber", 100))
	{
		write(2, "Error: bad extension\n", 22);
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

void	so_long(t_map *map)
{
	ft_rectangle(map);
	check_wall(map);
	check_map(map);
	find_player(map);
	copy_map(map);
	flood_fill(map->cpymap, map->new_x, map->new_y, map);
	check_cpymap(map);
	print_map(map->cpymap);
}

int	main(int ac, char **av)
{
	t_map	map;

	ft_init(&map);
	if (ac != 2)
		return (1);
	check_ber(av[1]);
	check_files(av[1], &map);
	ft_count_line(av[1], &map);
	load_map(&map, av[1]);
	so_long(&map);
	
	// int i = 0;
	// while (i < map.size)
	// {
	// 	ft_printf("%s", map.map[i]);
	// 	i++;
	// }
	// check_wall(&map);
	// // ft_printf("%s", map.map[0]);
}
