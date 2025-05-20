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
	int	x;
	int	y;
	int	found;

	y = 0;
	found = 0;
	while (y < map_info.height)
	{
		x = 0;
		while (x < map_info.width)
		{
			if (map_info.map[y][x] == c)
			{
				found++;
				break ;
			}
			x++;
		}
		y++;
	}
	return (found);
}

void	validate_componets(t_map map_info)
{
	if (find_element(map_info, PLAYER) != 1)
		print_error(INVALID_MAP);
	if (find_element(map_info, DOOR) != 1)
		print_error(INVALID_MAP);
	if (find_element(map_info, ENEMY) != 1)
		print_error(INVALID_MAP);
	if (find_element(map_info, COLLECT) > 0)
		print_error(INVALID_MAP);
	if (find_element(map_info, WALL) > 0)
		print_error(INVALID_MAP);
	if (find_element(map_info, FLOOR) > 0)
		print_error(INVALID_MAP);
}

void	validate_shape(t_map map_info)
{
	int	i;

	i = 0;
	while (i < map_info.height)
	{
		if (ft_strlen(map_info.map[i]) != map_info.width)
			print_error(INVALID_MAP);
		i++;
	}
}

void	validate_walls(t_map map_info)
{
	int	i;

	i = 0;
	while (i < map_info.width)
	{
		if (map_info.map[0][i] != '1')
			print_error(INVALID_MAP);
		if (map_info.map[0][map_info.height] != '1')
			print_error(INVALID_MAP);
		i++;
	}
	i = 0;
	while (i < map_info.height)
	{
		if (map_info.map[i][0] != '1')
			print_error(INVALID_MAP);
		if (map_info.map[i][map_info.width] != '1')
			print_error(INVALID_MAP);
		i++;
	}
}

typedef struct s_point
{
	int x; // x : Width  | x-axis
	int y; // y : Height | y-axis
}		t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

void	validate_collectible(t_map map_info)
{
}

void	validate_playability(t_map map_info)
{
	valdate_walls(map_info);
	validate_collectible(map_info);
	validate_player(map_info);
	validate_enemy(map_info);
}

void	validate_size(t_map map_info)
{
	if (map_info.height > 12 || map_info.width > 26)
		print_error(INVALID_MAP);
}

void	validate_filename(char *map_name)
{
	size_t	i;

	i = ft_strlen(map_name);
	if (ft_strncmp((*map_name + i - 4), ".ber", 4))
		print_error(INVALID_MAP);
}

void	validate_map(t_map map_info, char *map_name)
{
	validate_filename(map_name);
	validate_componets(map_info);
	validate_shape(map_info);
	validate_playability(map_info);
	validate_size(map_info);
}
