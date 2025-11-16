/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pregame_validation_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-31 09:21:05 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-31 09:21:05 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	validate_walls(t_map map_info)
{
	size_t	i;

	i = 0;
	while (i < map_info.width - 1)
	{
		if (map_info.map[0][i] != '1')
			print_error2(INVALID_MAP, map_info);
		if (map_info.map[map_info.height - 1][i] != '1')
			print_error2(INVALID_MAP, map_info);
		i++;
	}
	i = 0;
	while (i < map_info.height - 1)
	{
		if (map_info.map[i][0] != '1')
			print_error2(INVALID_MAP, map_info);
		if (map_info.map[i][map_info.width - 2] != '1')
			print_error2(INVALID_MAP, map_info);
		i++;
	}
}

void	validate_shape(t_map map_info)
{
	size_t	i;

	i = 0;
	while (i < map_info.height - 1)
	{
		if (ft_strlen(map_info.map[i]) != map_info.width)
			print_error2(INVALID_MAP, map_info);
		i++;
	}
	if (map_info.map[i][map_info.width - 1] == '\n')
	{
		if (ft_strlen(map_info.map[i]) != map_info.width)
			print_error2(INVALID_MAP, map_info);
	}
	else
	{
		if (ft_strlen(map_info.map[i]) != map_info.width - 1)
			print_error2(INVALID_MAP, map_info);
	}
}

void	validate_collectible_player(t_map map_info, char *map_name)
{
	t_point	size;
	t_point	current;
	char	*targets;
	t_map	temp_map;

	targets = "0CEP";
	size.y = map_info.height;
	size.x = map_info.width;
	get_init_point(&current, size, map_info, targets);
	temp_map.map = convert_map(map_name, map_info.height);
	fill(temp_map.map, size, current, targets);
	temp_map.height = map_info.height;
	temp_map.width = map_info.width;
	if (find_element(temp_map, COLLECT) || find_element(temp_map, DOOR)
		|| find_element(temp_map, PLAYER))
	{
		free_map(temp_map.map);
		print_error2(INVALID_MAP, map_info);
	}
	free_map(temp_map.map);
}

void	validate_size(t_map map_info)
{
	if (map_info.height > 16 || map_info.width > 31)
		print_error2(INVALID_MAP, map_info);
}

void	validate_playability(t_map map_info, char *map_name)
{
	validate_walls(map_info);
	validate_collectible_player(map_info, map_name);
}
