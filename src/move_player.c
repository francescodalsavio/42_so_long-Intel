/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:44:24 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/29 11:21:50 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_player_move(t_game *game, int x, int y)
{
	if (x > 0)
		game->player.sprite = game->player.sprite_right;
	else if (x < 0)
		game->player.sprite = game->player.sprite_left;
	else if (y > 0)
		game->player.sprite = game->player.sprite_down;
	else if (y < 0)
		game->player.sprite = game->player.sprite_up;
	if (game->map.layout[game->player.y][game->player.x] != 50)
		mlx_put_image_to_window(game->game_state, \
		game->window, game->player.sprite,
			game->player.x * 50, game->player.y * 50);
}

void	ft_map_reader(t_game *game, int c, void *img)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.layout[y])
	{
		x = 0;
		while (game->map.layout[y][x])
		{
			if (game->map.layout[y][x] == c)
				mlx_put_image_to_window(game->game_state, game->window, \
					img, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	ft_new_position(t_game *game, int x, int y)
{
	t_image	img;

	if (game->map.layout[y][x] == 67)
	{
		game->map.layout[y][x] = 48;
		game->collectible.collected++;
		put_images_to_window(game, x, y);
		if (game->collectible.collected == game->collectible.total)
		{
			mlx_destroy_image(game->game_state, game->game_objects.exit_object);
			game->game_objects.exit_object = \
			mlx_xpm_file_to_image(game->game_state, \
				"../resources/exit/unlock.xpm", &img.width, &img.heigth);
			ft_map_reader(game, 69, game->game_objects.free_space_object);
			ft_map_reader(game, 69, game->game_objects.exit_object);
		}
	}
	else if (game->map.layout[y][x] == 69 && \
	game->collectible.total == game->collectible.collected)
		quit_game(game);
	else if (game->map.layout[y][x] == 50)
		quit_game(game);
}

void	move_player(t_game *game, int x, int y)
{
	char	*movement_counter_string;

	if (game->map.layout[game->player.y + y][game->player.x + x] == '1')
		return ;
	game->player.movement_counter++;
	game->player.x += x;
	game->player.y += y;
	put_images_to_window(game, 0, 0);
	movement_counter_string = ft_itoa(game->player.movement_counter);
	mlx_string_put(game->game_state, \
	game->window, 15, 15, 0, movement_counter_string);
	free(movement_counter_string);
	ft_new_position(game, game->player.x, game->player.y);
	ft_player_move(game, x, y);
	put_images_to_window(game, game->player.x - x, game->player.y - y);
}

void	keys_actions(int key, t_game *game)
{
	if (key == 2 || key == 124)
		move_player(game, 1, 0);
	else if (key == 0 || key == 123)
		move_player(game, -1, 0);
	else if (key == 1 || key == 125)
		move_player(game, 0, 1);
	else if (key == 13 || key == 126)
		move_player(game, 0, -1);
	else if (key == 12 || key == 53)
		quit_game(game);
}
