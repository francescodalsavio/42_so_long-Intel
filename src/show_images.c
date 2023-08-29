/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:35:54 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/29 10:39:41 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_enemy_images(t_game *game, t_image *img)
{
	game->enemy.sprite = mlx_xpm_file_to_image(game->game_state, \
		"../resources/enemy/pizza.xpm", &img->width, &img->heigth);
	if (!game->enemy.sprite)
		free_on_error(free_map, game, "Error\nInvalid enemy sprite\n");
}

void	init_player_images(t_game *game, t_image *img)
{
	game->player.sprite_right = mlx_xpm_file_to_image(game->game_state, \
		"../resources/player/man_walking_right.xpm", &img->width, &img->heigth);
	game->player.sprite_left = mlx_xpm_file_to_image(game->game_state, \
		"../resources/player/man_walking_left.xpm", &img->width, &img->heigth);
	game->player.sprite_up = mlx_xpm_file_to_image(game->game_state, \
		"../resources/player/man_standing_down.xpm", &img->width, &img->heigth);
	game->player.sprite_down = mlx_xpm_file_to_image(game->game_state, \
		"../resources/player/man_standing_down.xpm", &img->width, &img->heigth);
	game->player.sprite = game->player.sprite_down;
	if (!game->player.sprite)
		free_on_error(free_map, game, "Error\nInvalid player sprite\n");
}

void	init_objects_images(t_game *game, t_image *img)
{
	game->game_objects.free_space_object = \
	mlx_xpm_file_to_image(game->game_state, \
	"../resources/free_space/free_space.xpm", &img->width, &img->heigth);
	game->game_objects.wall_object = mlx_xpm_file_to_image(game->game_state, \
		"../resources/wall/wall.xpm", &img->width, &img->heigth);
	game->collectible.sprite = mlx_xpm_file_to_image(game->game_state, \
		"../resources/collectible/avocado.xpm", &img->width, &img->heigth);
	game->game_objects.exit_object = mlx_xpm_file_to_image(game->game_state, \
		"../resources/exit/lock.xpm", &img->width, &img->heigth);
	init_player_images(game, img);
	init_enemy_images(game, img);
	if (!game->game_objects.wall_object || \
	!game->collectible.sprite || \
	!game->game_objects.exit_object || \
	!game->game_objects.free_space_object)
		free_on_error(free_map, game, "Error\nInvalid object sprite\n");
}

void	put_images_to_window(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->game_state, game->window, \
		game->game_objects.free_space_object, x * 50, y * 50);
	if (game->map.layout[y][x] == '1')
		mlx_put_image_to_window(game->game_state, game->window, \
			game->game_objects.wall_object, x * 50, y * 50);
	else if (game->map.layout[y][x] == 80 \
		&& y == game->player.y && x == game->player.x)
		mlx_put_image_to_window(game->game_state, game->window, \
			game->player.sprite, x * 50, y * 50);
	else if (game->map.layout[y][x] == 69)
		mlx_put_image_to_window(game->game_state, game->window, \
			game->game_objects.exit_object, x * 50, y * 50);
	else if (game->map.layout[y][x] == 67)
		mlx_put_image_to_window(game->game_state, game->window, \
			game->collectible.sprite, x * 50, y * 50);
	else if (game->map.layout[y][x] == 50)
		mlx_put_image_to_window(game->game_state, game->window, \
			game->enemy.sprite, x * 50, y * 50);
}

void	show_images(t_game *game, t_image *img)
{
	int	x;
	int	y;

	init_objects_images(game, img);
	y = 0;
	while (game->map.layout[y])
	{
		x = 0;
		while (game->map.layout[y][x])
		{
			if (game->map.layout[y][x] == 'P')
			{
				game->player.y = y;
				game->player.x = x;
			}
			if (game->map.layout[y][x] == 'C')
				game->collectible.total++;
			put_images_to_window(game, x, y);
			x++;
		}
		y++;
	}
}
