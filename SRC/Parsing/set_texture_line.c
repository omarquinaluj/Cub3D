/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:50:35 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/21 13:50:36 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	adjust_player_start(t_game *game)
{
	t_start	s;

	s.offset = 0.1f;
	s.map_x = (int)game->player_x;
	s.map_y = (int)game->player_y;
	if (game->player_dir == 'N')
		game->player_y += s.offset;
	else if (game->player_dir == 'S')
		game->player_y -= s.offset;
	else if (game->player_dir == 'E')
		game->player_x -= s.offset;
	else if (game->player_dir == 'W')
		game->player_x += s.offset;
	if (s.map_x > 0 && s.map_x < game->map_width - 1
		&& s.map_y > 0 && s.map_y < game->map_height - 1)
	{
		if (game->map[s.map_y][s.map_x - 1] == '1' && game->player_dir != 'E')
			game->player_x += s.offset;
		if (game->map[s.map_y][s.map_x + 1] == '1' && game->player_dir != 'W')
			game->player_x -= s.offset;
		if (game->map[s.map_y - 1][s.map_x] == '1' && game->player_dir != 'S')
			game->player_y += s.offset;
		if (game->map[s.map_y + 1][s.map_x] == '1' && game->player_dir != 'N')
			game->player_y -= s.offset;
	}
}

static int	set_wall_texture(char **splitted, t_game *game)
{
	if (!splitted[1] || splitted[2])
		return (errors("Incorrect textures\n"));
	if (!ft_strncmp(splitted[0], "NO", 2))
		game->textures->north = ft_strdup(splitted[1]);
	else if (!ft_strncmp(splitted[0], "SO", 2))
		game->textures->south = ft_strdup(splitted[1]);
	else if (!ft_strncmp(splitted[0], "EA", 2))
		game->textures->east = ft_strdup(splitted[1]);
	else if (!ft_strncmp(splitted[0], "WE", 2))
		game->textures->west = ft_strdup(splitted[1]);
	return (0);
}

static int	set_color_texture(char *line, t_game *game)
{
	char	*value;

	value = line + 1;
	while (*value == ' ')
		value++;
	if (*value == '\0')
		return (errors("Incorrect color\n"));
	if (*line == 'C')
	{
		if (game->textures->celing[3] == 1)
			return (errors("More than one celing\n"));
		if (parse_rgb(value, game->textures->celing) == -1)
			return (errors("Celing not correct\n"));
		game->textures->celing[3] = 1;
	}
	else
	{
		if (game->textures->floor[3] == 1)
			return (errors("More than one floor\n"));
		if (parse_rgb(value, game->textures->floor) == -1)
			return (errors("Floor not correct\n"));
		game->textures->floor[3] = 1;
	}
	return (0);
}

int	set_texture_line(char *line, t_game *game)
{
	char	**splitted;
	int		ret;

	splitted = ft_split(line, ' ');
	if (!splitted || !splitted[0])
		return (free_matrix(splitted), 1);
	if ((!ft_strncmp(splitted[0], "NO", 2)
			|| !ft_strncmp(splitted[0], "SO", 2)
			|| !ft_strncmp(splitted[0], "EA", 2)
			|| !ft_strncmp(splitted[0], "WE", 2))
		&& ft_strlen(splitted[0]) == 2)
		ret = set_wall_texture(splitted, game);
	else if ((!ft_strncmp(splitted[0], "C", 1)
			|| !ft_strncmp(splitted[0], "F", 1))
		&& ft_strlen(splitted[0]) == 1)
		ret = set_color_texture(line, game);
	else
		ret = 0;
	free_matrix(splitted);
	return (ret);
}
