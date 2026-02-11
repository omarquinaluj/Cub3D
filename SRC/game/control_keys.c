#include "../../INCLUDES/cub3d.h"

int	key_release(int key, t_game *game)
{
	if (key == ESC)
		do_destroy_window(game);
	if (key == W)
		game->player->key_up = false;
	if (key == A)
		game->player->key_left = false;
	if (key == S)
		game->player->key_down = false;
	if (key == D)
		game->player->key_right = false;
	if (key == LEFT)
		game->player->left_rotate = false;
	if (key == RIGHT)
		game->player->right_rotate = false;
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		do_destroy_window(game);
	if (key == W)
		game->player->key_up = true;
	if (key == A)
		game->player->key_left = true;
	if (key == S)
		game->player->key_down = true;
	if (key == D)
		game->player->key_right = true;
	if (key == LEFT)
		game->player->left_rotate = true;
	if (key == RIGHT)
		game->player->right_rotate = true;
	return (0);
}

int	move_player(t_game *game)
{
	float	speed;
	int		rotation_speed;

	speed = 0.2;
	rotation_speed = 4;
	if (game->player->right_rotate)
		game->player->angle += rotation_speed;
	if (game->player->left_rotate)
		game->player->angle -= rotation_speed;
	game->player->angle = fix_ang(game->player->angle);
	game->player->delta_x = cos(deg_to_rad(game->player->angle));
	game->player->delta_y = sin(deg_to_rad(game->player->angle));
	if (game->player->key_up)
		key_up(game, speed);
	if (game->player->key_down)
		key_down(game, speed);
	if (game->player->key_left)
		key_left(game, speed);
	if (game->player->key_right)
		key_right(game, speed);
	clear_image(game);
	draw_rays(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->mlx_win,
		game->mlx->img, 0, 0);
	return (0);
}