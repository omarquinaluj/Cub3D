/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:55:08 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/15 03:55:34 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../INCLUDES/cub3d.h"

static float	calculate_perp_dist(t_game *game, int side)
{
	float	perp_dist;

	if (side == 0)
		perp_dist = (game->rays.map_x - game->player_x
				+ (game->rays.step_x < 0))
			/ game->rays.ray_dir_x;
	else
		perp_dist = (game->rays.map_y - game->player_y
				+ (game->rays.step_y < 0))
			/ game->rays.ray_dir_y;
	if (perp_dist <= 0)
		perp_dist = 0.0001f;
	return (perp_dist);
}

static void	calculate_texture_x(t_game *game,
				float perp_dist, int side, int wall_plane)
{
	float	wall_x;
	int		texture_width;

	texture_width = game->info[wall_plane].width;
	if (side == 0)
		wall_x = game->player_y + perp_dist * game->rays.ray_dir_y;
	else
		wall_x = game->player_x + perp_dist * game->rays.ray_dir_x;
	wall_x -= floor(wall_x);
	game->rays.tex_x = (int)(wall_x * texture_width);
	if (game->rays.tex_x < 0)
		game->rays.tex_x = 0;
	if (game->rays.tex_x >= texture_width)
		game->rays.tex_x = texture_width - 1;
	if (side == 0)
	{
		if ((wall_plane == WEST && game->rays.step_x < 0)
			|| (wall_plane == EAST && game->rays.step_x > 0))
		{
			game->rays.tex_x = texture_width - game->rays.tex_x - 1;
		}
	}
	if (side == 1 && wall_plane == SOUTH && game->rays.step_y > 0)
		game->rays.tex_x = texture_width - game->rays.tex_x - 1;
}

static int	get_wall_plane(t_game *game, int side)
{
	if (side == 0)
	{
		if (game->rays.step_x < 0)
			return (WEST);
		return (EAST);
	}
	if (game->rays.step_y < 0)
		return (NORTH);
	return (SOUTH);
}

void	calculate_and_draw(t_game *game, int side, int x)
{
	float	perp_dist;
	int		wall_plane;

	perp_dist = calculate_perp_dist(game, side);
	game->rays.wall_height = (int)(HEIGHT / perp_dist);
	wall_plane = get_wall_plane(game, side);
	calculate_texture_x(game, perp_dist, side, wall_plane);
	draw_wall_line_2(game, x, wall_plane);
}
