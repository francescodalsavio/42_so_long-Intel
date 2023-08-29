/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:51:11 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/29 10:12:50 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_image	img;
	int		width;
	int		height;

	game.player.movement_counter = 0;
	game.collectible.collected = 0;
	game.collectible.total = 0;
	check_arguments(argc, argv);
	map_manager(argv[1], &game);
	game.game_state = mlx_init();
	width = game.map.width * 50;
	height = game.map.height * 50;
	game.window = mlx_new_window(game.game_state, width, height, "so_long");
	show_images(&game, &img);
	mlx_key_hook(game.window, (void *)keys_actions, &game);
	mlx_hook(game.window, 17, 0, (void *)quit_game, &game);
	mlx_loop_hook(game.game_state, (void *)animate_enemy, &game);
	mlx_loop(game.game_state);
	return (0);
}
