#include "../../INCLUDES/cub3d.h"

void	key_up(t_game *game, float speed)
{
	float	new_x;
	float	new_y;

	new_x = game->player_x + game->player->delta_x * speed;
	new_y = game->player_y + game->player->delta_y * speed;

	if (game->map[(int)game->player_y][(int)new_x] != '1')
		game->player_x = new_x;
	if (game->map[(int)new_y][(int)game->player_x] != '1')
		game->player_y = new_y;
}

void	key_down(t_game *game, float speed)
{
	float	new_x;
	float	new_y;

	new_x = game->player_x - game->player->delta_x * speed;
	new_y = game->player_y - game->player->delta_y * speed;

	if (game->map[(int)game->player_y][(int)new_x] != '1')
		game->player_x = new_x;
	if (game->map[(int)new_y][(int)game->player_x] != '1')
		game->player_y = new_y;
}

void	key_left(t_game *game, float speed)
{
	float	new_x;
	float	new_y;

	new_x = game->player_x + game->player->delta_y * speed;
	new_y = game->player_y - game->player->delta_x * speed;

	if (game->map[(int)game->player_y][(int)new_x] != '1')
		game->player_x = new_x;
	if (game->map[(int)new_y][(int)game->player_x] != '1')
		game->player_y = new_y;
}

void	key_right(t_game *game, float speed)
{
	float	new_x;
	float	new_y;

	new_x = game->player_x - game->player->delta_y * speed;
	new_y = game->player_y + game->player->delta_x * speed;

	if (game->map[(int)game->player_y][(int)new_x] != '1')
		game->player_x = new_x;
	if (game->map[(int)new_y][(int)game->player_x] != '1')
		game->player_y = new_y;
}
