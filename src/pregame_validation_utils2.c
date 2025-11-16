/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 14:32:12 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-14 14:32:12 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

int	find_element(t_map map_info, char c)
{
	size_t	x;
	size_t	y;
	int		found;

	y = 0;
	found = 0;
	while (y < map_info.height)
	{
		x = 0;
		while (x < map_info.width)
		{
			if (map_info.map[y][x] == c)
				found++;
			x++;
		}
		y++;
	}
	return (found);
}

int	find_invalid_element(t_map map_info)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_info.height)
	{
		x = 0;
		while (x < map_info.width)
		{
			if (((map_info.map[y][x] == '\n') || (map_info.map[y][x] == '\0'))
				&& x + 1 == map_info.width)
			{
				x++;
				break ;
			}
			if (!in_targets(map_info.map[y][x], "01EPXC"))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	validate_componets(t_map map_info)
{
	if (find_element(map_info, PLAYER) != 1)
		print_error2(INVALID_MAP, map_info);
	if (find_element(map_info, DOOR) != 1)
		print_error2(INVALID_MAP, map_info);
	if (find_element(map_info, ENEMY) != 1)
		print_error2(INVALID_MAP, map_info);
	if (!find_element(map_info, COLLECT))
		print_error2(INVALID_MAP, map_info);
	if (!find_element(map_info, WALL))
		print_error2(INVALID_MAP, map_info);
	if (!find_element(map_info, FLOOR))
		print_error2(INVALID_MAP, map_info);
	if (find_invalid_element(map_info))
		print_error2(INVALID_MAP, map_info);
}

void	validate_filename(t_map map_info, char *map_name)
{
	size_t	i;

	i = ft_strlen(map_name);
	if (i < 4 || ft_strncmp((map_name + i - 4), ".ber", 4) != 0)
		print_error2(INVALID_MAP, map_info);
}

void	validate_map(t_map map_info, char *map_name)
{
	validate_filename(map_info, map_name);
	validate_componets(map_info);
	validate_shape(map_info);
	validate_playability(map_info, map_name);
	validate_size(map_info);
}
