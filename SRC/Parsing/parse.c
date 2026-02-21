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

void	init_cf(t_game *game)
{
	game->textures->celing[0] = -1;
	game->textures->celing[1] = -1;
	game->textures->celing[2] = -1;
	game->textures->celing[3] = 0;
	game->textures->floor[0] = -1;
	game->textures->floor[1] = -1;
	game->textures->floor[2] = -1;
	game->textures->floor[3] = 0;
}

int	check_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	check_permiss(t_game *game)
{
	if (check_open(game->textures->north))
		return (errors("Invalid north texture\n"));
	if (check_open(game->textures->south))
		return (errors("Invalid south texture\n"));
	if (check_open(game->textures->west))
		return (errors("Invalid west texture\n"));
	if (check_open(game->textures->east))
		return (errors("Invalid east texture\n"));
	return (0);
}

void	set_player_angle(t_game *game)
{
	if (game->player_dir == 'N')
		game->player->angle = 270;
	if (game->player_dir == 'S')
		game->player->angle = 90;
	if (game->player_dir == 'E')
		game->player->angle = 180;
	if (game->player_dir == 'W')
		game->player->angle = 0;
}

int	parse(t_game *game, char *argv)
{
	init_cf(game);
	if (check_cub(argv) == 1)
		return (1);
	if (open_save_all(argv, game, 0) == 1)
		return (1);
	if (check_textures(game) == 1)
		return (1);
	if (check_permiss(game) == 1)
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
	adjust_player_start(game);
	return (0);
}
