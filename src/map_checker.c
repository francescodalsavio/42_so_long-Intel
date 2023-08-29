/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:53:03 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/29 10:41:58 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mandatory_chars(char c, int *ex_pl_col)
{
	if (c == 'E')
		ex_pl_col[0] = 1;
	else if (c == 'P')
		ex_pl_col[1] = 1;
	else if (c == 'C')
		ex_pl_col[2] = 1;
}

void	map_check_chars(t_game *map)
{
	char	*str;
	int		*ex_pl_col;
	int		i;
	int		j;

	str = "012CEP";
	i = -1;
	ex_pl_col = ft_calloc(3 * 4);
	while (map->map.layout[++i])
	{
		j = -1;
		while (map->map.layout[i][++j])
		{
			if (!strchr(str, map->map.layout[i][j]))
				free_on_error(free_map, map, "Error: forbidden char!\n");
			mandatory_chars(map->map.layout[i][j], ex_pl_col);
		}
	}
	if (!ex_pl_col[0] || !ex_pl_col[1] || !ex_pl_col[2])
		free_on_error(free_map, map, "Error: missing mandatory chars!\n");
	free(ex_pl_col);
}

void	map_check_wall(t_game *map)
{
	int		i;
	char	*error;

	error = "Error: walls settled incorrectly!\n";
	i = -1;
	while (map->map.layout[0][++i])
		if (map->map.layout[0][i] != '1')
			free_on_error(free_map, map, error);
	i = -1;
	while (map->map.layout[map->map.height - 1][++i])
		if (map->map.layout[map->map.height - 1][i] != '1')
			free_on_error(free_map, map, error);
	i = -1;
	while (map->map.layout[++i])
	{
		if (map->map.layout[i][0] != '1')
			free_on_error(free_map, map, error);
		if (map->map.layout[i][map->map.width - 1] != '1')
			free_on_error(free_map, map, error);
	}
}

void	map_checker(t_game *map)
{
	int		i;
	char	*error;

	error = "Error: map is not rectangular!\n";
	if (map->map.height < 3) 
		free_on_error(free_map, map, error);
	if (map->map.width < 3)
		free_on_error(free_map, map, error);
	if (map->map.height == map->map.width)
		free_on_error(free_map, map, error);
	i = 0;
	while (++i < map->map.height)
		if (ft_strlen(map->map.layout[i]) != ft_strlen(map->map.layout[i - 1]))
			free_on_error(free_map, map, error);
	map_check_wall(map);
	map_check_chars(map);
}
