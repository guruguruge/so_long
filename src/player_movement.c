/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 23:07:40 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-14 23:07:40 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	hit_wall(t_core *so_long)
{
	// display_map(so_long->map_info, so_long->mlx, so_long->win, so_long);
	mlx_do_sync(so_long->mlx);
}

void	move_forward(t_core *so_long, int new_x, int new_y)
{
	int	prev_x;
	int	prev_y;

	prev_x = so_long->player_x;
	prev_y = so_long->player_y;
	so_long->map_info.map[prev_y][prev_x] = FLOOR;
	display_chunk(so_long->map_info.map[prev_y][prev_x], so_long->mlx,
		so_long->win, so_long);
	so_long->map_info.map[new_y][new_x] = PLAYER;
	so_long->player_x = new_x;
	so_long->player_y = new_y;
	display_chunk(so_long->map_info.map[new_y][new_x], so_long->mlx,
		so_long->win, so_long);
	so_long->move_count++;
	ft_printf("Number of Movement %d\n", so_long->move_count);
}

void	move_and_collect(t_core *so_long, int new_x, int new_y)
{
	int	prev_x;
	int	prev_y;

	prev_x = so_long->player_x;
	prev_y = so_long->player_y;
	so_long->map_info.map[prev_y][prev_x] = FLOOR;
	display_chunk(so_long->map_info.map[prev_y][prev_x], so_long->mlx,
		so_long->win, so_long);
	so_long->map_info.map[new_y][new_x] = PLAYER;
	so_long->player_x = new_x;
	so_long->player_y = new_y;
	display_chunk(so_long->map_info.map[new_y][new_x], so_long->mlx,
		so_long->win, so_long);
	so_long->move_count++;
	ft_printf("Number of Movement %d\n", so_long->move_count);
}

void	move_to_door(t_core *so_long, int new_x, int new_y)
{
	int	prev_x;
	int	prev_y;

	if (game_clear(so_long))
	{
		prev_x = so_long->player_x;
		prev_y = so_long->player_y;
		so_long->map_info.map[prev_y][prev_x] = FLOOR;
		display_chunk(so_long->map_info.map[prev_y][prev_x], so_long->mlx,
			so_long->win, so_long);
		so_long->map_info.map[new_y][new_x] = PLAYER;
		so_long->player_x = new_x;
		so_long->player_y = new_y;
		display_chunk(so_long->map_info.map[new_y][new_x], so_long->mlx,
			so_long->win, so_long);
		so_long->move_count++;
		ft_printf("Number of Movement %d\n", so_long->move_count);
		end_game(so_long);
	}
	display_map(so_long->map_info, so_long->mlx, so_long->win, so_long);
	mlx_do_sync(so_long->mlx);
}
