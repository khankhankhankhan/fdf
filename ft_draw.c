/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:37:12 by huakang           #+#    #+#             */
/*   Updated: 2017/12/11 13:38:21 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_draw(char **new_file, t_map *map)
{
	ft_strtoint(new_file, map);
	ft_calc_map(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width, map->hight, map->title);
	ft_display(map);
}

void	ft_display(t_map *map)
{
	int i;
	int j;

	j = 0;
	while (j < map->y)
	{
		i = 0;
		while (i < map->x)
		{
			if (j > 0)
				ft_draw_xline(map->res, i, j, map);
			if (i > 0)
				ft_draw_yline(map->res, i, j, map);
			i++;
		}
		j++;
	}
}

void	ft_draw_xline(int **res, int i, int j, t_map *map)
{
	int temp[2][3];

	temp[0][2] = res[j - 1][i];
	temp[0][0] = map->offsetx + i * map->dx + (j - 1) * map->dy -
				res[j - 1][i] / map->divid;
	temp[0][1] = map->offsety - i * map->dx + (j - 1) * map->dy -
				res[j - 1][i] * map->multy;
	temp[1][2] = res[j][i];
	temp[1][0] = map->offsetx + i * map->dx + j * map->dy -
				res[j][i] / map->divid;
	temp[1][1] = map->offsety - i * map->dx + j * map->dy -
				res[j][i] * map->multy;
	ft_draw_line(temp[0], temp[1], map);
}

void	ft_draw_yline(int **res, int i, int j, t_map *map)
{
	int temp[2][3];

	temp[0][2] = res[j][i - 1];
	temp[0][0] = map->offsetx + (i - 1) * map->dx + j * map->dy -
				res[j][i - 1] / map->divid;
	temp[0][1] = map->offsety - (i - 1) * map->dx + j * map->dy -
				res[j][i - 1] * map->multy;
	temp[1][2] = res[j][i];
	temp[1][0] = map->offsetx + i * map->dx + j * map->dy -
				res[j][i] / map->divid;
	temp[1][1] = map->offsety - i * map->dx + j * map->dy -
				res[j][i] * map->multy;
	ft_draw_line(temp[0], temp[1], map);
}
