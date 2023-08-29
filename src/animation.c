/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:07:07 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/29 09:53:33 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	change_collectible_image(t_game *game, int image)
{
	t_image	img;

	if (image < 100)
		game->enemy.sprite = mlx_xpm_file_to_image(game->game_state, \
			"../resources/enemy/pizza.xpm", &img.width, &img.heigth);
	else if (image < 200)
		game->enemy.sprite = mlx_xpm_file_to_image(game->game_state, \
			"../resources/enemy/fries.xpm", &img.width, &img.heigth);
	else if (image < 300)
		game->enemy.sprite = mlx_xpm_file_to_image(game->game_state, \
			"../resources/enemy/spaghetti.xpm", &img.width, &img.heigth);
}

void	animate_enemy(t_game *game)
{
	static int	image;

	usleep(6000);
	mlx_destroy_image(game->game_state, game->enemy.sprite);
	change_collectible_image(game, image);
	ft_map_reader(game, 50, game->game_objects.free_space_object);
	ft_map_reader(game, 50, game->enemy.sprite);
	image++;
	if (image == 300)
		image = 0;
}
