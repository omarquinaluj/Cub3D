/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owmarqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:49:08 by owmarqui          #+#    #+#             */
/*   Updated: 2026/02/14 19:49:09 by owmarqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

int	check_line(char *line)
{
	int	comma;
	int	i;

	comma = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (-1);
	return (0);
}

static int	parse_number(char *line, int *i)
{
	int	n;

	n = 0;
	if (!(line[*i] >= '0' && line[*i] <= '9'))
		return (-1);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		n = n * 10 + (line[*i] - '0');
		if (n > 255)
			return (-1);
		(*i)++;
	}
	return (n);
}

int	parse_rgb(char *line, int rgb[3])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] && count < 3)
	{
		while (line[i] == ' ')
			i++;
		rgb[count] = parse_number(line, &i);
		if (rgb[count] == -1)
			return (-1);
		count++;
		while (line[i] == ' ')
			i++;
		if (count < 3)
		{
			if (line[i] != ',')
				return (-1);
			i++;
		}
	}
	if (count != 3 || line[i] != '\0')
		return (-1);
	return (0);
}

int	color(char **split_line)
{
	if ((!ft_strncmp(split_line[0], "F", 1)
			|| !ft_strncmp(split_line[0], "C", 1))
		&& ft_strlen(split_line[0]) == 1)
	{
		if (!split_line[1])
			return (errors("Colors aren't written correctly\n"));
	}
	return (0);
}

int	check_colors(char **split_line, t_game *game)
{
	if (color(split_line) == 1)
		return (1);
	if (!ft_strncmp(split_line[0], "C", 1)
		&& ft_strlen(split_line[0]) == 1)
	{
		if (game->textures->celing[3] == 1)
			return (errors("More than one celing\n"));
		if (parse_rgb(split_line[1], game->textures->celing) == -1)
			return (errors("Celing not correct\n"));
		game->textures->celing[3] = 1;
	}
	if (!ft_strncmp(split_line[0], "F", 1)
		&& ft_strlen(split_line[0]) == 1)
	{
		if (game->textures->floor[3] == 1)
			return (errors("More than one floor\n"));
		if (parse_rgb(split_line[1], game->textures->floor) == -1)
			return (errors("Floor not correct\n"));
		game->textures->floor[3] = 1;
	}
	return (0);
}
