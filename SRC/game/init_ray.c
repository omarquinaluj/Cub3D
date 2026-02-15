/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 04:04:47 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/15 04:04:49 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

static void	init_ray_position(t_game *game)
{
	game->rays.map_x = (int)game->player_x;
	game->rays.map_y = (int)game->player_y;
}

static void	init_ray_delta(t_game *game)
{
	if (game->rays.ray_dir_x == 0)
		game->rays.delta_dist_x = 1e30;
	else
		game->rays.delta_dist_x = fabs(1
				/ game->rays.ray_dir_x);
	if (game->rays.ray_dir_y == 0)
		game->rays.delta_dist_y = 1e30;
	else
		game->rays.delta_dist_y = fabs(1
				/ game->rays.ray_dir_y);
}

static void	init_ray_step_x(t_game *game)
{
	if (game->rays.ray_dir_x < 0)
	{
		game->rays.step_x = -1;
		game->rays.side_dist_x = (game->player_x
				- game->rays.map_x)
			* game->rays.delta_dist_x;
	}
	else
	{
		game->rays.step_x = 1;
		game->rays.side_dist_x = (game->rays.map_x + 1.0
				- game->player_x)
			* game->rays.delta_dist_x;
	}
}

static void	init_ray_step_y(t_game *game)
{
	if (game->rays.ray_dir_y < 0)
	{
		game->rays.step_y = -1;
		game->rays.side_dist_y = (game->player_y
				- game->rays.map_y)
			* game->rays.delta_dist_y;
	}
	else
	{
		game->rays.step_y = 1;
		game->rays.side_dist_y = (game->rays.map_y + 1.0
				- game->player_y)
			* game->rays.delta_dist_y;
	}
}

void	init_ray(t_game *game)
{
	init_ray_position(game);
	init_ray_delta(game);
	init_ray_step_x(game);
	init_ray_step_y(game);
}
