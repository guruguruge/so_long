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
    while ()
    {
        /* code */
    }
    
}

void	validate_playability(t_map map_info);
void	validate_size(t_map map_info);
void	validate_filename(char *map_name)
{
}

void	validate_map(t_map map_info, char *map_name)
{
	validate_componets(map_info);
	validate_shape(map_info);
	validate_playability(map_info);
}