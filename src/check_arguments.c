/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:04:31 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/11 11:23:36 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_map_name(char *str)
{
	if (ft_strlen(str) < 5 || ft_strlen(str) > 100)
		return (0);
	return (1);
}

int	check_map_extension(char *str)
{
	if (ft_strncmp(str + ft_strlen(str) - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

void	check_arguments(int argc, char **argv)
{
	if (argc < 2)
		show_error("You must provide a map\n");
	else if (argc > 2)
		show_error("Too many arguments\n");
	else if (!check_map_name(argv[1]))
		show_error("Map name must be between 5 and 100 characters\n");
	else if (!check_map_extension(argv[1]))
		show_error("Map extension must be .ber\n");
}
