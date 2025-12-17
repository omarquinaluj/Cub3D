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

#ifndef	CUB3D_H
# define CUB3D_H

# include "../MLX/mlx.h"
# include "Libft/libft.h"

# include <stdint.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h> //printf, perror
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //close, read, write
# include <fcntl.h> //open
# include <string.h> //strerror
# include <sys/time.h>
# include <math.h>

typedef struct s_game
{
	char		*is_map;
	char		*is_texture;
	char		**map;
	int			map_width;
	int			map_height;
	char		player_dir;
	float		player_x;
	float		player_y;
	t_textures	*textures;
	t_mlx		*mlx;
	t_player	*player;
	t_info		info[4];
}				t_game;

//M_error
int	errors(char *str);