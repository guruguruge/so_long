/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-15 00:08:18 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-15 00:08:18 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	movement_up(int key, t_core *so_long)
{
	int	new_x;
	int	new_y;

	new_x = so_long->player_x;
	new_y = so_long->player_y - 1;
	if (so_long->map_info.map[new_y][new_x] == WALL)
		hit_wall(so_long);
	else if (so_long->map_info.map[new_y][new_x] == FLOOR)
		move_forward(so_long, new_x, new_y);
	else if (so_long->map_info.map[new_y][new_x] == COLLECT)
		move_and_collect(so_long, new_x, new_y);
	else if (so_long->map_info.map[new_y][new_x] == DOOR)
		move_to_door(so_long, new_x, new_y);
}

void	movement_left(int key, t_core *so_long)
{
	int	new_x;
	int	new_y;

	new_x = so_long->player_x - 1;
	new_y = so_long->player_y;
	if (so_long->map_info.map[new_y][new_x] == WALL)
		hit_wall(so_long);
	else if (so_long->map_info.map[new_y][new_x] == FLOOR)
		move_forward(so_long, new_x, new_y);
	else if (so_long->map_info.map[new_y][new_x] == COLLECT)
		move_and_collect(so_long, new_x, new_y);
	else if (so_long->map_info.map[new_y][new_x] == DOOR)
		move_to_door(so_long, new_x, new_y);
}

void	movement_down(int key, t_core *so_long)
{
	int	new_x;
	int	new_y;

	new_x = so_long->player_x;
	new_y = so_long->player_y + 1;
	if (so_long->map_info.map[new_y][new_x] == WALL)
		hit_wall(so_long);
	else if (so_long->map_info.map[new_y][new_x] == FLOOR)
		move_forward(so_long, new_x, new_y);
	else if (so_long->map_info.map[new_y][new_x] == COLLECT)
		move_and_collect(so_long, new_x, new_y);
	else if (so_long->map_info.map[new_y][new_x] == DOOR)
		move_to_door(so_long, new_x, new_y);
}

void	movement_right(int key, t_core *so_long)
{
	int	new_x;
	int	new_y;

	new_x = so_long->player_x + 1;
	new_y = so_long->player_y;
	if (so_long->map_info.map[new_y][new_x] == WALL)
		hit_wall(so_long);
	else if (so_long->map_info.map[new_y][new_x] == FLOOR)
		move_forward(so_long, new_x, new_y);
	else if (so_long->map_info.map[new_y][new_x] == COLLECT)
		move_and_collect(so_long, new_x, new_y);
	else if (so_long->map_info.map[new_y][new_x] == DOOR)
		move_to_door(so_long, new_x, new_y);
}
