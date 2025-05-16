/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pregame_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 08:36:35 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-16 08:36:35 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	get_images_one(void *mlx, t_core *so_long)
{
	t_path	p;
	int		n;

	n = 64;
	p.wall = "./textures/wall.xpm";
	p.floor = "./textures/floor.xpm";
	p.collect = "./textures/collectible.xpm";
	p.door = "./textures/door.xpm";
	p.counter = "./textures/counter.xpm";
	so_long->wall.img_ptr = mlx_xpm_file_to_image(mlx, p.wall, &n, &n);
	so_long->floor.img_ptr = mlx_xpm_file_to_image(mlx, p.floor, &n, &n);
	so_long->collect.img_ptr = mlx_xpm_file_to_image(mlx, p.collect, &n, &n);
	so_long->door.img_ptr = mlx_xpm_file_to_image(mlx, p.door, &n, &n);
	so_long->counter.img_ptr = mlx_xpm_file_to_image(mlx, p.counter, &n, &n);
	get_images_two(mlx, so_long);
	image_error_check(so_long);
}

void	get_images_two(void *mlx, t_core *so_long)
{
	t_path	p;
	int		n;

	n = 64;
	p.player1 = "./textures/player1.xpm";
	p.player2 = "./textures/player2.xpm";
	p.player3 = "./textures/player3.xpm";
	p.enemy1 = "./textures/enemy1.xpm";
	p.enemy2 = "./textures/enemy2.xpm";
	p.enemy3 = "./textures/enemy3.xpm";
	so_long->player1.img_ptr = mlx_xpm_file_to_image(mlx, p.player1, &n, &n);
	so_long->player2.img_ptr = mlx_xpm_file_to_image(mlx, p.player2, &n, &n);
	so_long->player3.img_ptr = mlx_xpm_file_to_image(mlx, p.player3, &n, &n);
	so_long->enemy1.img_ptr = mlx_xpm_file_to_image(mlx, p.enemy1, &n, &n);
	so_long->enemy2.img_ptr = mlx_xpm_file_to_image(mlx, p.enemy2, &n, &n);
	so_long->enemy3.img_ptr = mlx_xpm_file_to_image(mlx, p.enemy3, &n, &n);
	get_images_three(mlx, so_long);
	image_error_check(so_long);
}

void	get_images_three(void *mlx, t_core *so_long)
{
	t_path	p;
	int		n;

	n = 64;
	p.attack_hit = "./textures/attack_hit.xpm";
	p.attack_miss = "./textures/attack_miss.xpm";
	so_long->attack_hit.img_ptr = mlx_xpm_file_to_image(mlx, p.attack_hit, &n,
			&n);
	so_long->attack_miss.img_ptr = mlx_xpm_file_to_image(mlx, p.attack_miss, &n,
			&n);
	image_error_check(so_long);
}

void	init_core(t_map map_info, t_core *so_long)
{
	so_long->mlx = NULL;
	so_long->toggle = 0;
	so_long->move_count = 0;
	so_long->enemy.hit = 0;
	so_long->map_info.map = map_info.map;
	so_long->map_info.height = map_info.height;
	so_long->map_info.width = map_info.width;
	find_enemy(map_info, so_long);
	so_long->enemy.route = check_rout(so_long);
}

t_map	init_map(char **map, int width, int height)
{
	t_map	map_info;

	map_info.map = map;
	map_info.width = width;
	map_info.height = height;
	return (map_info);
}

void	reinit_core(t_map map_info, t_core *so_long, void *mlx, void *mlx_win)
{
	find_player(map_info, so_long);
	find_enemy(map_info, so_long);
	so_long->map_info = map_info;
	so_long->map_info.height = map_info.height;
	so_long->map_info.width = map_info.width;
	so_long->win = mlx_win;
	so_long->mlx = mlx;
}
