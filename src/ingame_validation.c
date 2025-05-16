/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 08:33:20 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-16 08:33:20 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	find_player(t_map map_info, t_core *so_long)
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
			if (map_info.map[y][x] == PLAYER)
			{
				so_long->player_x = x;
				so_long->player_y = y;
				found = 1;
				break ;
			}
			x++;
		}
		if (found)
			break ;
		y++;
	}
	so_long->player_x = x;
	so_long->player_y = y;
}

void	find_enemy(t_map map_info, t_core *so_long)
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
			if (map_info.map[y][x] == ENEMY)
			{
				so_long->enemy.x = x;
				so_long->enemy.y = y;
				found = 1;
				break ;
			}
			x++;
		}
		if (found)
			break ;
		y++;
	}
	so_long->enemy.x = x;
	so_long->enemy.y = y;
}

int	game_clear(t_core *so_long)
{
	if (is_map_complete(so_long->map_info.map, so_long))
		return (COMPLETE);
	else
		return (NOT_COMPLETE);
}

int	is_map_complete(char **map, t_core *so_long)
{
	int	x;
	int	y;
	int	found;

	y = 0;
	found = 0;
	while (y < so_long->map_info.height)
	{
		x = 0;
		while (x < so_long->map_info.width)
		{
			if (map[y][x] == COLLECT)
				return (NOT_COMPLETE);
			x++;
		}
		y++;
	}
	return (COMPLETE);
}

int	check_rout(t_core *so_long)
{
	int	y;
	int	x;

	y = so_long->enemy.y;
	x = so_long->enemy.x;
	if (so_long->map_info.map[y + 1][x] != WALL || so_long->map_info.map[y
		- 1][x] != WALL)
	{
		so_long->enemy.direction = UP;
		return (VERTICAL);
	}
	else if (so_long->map_info.map[y][x + 1] != WALL
		|| so_long->map_info.map[y][x - 1] != WALL)
	{
		so_long->enemy.direction = LEFT;
		return (HORIZONTAL);
	}
	return (ERROR);
}

void	image_error_check(t_core *so_long)
{
	if (!so_long->wall.img_ptr || !so_long->floor.img_ptr)
		print_error(FAIL_DISPLAY);
	if (!so_long->collect.img_ptr || !so_long->counter.img_ptr)
		print_error(FAIL_DISPLAY);
	if (!so_long->player1.img_ptr || !so_long->player2.img_ptr)
		print_error(FAIL_DISPLAY);
	if (!so_long->player3.img_ptr || !so_long->door.img_ptr)
		print_error(FAIL_DISPLAY);
}
