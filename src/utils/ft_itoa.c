/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdal-sa <frdal-sa@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:20:51 by frdal-sa          #+#    #+#             */
/*   Updated: 2023/08/29 09:58:33 by frdal-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_numlen(long long num, int base)
{
	int	counter;

	counter = 0;
	if (num < 0 && ++counter)
		num *= -1;
	while (num > 0 && ++ counter)
		num = num / base;
	return (counter);
}

char	*ft_itoa(long long num)
{
	int		strlen;
	char	*strnum;

	if (!num || num < INT_MIN || num > INT_MAX)
		return (NULL);
	if (num == 0)
	{
		strnum = ft_calloc(1);
		strnum[0] = 48;
		return (strnum);
	}
	strlen = ft_numlen(num, 10);
	strnum = ft_calloc(strlen);
	if (num < 0)
	{
		strnum[0] = 45;
		num *= -1;
	}
	while (num > 0)
	{
		strlen--;
		strnum[strlen] = (num % 10) + 48;
		num = num / 10;
	}
	return (strnum);
}
