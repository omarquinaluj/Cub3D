#include "../../INCLUDES/cub3d.h"

unsigned int get_pixel_from_texture(int wall_plane, int texture_x, int texture_y, t_game *game)
{
	t_info texture;
	char *pixel_addr;

	if (wall_plane == NORTH)
		texture = game->info[0];
	else if (wall_plane == SOUTH)
		texture = game->info[1];
	else if (wall_plane == EAST)
		texture = game->info[2];
	else
		texture = game->info[3];
	if (texture_x < 0)
		texture_x = 0;
	if (texture_x >= texture.width)
		texture_x = texture.width - 1;
	if (texture_y < 0)
		texture_y = 0;
	if (texture_y >= texture.height)
		texture_y = texture.height - 1;
	pixel_addr = texture.data + (texture_y * texture.size_line) + (texture_x * (texture.bpp / 8));
	return (*(unsigned int *)pixel_addr);
}

static void	draw_wall_line(t_game *game, int ray_iteration, int wall_height,
	int wall_plane, int tex_x)
{
	if (wall_height <= 0)
		return;

	int		wall_y = (HEIGHT - wall_height) / 2;
	int		i = 0;
	int		texture_y;
	t_info	texture = game->info[wall_plane];

	if (wall_y < 0)
	{
		i = -wall_y;
		wall_y = 0;
	}

	while (i < wall_height && wall_y < HEIGHT)
	{
		texture_y = (int)((float)i / wall_height * texture.height);
		if (texture_y >= texture.height)
			texture_y = texture.height - 1;
		put_pixel(ray_iteration, wall_y,
			get_pixel_from_texture(wall_plane, tex_x, texture_y, game),
			game);
		wall_y++;
		i++;
	}
}

void	is_north(int tex_x, int ray_iteration, int wall_height, t_game *game)
{
	draw_wall_line(game, ray_iteration, wall_height, NORTH, tex_x);
}

void	is_south(int tex_x, int ray_iteration, int wall_height, t_game *game)
{
	draw_wall_line(game, ray_iteration, wall_height, SOUTH, tex_x);
}

void	is_east(int tex_x, int ray_iteration, int wall_height, t_game *game)
{
	draw_wall_line(game, ray_iteration, wall_height, EAST, tex_x);
}

void	is_west(int tex_x, int ray_iteration, int wall_height, t_game *game)
{
	draw_wall_line(game, ray_iteration, wall_height, WEST, tex_x);
}
