/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:55:27 by owmarqui          #+#    #+#             */
/*   Updated: 2025/12/09 10:55:29 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <stdint.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h> //printf, perror
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //close, read, write
# include <fcntl.h> //open
# include <string.h> //strerror
# include <sys/time.h> //gettimeofday
# include <math.h>

# define MARGIN 0.05f

# define TILE_SIZE 8

# define WIDTH 1280
# define HEIGHT 1200
# define PI 3.1415926535897932384626433832
# define FOV 60
# define STEP 0.01

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

typedef struct s_point
{
	float	x;
	float	y;
}			t_point;

typedef struct s_info
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}			t_info;

typedef struct s_player
{
	float	angle;
	float	delta_x;
	float	delta_y;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}				t_player;

typedef struct s_rays
{
	float	dir_x;
	float	dir_y;
	float	ray_dir_x;
	float	ray_dir_y;
	float	plane_x;
	float	plane_y;
	int		map_x;
	int		map_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	int		tex_x;
	int		hit;
	int		wall_height;
	int		wall_y;
	int		draw_i;

}			t_rays;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_mlx;

typedef struct s_start
{
	float	offset;
	int		map_x;
	int		map_y;
}			t_start;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor[4];
	int		celing[4];
}			t_textures;

typedef struct s_game
{
	char		*is_map;
	char		*is_texture;
	char		**map;
	int			map_open;
	int			map_width;
	int			map_height;
	char		player_dir;
	float		player_x;
	float		player_y;
	t_rays		rays;		
	t_textures	*textures;
	t_mlx		*mlx;
	t_player	*player;
	t_info		info[4];
}				t_game;

//MAIN
int				errors(char	*str);

//PARSE
int				parse(t_game *game, char *argv);
int				set_texture_line(char *line, t_game *game);
void			adjust_player_start(t_game *game);
int				check_cub(char *argv);
int				open_save_all(char *argv, t_game *game, int temp);
void			free_matrix(char **matrix);
int				check_textures(t_game *game);
int				check_map(t_game *game);
int				rectangular_map(t_game *game);
void			free_structure(t_game *game);
int				check_colors(char **split_line, t_game *game);

//RENDER
int				render_map(t_game *game);
int				do_destroy_window(t_game *game);
int				key_release(int key, t_game *game);
int				key_press(int key, t_game *game);
int				move_player(t_game *game);
float			deg_to_rad(float angle);
void			draw_rays(t_game *game);
void			put_pixel(int x, int y, int color, t_game *game);
void			key_up(t_game *game, float speed);
void			key_down(t_game *game, float speed);
void			key_left(t_game *game, float speed);
void			key_right(t_game *game, float speed);

void			is_north(int ray_iteration, t_game *game);
void			is_south(int ray_iteration, t_game *game);
void			is_east(int ray_iteration, t_game *game);
void			is_west(int ray_iteration, t_game *game);
void			put_pixel(int x, int y, int color, t_game *game);

float			fix_ang(float angle);
void			clear_image(t_game *game);

int				validate_map(t_game *game);
int				check_spaces(t_game *game);
char			**duplicate_map(char **map);
unsigned int	get_pixel_from_texture(int wall_plane, int texture_y,
					t_game *game);
void			draw_wall_line_2(t_game *game, int ray_iteration,
					int wall_plane);
void			calculate_and_draw(t_game *game, int side, int x);
void			init_ray(t_game *game);

int				parse_rgb(char *line, int rgb[3]);

//MINIMAP
void			draw_minimap(t_game *game);

#endif