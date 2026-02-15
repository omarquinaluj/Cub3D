/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:50:28 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/14 19:50:29 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	set_player_angle(t_game *game)
{
	if (game->player_dir == 'N')
		game->player->angle = 90;
	if (game->player_dir == 'S')
		game->player->angle = 270;
	if (game->player_dir == 'E')
		game->player->angle = 0;
	if (game->player_dir == 'W')
		game->player->angle = 180;
}

int	parse(t_game *game, char *argv)
{
	if (check_cub(argv) == 1)
		return (1);
	if (open_save_all(argv, game, 0) == 1)
		return (1);
	if (check_textures(game) == 1)
		return (1);
	if (check_map(game) == 1)
		return (1);
	if (rectangular_map(game) == 1)
		return (1);
	if (!check_spaces(game))
		return (errors("Map open (spaces)\n"));
	if (!validate_map(game))
		return (errors("Map not closed\n"));
	set_player_angle(game);
	return (0);
}
