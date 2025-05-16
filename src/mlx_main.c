/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 08:31:31 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-16 08:31:31 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

int	render(void *so_long_void)
{
	t_core			*so_long;
	static size_t	frame = 0;

	so_long = (t_core *)so_long_void;
	if (++frame >= 9000)
	{
		enemy_movement(so_long);
		frame = 0;
	}
	if (so_long->attack_state)
	{
		draw_attack_effect(so_long);
		if (++so_long->attack_frame >= 1000)
		{
			so_long->attack_state = 0;
			check_attack_hit(so_long);
		}
	}
	return (0);
}

int	handle_key_input(int key, void *so_long_void)
{
	t_core	*so_long;

	so_long = (t_core *)so_long_void;
	if (key == W)
		movement_up(key, so_long);
	else if (key == A)
		movement_left(key, so_long);
	else if (key == S)
		movement_down(key, so_long);
	else if (key == D)
		movement_right(key, so_long);
	else if (key == ATTACK_U || key == ATTACK_D)
		note_attack(key, so_long);
	else if (key == ATTACK_U || key == ATTACK_D)
		note_attack(key, so_long);
	else if (key == ESC)
		end_game(so_long);
	return (0);
}

void	end_game(t_core *so_long)
{
	free_all(so_long);
	free(so_long);
	exit(0);
}

int	close_window(void *so_long_void)
{
	t_core	*so_long;

	so_long = (t_core *)so_long_void;
	free_all(so_long);
	exit(0);
	return (0);
}

void	player_movement(t_map map_info, void *mlx, void *mlx_win,
		t_core *so_long)
{
	reinit_core(map_info, so_long, mlx, mlx_win);
	mlx_hook(mlx_win, 2, 1L << 0, handle_key_input, so_long);
	mlx_loop_hook(mlx, render, so_long);
	mlx_hook(mlx_win, 17, 0, close_window, so_long);
}
