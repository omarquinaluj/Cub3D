#include "../../INCLUDES/cub3d.h"

float	deg_to_rad(float angle)
{
	return (angle * PI / 180.0);
}

float	fix_ang(float angle)
{
	if (angle > 359)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

int	argb_to_int(int a, int r, int g, int b)
{
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

void	clear_image(t_game *game)
{
	int	y;
	int	x;
	int	celing;
	int	floor;

	floor = (int)((255 << 24) | (game->textures->floor[0] << 16)
			| (game->textures->floor[1] << 8) | game->textures->floor[2]);
	celing = (int)((255 << 24) | (game->textures->celing[0] << 16)
			| (game->textures->celing[1] << 8) | game->textures->celing[2]);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel(x, y, celing, game);
			else
				put_pixel(x, y, floor, game);
			x++;
		}
		y++;
	}
}
