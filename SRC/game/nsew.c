/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsew.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:06:25 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/14 21:06:26 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	is_north(int ray_iteration, t_game *game)
{
	draw_wall_line_2(game, ray_iteration, NORTH);
}

void	is_south(int ray_iteration, t_game *game)
{
	draw_wall_line_2(game, ray_iteration, SOUTH);
}

void	is_east(int ray_iteration, t_game *game)
{
	draw_wall_line_2(game, ray_iteration, EAST);
}

void	is_west_2(int ray_iteration, t_game *game)
{
	draw_wall_line_2(game, ray_iteration, WEST);
}
