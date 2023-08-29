/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:53:03 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/29 11:16:09 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_allocate(char *map_path, t_game *game)
{
	int		i;
	int		fd;

	game->map.layout = ft_calloc((game->map.height + 1) * 8);
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (i < game->map.height)
	{
		game->map.layout[i] = get_next_line(fd);
		if (game->map.layout[i][ft_strlen(game->map.layout[i]) - 1] == 10)
			game->map.layout[i][ft_strlen(game->map.layout[i]) - 1] = 0;
		i++;
	}
	close(fd);
	game->map.layout[i] = NULL;
}

void	map_manager(char *map_path, t_game *game)
{
	int		fd;
	char	*line;

	game->map.height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		show_error("Error: map not found!\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.height++;
		free(line);
	}
	close(fd);
	map_allocate(map_path, game);
	game->map.width = ft_strlen(game->map.layout[0]);
	map_checker(game);
}
