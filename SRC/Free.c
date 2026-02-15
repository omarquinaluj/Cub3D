/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:33:37 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/12 23:03:53 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	more_free(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
	if (game->player)
		free(game->player);
	if (game->mlx)
		free(game->mlx);
}

void	free_structure(t_game *game)
{
	if (game->textures)
	{
		if (game->textures->north)
			free(game->textures->north);
		if (game->textures->south)
			free(game->textures->south);
		if (game->textures->east)
			free(game->textures->east);
		if (game->textures->west)
			free(game->textures->west);
		free(game->textures);
	}
	if (game->is_map)
		free(game->is_map);
	if (game->is_texture)
		free(game->is_texture);
	more_free(game);
}

int	do_destroy_window(t_game *game)
{
	mlx_clear_window(game->mlx->mlx, game->mlx->mlx_win);
	mlx_destroy_image(game->mlx->mlx, game->mlx->img);
	mlx_destroy_window(game->mlx->mlx, game->mlx->mlx_win);
	if (game->info[0].img)
		mlx_destroy_image(game->mlx->mlx, game->info[0].img);
	if (game->info[1].img)
		mlx_destroy_image(game->mlx->mlx, game->info[1].img);
	if (game->info[2].img)
		mlx_destroy_image(game->mlx->mlx, game->info[2].img);
	if (game->info[3].img)
		mlx_destroy_image(game->mlx->mlx, game->info[3].img);
	mlx_destroy_display(game->mlx->mlx);
	free(game->mlx->mlx);
	free_structure(game);
	exit(0);
	return (0);
}

void	free_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
