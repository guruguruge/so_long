/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 18:54:08 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-16 18:54:08 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	note_attack(int key, t_core *so_long);
void	draw_attack_effect(t_core *so_long);
void	check_attack_hit(t_core *so_long);

void	note_attack(int key, t_core *so_long)
{
	int	px;
	int	py;

	px = so_long->player_x;
	py = so_long->player_y;
	if (key == ATTACK_U)
	{
		so_long->attack_x = px;
		so_long->attack_y = py - 1;
	}
	else if (key == ATTACK_D)
	{
		so_long->attack_x = px;
		so_long->attack_y = py + 1;
	}
	else if (key == ATTACK_L)
	{
		so_long->attack_x = px - 1;
		so_long->attack_y = py;
	}
	else if (key == ATTACK_R)
	{
		so_long->attack_x = px + 1;
		so_long->attack_y = py;
	}
	so_long->attack_state = 1;
	so_long->attack_frame = 0;
}

void	draw_attack_effect(t_core *so_long)
{
	if (so_long->attack_dir == UP)
		attack_up(so_long);
	else if (so_long->attack_dir == DOWN)
		attack_down(so_long);
	if (so_long->attack_dir == LEFT)
		attack_left(so_long);
	if (so_long->attack_dir == RIGHT)
		attack_right(so_long);
}

void	attack_up(t_core *so_long)
{
	int	x;
	int	y;

	x = so_long->player_x;
	y = so_long->player_y - 1;
	so_long->attack_x = x;
	so_long->attack_y = y;
	if (so_long->map_info.map[y][x] == WALL)
		display_map(so_long->map_info, so_long->mlx, so_long->win, so_long);
	if (so_long->map_info.map[y][x] == FLOOR)
		display_chunk_three(so_long->map_info.map[y][x], so_long->mlx,
			so_long->win, so_long);
}

void	attack_left(t_core *so_long)
{
	int	x;
	int	y;

	x = so_long->player_x - 1;
	y = so_long->player_y;
	so_long->attack_x = x;
	so_long->attack_y = y;
	if (so_long->map_info.map[y][x] == WALL)
		display_map(so_long->map_info, so_long->mlx, so_long->win, so_long);
	if (so_long->map_info.map[y][x] == FLOOR)
		display_chunk_three(so_long->map_info.map[y][x], so_long->mlx,
			so_long->win, so_long);
}

void	attack_down(t_core *so_long)
{
	int	x;
	int	y;

	x = so_long->player_x;
	y = so_long->player_y + 1;
	so_long->attack_x = x;
	so_long->attack_y = y;
	if (so_long->map_info.map[y][x] == WALL)
		display_map(so_long->map_info, so_long->mlx, so_long->win, so_long);
	if (so_long->map_info.map[y][x] == FLOOR)
		display_chunk_three(so_long->map_info.map[y][x], so_long->mlx,
			so_long->win, so_long);
}

void	attack_right(t_core *so_long)
{
	int	x;
	int	y;

	x = so_long->player_x + 1;
	y = so_long->player_y;
	so_long->attack_x = x;
	so_long->attack_y = y;
	if (so_long->map_info.map[y][x] == WALL)
		display_map(so_long->map_info, so_long->mlx, so_long->win, so_long);
	if (so_long->map_info.map[y][x] == FLOOR)
		display_chunk_three(so_long->map_info.map[y][x], so_long->mlx,
			so_long->win, so_long);
}

void	check_attack_hit(t_core *so_long)
{
	int		x;
	int		y;
	char	**map;

	x = so_long->attack_x;
	y = so_long->attack_y;
	map = so_long->map_info.map;
	if (map[y][x] == ENEMY)
		so_long->enemy.hit = 1;
	else if (map[y][x] == FLOOR)
	{
		so_long->enemy.hit = -1;
		display_chunk_three(so_long->map_info.map[y][x], so_long->mlx,
			so_long->win, so_long);
	}
}
