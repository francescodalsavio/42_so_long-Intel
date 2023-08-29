/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:15:18 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/29 09:53:33 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	quit_game(t_game *game)
{
	mlx_clear_window(game->game_state, game->window);
	mlx_destroy_window(game->game_state, game->window);
	free_imgs(game);
	free_map(game);
	exit(0);
}
