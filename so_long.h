/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:15:57 by fakambou          #+#    #+#             */
/*   Updated: 2025/01/02 18:45:36 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/header/libft.h"
# include "libft/header/get_next_line.h"
# include "libft/header/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_map
{
	char	**map;
 	int		length;
	int		column;
	int		item;
	int		exit;
	int		start;
	char	**cpymap;
	int		new_x;
	int		new_y;
}	t_map;

void	load_map(t_map *map, char *filename);
void	ft_count_line(char *filename, t_map *map);
void	ft_error(char *s, t_map *map);
void	free_map(char **map);
bool	ft_rectangle(t_map *map);
int		check_files(char *s, t_map *map);
void	ft_init(t_map *map);
int		len_tab(char **tab);
void	check_wall(t_map *map);
void	check_map(t_map *map);
void	copy_map(t_map *map);
void	flood_fill(char **map, int x, int y, t_map *m);
void	find_player(t_map *map);
void	check_cpymap(t_map *map);
void	print_map(char **map);

#endif