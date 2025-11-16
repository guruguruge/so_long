/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pregame_validation_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-22 22:36:26 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-22 22:36:26 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/so_long.h"

int	in_targets(char c, char *targets)
{
	size_t	i;

	i = 0;
	while (targets[i])
	{
		if (c == targets[i])
			return (1);
		i++;
	}
	return (0);
}

void	fill(char **tab, t_point size, t_point cur, char *targets)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| !in_targets(tab[cur.y][cur.x], targets))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, targets);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, targets);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, targets);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, targets);
}

void	get_init_point(t_point *init, t_point size, t_map map_info,
		char *target)
{
	size_t	x;
	size_t	y;
	int		found;

	y = 0;
	found = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (in_targets(map_info.map[y][x], target))
			{
				init->x = x;
				init->y = y;
				found = 1;
				break ;
			}
			x++;
		}
		if (found)
			break ;
		y++;
	}
}

char	**cpy_map(char **original, size_t height)
{
	char	**copy;
	size_t	i;

	if (!original)
		return (NULL);
	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}
