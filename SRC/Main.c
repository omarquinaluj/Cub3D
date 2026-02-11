#include "../INCLUDES/cub3d.h"

void	init_structure(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->textures = ft_calloc(1, sizeof(t_textures));
	game->mlx = ft_calloc(1, sizeof(t_mlx));
	game->player = ft_calloc(1, sizeof(t_player));
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (errors("Add only one argument ended in .cub\n"));
	init_structure(&game);
	if (parse(&game, argv[1]) == 1)
	{
		free_structure(&game);
		return (1);
	}
	if (render_map(&game) == 1)
	{
		free_structure(&game);
		return (1);
	}
	free_structure(&game);
}