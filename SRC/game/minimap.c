/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 04:04:47 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/15 04:04:49 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	draw_player(t_game *game)
{
	int	i;
	int	j;

	i = -3;
	while (i <= 3)
	{
		j = -3;
		while (j <= 3)
		{
			put_pixel(
				game->player_x * TILE_SIZE + i,
				game->player_y * TILE_SIZE + j,
				0xFF0000,
				game);
			j++;
		}
		i++;
	}
}

void	draw_tile(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			put_pixel(x + i, y + j, color, game);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				draw_tile(game, x * TILE_SIZE, y * TILE_SIZE, 0x000000);
			else
				draw_tile(game, x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF);
			x++;
		}
		y++;
	}
	draw_player(game);
}
