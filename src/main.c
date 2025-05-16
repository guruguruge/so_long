/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 14:20:26 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-14 14:20:26 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

void	print_error(int error_type)
{
	ft_printf("Error\n");
	if (error_type == INVALID_INPUT)
		ft_printf("Invalid input\n");
	else if (error_type == INVALID_MAP)
		ft_printf("Invalid map\n");
	else if (error_type == INVALID_FILE)
		ft_printf("Invalid file\n");
	else if (error_type == FAIL_DISPLAY)
		ft_printf("Failed display\n");
	else if (error_type == MALLOC_FAIL)
		ft_printf("Malloc fail\n");
	exit(ERROR);
}

// void	check_map(char *map_name)
// {
// 	char	**map;

// 	map = convert_map(map_name);
// 	if (valid_walls(map))
// 		print_error(INVALID_MAP);
// 	else if (valid_collectables(map))
// 		print_error(INVALID_MAP);
// 	else if (valid_start_goal(map))
// 		print_error(INVALID_MAP);
// }

t_map	handle_map(char *map_name)
{
	char	**map;
	int		height;
	int		width;
	t_map	map_info;

	height = preview_map(map_name);
	map = convert_map(map_name, height);
	width = ft_strlen(map[0]);
	map_info = init_map(map, width, height);
	// validate_map(map_info, map_name);
	return (map_info);
}

int	main(int argc, char **argv)
{
	t_map	map_info;

	if (argc != 2)
		print_error(INVALID_INPUT);
	map_info = handle_map(argv[1]);
	mlx(map_info);
	return (0);
}
