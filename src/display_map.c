/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 14:48:15 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-14 14:48:15 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	*display_window(void *mlx)
{
	return (mlx_new_window(mlx, 1000, 1000, "so_long"));
}

void	display_map(t_map map_info, void *mlx, void *mlx_win, t_core *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_info.height)
	{
		x = 0;
		while (x < map_info.width)
		{
			print_chunk(map_info.map[y][x], (64 * x + 100), (64 * y + 100), mlx,
				mlx_win, so_long);
			x++;
		}
		y++;
	}
	mlx_do_sync(mlx);
}

void	display_chunk(char c, void *mlx, void *mlx_win, t_core *so_long)
{
	int	print_x;
	int	print_y;

	print_y = (64 * so_long->player_y + 100);
	print_x = (64 * so_long->player_x + 100);
	if (!so_long->toggle)
		so_long->toggle = 1;
	else if (so_long->toggle > 0)
		so_long->toggle = -1;
	else if (so_long->toggle < 0)
		so_long->toggle = 0;
	print_chunk(c, print_x, print_y, mlx, mlx_win, so_long);
	print_move_count(so_long);
	mlx_do_sync(mlx);
}

void	print_chunk(char c, int x, int y, void *mlx, void *mlx_w, t_core *so_lg)
{
	if (c == WALL)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->wall.img_ptr, x, y);
	if (c == FLOOR)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->floor.img_ptr, x, y);
	if (c == COLLECT)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->collect.img_ptr, x, y);
	if (c == DOOR)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->door.img_ptr, x, y);
	if (c == ENEMY)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->enemy1.img_ptr, x, y);
	if (c == ENEMY && so_lg->toggle < 0)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->enemy3.img_ptr, x, y);
	if (c == PLAYER && so_lg->toggle > 0)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->player1.img_ptr, x, y);
	if (c == PLAYER && so_lg->toggle == 0)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->player2.img_ptr, x, y);
	if (c == PLAYER && so_lg->toggle < 0)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->player3.img_ptr, x, y);
}

void	print_chunk_two(char c, int x, int y, void *mlx, void *mlx_w,
		t_core *so_lg)
{
	if (c == FLOOR && so_lg->enemy.hit == -1)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->attack_miss.img_ptr, x, y);
	if (c == ENEMY && so_lg->enemy.hit == 1)
		mlx_put_image_to_window(mlx, mlx_w, so_lg->attack_hit.img_ptr, x, y);
}

void	display_chunk_two(char c, void *mlx, void *mlx_win, t_core *so_long)
{
	int	print_x;
	int	print_y;

	print_y = (64 * (so_long->enemy.y) + 100);
	print_x = (64 * so_long->enemy.x + 100);
	if (!so_long->toggle)
		so_long->toggle = 1;
	else if (so_long->toggle > 0)
		so_long->toggle = -1;
	else if (so_long->toggle < 0)
		so_long->toggle = 0;
	if (so_long->enemy.hit)
		print_chunk_two(c, print_x, print_y, mlx, mlx_win, so_long);
	print_chunk(c, print_x, print_y, mlx, mlx_win, so_long);
	print_move_count(so_long);
	mlx_do_sync(mlx);
}

void	display_chunk_three(char c, void *mlx, void *mlx_win, t_core *so_long)
{
	int	print_x;
	int	print_y;

	print_y = (64 * (so_long->attack_y) + 100);
	print_x = (64 * so_long->attack_x + 100);
	print_chunk_two(c, print_x, print_y, mlx, mlx_win, so_long);
	mlx_do_sync(mlx);
}

void	print_move_count(t_core *so_long)
{
	char	*move_count;
	char	*line;

	line = "Number of Movement";
	if (!so_long || !so_long->mlx || !so_long->win)
		return ;
	move_count = ft_itoa(so_long->move_count);
	if (!move_count)
		return ;
	mlx_put_image_to_window(so_long->mlx, so_long->win,
		so_long->counter.img_ptr, 0, 0);
	mlx_string_put(so_long->mlx, so_long->win, 10, 10, 0xFF0000, line);
	mlx_string_put(so_long->mlx, so_long->win, 10, 50, 0xFF0000, move_count);
	free(move_count);
}

void	mlx(t_map map_info)
{
	void	*mlx;
	void	*mlx_win;
	t_core	*so_long;

	so_long = malloc(sizeof(t_core));
	if (!so_long)
		print_error(MALLOC_FAIL);
	init_core(map_info, so_long);
	mlx = mlx_init();
	if (!mlx)
		print_error(FAIL_DISPLAY);
	get_images_one(mlx, so_long);
	mlx_win = display_window(mlx);
	display_map(so_long->map_info, mlx, mlx_win, so_long);
	player_movement(so_long->map_info, mlx, mlx_win, so_long);
	mlx_loop(mlx);
	free(so_long->mlx);
	if (so_long->mlx)
		mlx_destroy_display(so_long->mlx);
	exit(0);
}
