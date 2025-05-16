/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 08:30:19 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-16 08:30:19 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	free_images(t_core *so_long)
{
	if (so_long->wall.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->wall.img_ptr);
	if (so_long->floor.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->floor.img_ptr);
	if (so_long->collect.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->collect.img_ptr);
	if (so_long->door.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->door.img_ptr);
	if (so_long->player1.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->player1.img_ptr);
	if (so_long->player2.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->player2.img_ptr);
	if (so_long->player3.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->player3.img_ptr);
	if (so_long->counter.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->counter.img_ptr);
	if (so_long->enemy1.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->enemy1.img_ptr);
	if (so_long->enemy2.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->enemy2.img_ptr);
	if (so_long->enemy3.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->enemy3.img_ptr);
	if (so_long->attack_hit.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->attack_hit.img_ptr);
	if (so_long->attack_miss.img_ptr)
		mlx_destroy_image(so_long->mlx, so_long->attack_miss.img_ptr);
}

void	free_all(t_core *so_long)
{
	free_map(so_long->map_info.map);
	free_images(so_long);
	if (so_long->win)
		mlx_destroy_window(so_long->mlx, so_long->win);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
}
