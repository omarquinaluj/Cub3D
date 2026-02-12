#include "../../INCLUDES/cub3d.h"

char	**duplicate_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = ft_calloc(i + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_matrix(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	flood_fill(char **map, int y, int x, t_game *game)
{
	if (y < 0 || x < 0
		|| y >= game->map_height
		|| x >= game->map_width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == ' ')
	{
		game->map_open = 1;
		return ;
	}
	map[y][x] = 'F';
	flood_fill(map, y + 1, x, game);
	flood_fill(map, y - 1, x, game);
	flood_fill(map, y, x + 1, game);
	flood_fill(map, y, x - 1, game);
}

int	validate_map(t_game *game)
{
	char	**copy;

	copy = duplicate_map(game->map);
	if (!copy)
		return (0);
	game->map_open = 0;
	flood_fill(copy, game->player_y, game->player_x, game);
	free_matrix(copy);
	if (game->map_open)
		return (0);
	return (1);
}
