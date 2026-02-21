/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:27:34 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/18 13:05:39 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"
#include <math.h>

int	is_a_block(t_game *game, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0 || map_x >= game->map_width
		|| map_y >= game->map_height)
		return (1);
	return (game->map[map_y][map_x] == '1');
}

void	put_pixel(int x, int y, int color, t_game *game)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	((unsigned int *)game->mlx->data)
	[y * (game->mlx->size_line / 4) + x] = color;
}

static int	perform_dda(t_game *game)
{
	int	side;

	game->rays.hit = 0;
	while (!game->rays.hit)
	{
		if (game->rays.side_dist_x < game->rays.side_dist_y)
		{
			game->rays.side_dist_x += game->rays.delta_dist_x;
			game->rays.map_x += game->rays.step_x;
			side = 0;
		}
		else
		{
			game->rays.side_dist_y += game->rays.delta_dist_y;
			game->rays.map_y += game->rays.step_y;
			side = 1;
		}
		if (is_a_block(game, game->rays.map_x, game->rays.map_y))
			game->rays.hit = 1;
	}
	return (side);
}

void	draw_a_ray_vector(t_game *game, int x)
{
	int		side;

	init_ray(game);
	side = perform_dda(game);
	calculate_and_draw(game, side, x);
}

void	draw_rays(t_game *game)
{
	int		x;
	float	camera_x;

	game->rays.dir_x = cos(deg_to_rad(game->player->angle));
	game->rays.dir_y = sin(deg_to_rad(game->player->angle));
	game->rays.plane_x = -game->rays.dir_y * tan(deg_to_rad(FOV / 2));
	game->rays.plane_y = game->rays.dir_x * tan(deg_to_rad(FOV / 2));
	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (float)WIDTH - 1;
		game->rays.ray_dir_x = game->rays.dir_x + game->rays.plane_x * camera_x;
		game->rays.ray_dir_y = game->rays.dir_y + game->rays.plane_y * camera_x;
		draw_a_ray_vector(game, x);
		x++;
	}
	draw_minimap(game);
}
