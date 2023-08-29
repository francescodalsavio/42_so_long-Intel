/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:21:47 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/29 10:06:21 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*ft_calloc(size_t bytes)
{
	void	*var;
	char	*tmp;
	size_t	i;

	var = malloc(bytes);
	if (!var)
		exit(1);
	tmp = (char *)var;
	i = 0;
	while (i < bytes)
	{
		tmp[i] = 0;
		i++;
	}
	return (var);
}

void	free_imgs(t_game *game)
{
	mlx_destroy_image(game->game_state, game->game_objects.free_space_object);
	mlx_destroy_image(game->game_state, game->game_objects.wall_object);
	mlx_destroy_image(game->game_state, game->player.sprite);
	mlx_destroy_image(game->game_state, game->game_objects.exit_object);
	if (game->collectible.sprite)
		mlx_destroy_image(game->game_state, game->collectible.sprite);
}

void	free_map(t_game *map)
{
	int	i;

	i = 0;
	while (i < map->map.height)
	{
		free(map->map.layout[i]);
		i++;
	}
	free(map->map.layout);
}

void	free_on_error(void (*ft_free)(void *), void *par, char *error)
{
	ft_free(par);
	show_error(error);
}
