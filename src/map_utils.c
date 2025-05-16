/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 17:04:55 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-14 17:04:55 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

int	preview_map(char *map_name)
{
	int		fd;
	int		height;
	char	*line;
	int		i;

	line = "init";
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		print_error(INVALID_FILE);
	height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

char	**convert_map(char *map_name, int height)
{
	int		fd;
	char	*line;
	int		i;
	char	**map_array;

	map_array = malloc(sizeof(char *) * (height + 1));
	if (!map_array)
	{
		free_map(map_array);
		close(fd);
		return (NULL);
	}
	fd = open(map_name, O_RDONLY);
	i = 0;
	map_array[height] = NULL;
	while (i < height)
	{
		map_array[i] = get_next_line(fd);
		if (!map_array[i])
		{
			free_map(map_array);
			close(fd);
			return (NULL);
		}
		i++;
	}
	close(fd);
	return (map_array);
}
