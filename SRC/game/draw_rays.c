#include "../../INCLUDES/cub3d.h"
#include <math.h>

// Devuelve true si la celda es pared
int	is_a_block(t_game *game, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0 || map_x >= game->map_width || map_y >= game->map_height)
		return (1);
	return (game->map[map_y][map_x] == '1');
}

// Calcula el color de un pixel
void	put_pixel(int x, int y, int color, t_game *game)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	((unsigned int *)game->mlx->data)[y * (game->mlx->size_line / 4) + x] = color;
}

// Obtener color de la textura de forma segura


// Dibujar una columna de pared usando textura
static void draw_wall_line(t_game *game, int x, int wall_height, int wall_plane, int tex_x)
{
	if (wall_height <= 0)
		return;

	int wall_y = (HEIGHT - wall_height) / 2;
	int i = 0;
	t_info texture = game->info[wall_plane];
	int texture_y;

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

		put_pixel(x, wall_y, get_pixel_from_texture(wall_plane, tex_x, texture_y, game), game);
		i++;
		wall_y++;
	}
}

// Dibuja un rayo individual
void draw_a_ray_vector(t_game *game, float ray_dir_x, float ray_dir_y, int x)
{
	float px = game->player_x;
	float py = game->player_y;
	int map_x = (int)px;
	int map_y = (int)py;

	float delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
	float delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

	int step_x, step_y;
	float side_dist_x, side_dist_y;

	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (px - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - px) * delta_dist_x;
	}

	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (py - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - py) * delta_dist_y;
	}

	int hit = 0;
	int side;

	while (!hit)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}

		if (is_a_block(game, map_x, map_y))
			hit = 1;
	}

	// Distancia perpendicular al plano de la cámara
	float perp_dist;
	if (side == 0)
		perp_dist = (map_x - px + (step_x < 0 ? 1 : 0)) / ray_dir_x;
	else
		perp_dist = (map_y - py + (step_y < 0 ? 1 : 0)) / ray_dir_y;

	if (perp_dist <= 0)
		perp_dist = 0.0001;

	int wall_height = (int)(HEIGHT / perp_dist);

	// Coordenada de la textura horizontal
	float wall_x = (side == 0) ? py + perp_dist * ray_dir_y : px + perp_dist * ray_dir_x;
	wall_x -= floor(wall_x);
	int tex_x = (int)(wall_x * game->info[NORTH].width);
	if (tex_x >= game->info[NORTH].width)
		tex_x = game->info[NORTH].width - 1;

	int wall_plane;
	if (side == 0)
		wall_plane = (step_x < 0) ? WEST : EAST;
	else
		wall_plane = (step_y < 0) ? NORTH : SOUTH;

	draw_wall_line(game, x, wall_height, wall_plane, tex_x);
}

// Dibuja todos los rayos
void draw_rays(t_game *game)
{
	int x;
	float dir_x = cos(deg_to_rad(game->player->angle));
	float dir_y = sin(deg_to_rad(game->player->angle));

	float plane_x = -dir_y * tan(deg_to_rad(FOV / 2));
	float plane_y =  dir_x * tan(deg_to_rad(FOV / 2));

	for (x = 0; x < WIDTH; x++)
	{
		float camera_x = 2 * x / (float)WIDTH - 1;
		float ray_dir_x = dir_x + plane_x * camera_x;
		float ray_dir_y = dir_y + plane_y * camera_x;

		draw_a_ray_vector(game, ray_dir_x, ray_dir_y, x);
	}
}

