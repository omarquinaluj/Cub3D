/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:50:16 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/14 19:50:18 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

int	check_is_spaces(t_game *game, int x, int y)
{
	if (y == 0 || x == 0
		|| y == game->map_height - 1
		|| x == game->map_width - 1)
		return (0);
	if (game->map[y - 1][x] == ' '
		|| game->map[y + 1][x] == ' '
		|| game->map[y][x - 1] == ' '
		|| game->map[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	check_spaces(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '0'
				|| ft_strchr("NSEW", game->map[y][x]))
			{
				if (check_is_spaces(game, x, y) == 0)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
