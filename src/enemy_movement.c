/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemt_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 00:23:50 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-16 00:23:50 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	enemy_movement(t_core *so_long)
{
	if (so_long->enemy.route == VERTICAL)
	{
		if (so_long->enemy.direction == UP)
		{
			if (enemy_move_up(so_long) == NOT_POSSIBLE)
				so_long->enemy.direction = DOWN;
		}
		else if (so_long->enemy.direction == DOWN)
		{
			if (enemy_move_down(so_long) == NOT_POSSIBLE)
				so_long->enemy.direction = UP;
		}
	}
	else if (so_long->enemy.route == HORIZONTAL)
	{
		if (so_long->enemy.direction == LEFT)
		{
			if (enemy_move_left(so_long) == NOT_POSSIBLE)
				so_long->enemy.direction = RIGHT;
		}
		else if (so_long->enemy.direction == RIGHT)
		{
			if (enemy_move_right(so_long) == NOT_POSSIBLE)
				so_long->enemy.direction = LEFT;
		}
	}
}

int	enemy_move_up(t_core *so_long)
{
	int	new_x;
	int	new_y;
	int	prev_x;
	int	prev_y;

	new_x = so_long->enemy.x;
	new_y = so_long->enemy.y - 1;
	if (so_long->map_info.map[new_y][new_x] == WALL)
		return (NOT_POSSIBLE);
	if (so_long->map_info.map[new_y][new_x] == PLAYER)
		end_game(so_long);
	prev_x = so_long->enemy.x;
	prev_y = so_long->enemy.y;
	so_long->map_info.map[prev_y][prev_x] = FLOOR;
	display_chunk_two(so_long->map_info.map[prev_y][prev_x], so_long->mlx,
		so_long->win, so_long);
	so_long->map_info.map[new_y][new_x] = ENEMY;
	so_long->enemy.x = new_x;
	so_long->enemy.y = new_y;
	if (did_attack_hit(so_long))
		enemy_dies(so_long->map_info.map[new_y][new_x], so_long->mlx,
			so_long->win, so_long);
	display_chunk_two(so_long->map_info.map[new_y][new_x], so_long->mlx,
		so_long->win, so_long);
	return (POSSIBLE);
}

int	enemy_move_left(t_core *so_long)
{
	int	new_x;
	int	new_y;
	int	prev_x;
	int	prev_y;

	new_x = so_long->enemy.x - 1;
	new_y = so_long->enemy.y;
	if (so_long->map_info.map[new_y][new_x] == WALL)
		return (NOT_POSSIBLE);
	if (so_long->map_info.map[new_y][new_x] == PLAYER)
		end_game(so_long);
	prev_x = so_long->enemy.x;
	prev_y = so_long->enemy.y;
	so_long->map_info.map[prev_y][prev_x] = FLOOR;
	display_chunk_two(so_long->map_info.map[prev_y][prev_x], so_long->mlx,
		so_long->win, so_long);
	so_long->map_info.map[new_y][new_x] = ENEMY;
	so_long->enemy.x = new_x;
	so_long->enemy.y = new_y;
	display_chunk_two(so_long->map_info.map[new_y][new_x], so_long->mlx,
		so_long->win, so_long);
	return (POSSIBLE);
}

int	enemy_move_down(t_core *so_long)
{
	int	new_x;
	int	new_y;
	int	prev_x;
	int	prev_y;

	new_x = so_long->enemy.x;
	new_y = so_long->enemy.y + 1;
	if (so_long->map_info.map[new_y][new_x] == WALL)
		return (NOT_POSSIBLE);
	if (so_long->map_info.map[new_y][new_x] == PLAYER)
		end_game(so_long);
	prev_x = so_long->enemy.x;
	prev_y = so_long->enemy.y;
	so_long->map_info.map[prev_y][prev_x] = FLOOR;
	display_chunk_two(so_long->map_info.map[prev_y][prev_x], so_long->mlx,
		so_long->win, so_long);
	so_long->map_info.map[new_y][new_x] = ENEMY;
	so_long->enemy.x = new_x;
	so_long->enemy.y = new_y;
	display_chunk_two(so_long->map_info.map[new_y][new_x], so_long->mlx,
		so_long->win, so_long);
	return (POSSIBLE);
}

int	enemy_move_right(t_core *so_long)
{
	int	new_x;
	int	new_y;
	int	prev_x;
	int	prev_y;

	new_x = so_long->enemy.x + 1;
	new_y = so_long->enemy.y;
	if (so_long->map_info.map[new_y][new_x] == WALL)
		return (NOT_POSSIBLE);
	if (so_long->map_info.map[new_y][new_x] == PLAYER)
		end_game(so_long);
	prev_x = so_long->enemy.x;
	prev_y = so_long->enemy.y;
	so_long->map_info.map[prev_y][prev_x] = FLOOR;
	display_chunk_two(so_long->map_info.map[prev_y][prev_x], so_long->mlx,
		so_long->win, so_long);
	so_long->map_info.map[new_y][new_x] = ENEMY;
	so_long->enemy.x = new_x;
	so_long->enemy.y = new_y;
	display_chunk_two(so_long->map_info.map[new_y][new_x], so_long->mlx,
		so_long->win, so_long);
	return (POSSIBLE);
}

int	did_attack_hit(t_core *so_long)
{
	int	x;
	int	y;

	x = so_long->attack_x;
	y = so_long->attack_y;
	if (so_long->attack_state)
	{
		if ((x == so_long->enemy.x) && (y == so_long->enemy.y))
			return (1);
	}
	else
		return (0);
	return (0);
}

void	enemy_dies(char c, void *mlx, void *mlx_win, t_core *so_long)
{
	int x;
	int y;

	y = (64 * so_long->enemy.y + 100);
	x = (64 * so_long->enemy.x + 100);
	if (c == ENEMY && so_long->enemy.hit == 1)
		mlx_put_image_to_window(mlx, mlx_win, so_long->attack_hit.img_ptr, x,
			y);
	mlx_do_sync(mlx);
}