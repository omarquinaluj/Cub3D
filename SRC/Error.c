#include "../INCLUDES/cub3d.h"

int	errors(char	*str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	return (1);
}