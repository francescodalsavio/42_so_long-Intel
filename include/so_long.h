/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:56:59 by gvigilan          #+#    #+#             */
/*   Updated: 2023/08/29 11:15:40 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "../lib/minilibx_opengl_20191021/mlx.h"
# define SCREEN_WIDTH 500	
# define SCREEN_HEIGHT 500
# define BUFFER_SIZE 1

typedef struct t_image
{
	int	width;
	int	heigth;
}	t_image;

typedef struct t_gameObjects {
	void	*exit_object;
	void	*wall_object;
	void	*free_space_object;
}	t_gameObjects;

typedef struct t_player {
	int		x;
	int		y;
	void	*sprite;
	void	*sprite_right;
	void	*sprite_left;
	void	*sprite_up;
	void	*sprite_down;
	int		movement_counter;
}	t_player;

typedef struct t_enemy {
	void	*sprite;
}	t_enemy;

typedef struct t_collectible {
	void	*sprite;
	int		total;
	int		collected;
}	t_collectible;

typedef struct t_map {
	char	**layout;
	int		height;
	int		width;
}	t_map;

typedef struct t_game
{
	void			*game_state;
	void			*window;
	t_map			map;
	t_player		player;
	t_enemy			enemy;
	t_collectible	collectible;
	t_gameObjects	game_objects;
}	t_game;

size_t	ft_strlen(char *str);
void	show_error(char *str);
void	check_arguments(int argc, char **argv);
char	*ft_strdup(char *string);
char	*get_next_line(int fd);
void	map_checker(t_game *map);
void	free_on_error(void ft_free(), void *par, char *error);
void	free_map(t_game *map);
void	*ft_calloc(size_t bytes);
void	show_images(t_game *game, t_image *img);
void	free_imgs(t_game *game);
void	free_map(t_game *map);
void	quit_game(t_game *game);
void	put_images_to_window(t_game *game, int x, int y);
void	animate_enemy(t_game *game);
void	ft_map_reader(t_game *game, int c, void *img);
void	quit_game(t_game *game);
char	*ft_itoa(long long num);
void	map_manager(char *map_path, t_game *game);
void	keys_actions(int key, t_game *game);
#endif