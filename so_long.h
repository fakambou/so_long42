/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:15:57 by fakambou          #+#    #+#             */
/*   Updated: 2025/01/24 20:20:17 by fakambou         ###   ########.fr       */
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
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

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
	int		collectibles;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	char	**map;
	void	*background;
	void	*collectable;
	void	*player;
	void	*wall;
	void	*exit;
	int		old_y;
	int		old_x;
	t_map	m;
}t_game;

void	load_map(t_map *map, char *filename);
void	ft_count_line(char *filename, t_map *map);
void	ft_error(char *s, t_map *map);
void	free_map(char **map);
bool	ft_rectangle(t_map *map);
int		check_files(char *s, t_map *map);
void	ft_init(t_map *map);
int		len_tab(char **tab);
int		lengthline(char *line);
void	check_wall(t_map *map);
void	check_map(t_map *map);
void	copy_map(t_map *map);
void	flood_fill(char **map, int x, int y, t_map *m);
void	find_player(t_map *map);
void	check_cpymap(t_map *map);
void	init_map(t_game *game, char **map);
int		close_window(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	load_textures(t_game *game);
void	draw_map(t_game *game, t_map *map);
void	elyeshattab(t_game *game);
void	exit_game(t_game *game);

#endif