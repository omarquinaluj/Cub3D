/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:05:39 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/13 16:05:41 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

unsigned int	get_pixel_from_texture(int wall_plane, int texture_y,
					t_game *game)
{
	t_info	texture;
	char	*pixel_addr;

	if (wall_plane == NORTH)
		texture = game->info[0];
	else if (wall_plane == SOUTH)
		texture = game->info[1];
	else if (wall_plane == EAST)
		texture = game->info[2];
	else
		texture = game->info[3];
	if (game->rays.tex_x < 0)
		game->rays.tex_x = 0;
	if (game->rays.tex_x >= texture.width)
		game->rays.tex_x = texture.width - 1;
	if (texture_y < 0)
		texture_y = 0;
	if (texture_y >= texture.height)
		texture_y = texture.height - 1;
	pixel_addr = texture.data + (texture_y * texture.size_line)
		+ (game->rays.tex_x * (texture.bpp / 8));
	return (*(unsigned int *)pixel_addr);
}

void	draw_wall_line_2(t_game *game, int ray_iteration, int wall_plane)
{
	int		texture_y;
	t_info	texture;

	if (game->rays.wall_height <= 0)
		return ;
	game->rays.wall_y = (HEIGHT - game->rays.wall_height) / 2;
	game->rays.draw_i = 0;
	texture = game->info[wall_plane];
	if (game->rays.wall_y < 0)
	{
		game->rays.draw_i = -game->rays.wall_y;
		game->rays.wall_y = 0;
	}
	while (game->rays.draw_i < game->rays.wall_height
		&& game->rays.wall_y < HEIGHT)
	{
		texture_y = (int)((float)game->rays.draw_i / game->rays.wall_height
				* texture.height);
		if (texture_y >= texture.height)
			texture_y = texture.height - 1;
		put_pixel(ray_iteration, game->rays.wall_y,
			get_pixel_from_texture(wall_plane, texture_y, game), game);
		game->rays.wall_y++;
		game->rays.draw_i++;
	}
}
