/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:05:53 by hkang             #+#    #+#             */
/*   Updated: 2017/12/11 13:43:12 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_draw_line(int *a, int *b, t_map *map)
{
	map->color = map->color_base - a[2] * map->dcolor;
	mlx_pixel_put(map->mlx, map->win, a[0], a[1], map->color);
	if (a[0] == b[0] && a[1] != b[1])
		ft_draw_vertical(a, b, map);
	else if (a[0] != b[0] && a[1] == b[1])
		ft_draw_horizon(a, b, map);
	else if (a[0] != b[0] && a[1] != b[1])
		ft_draw_slope(a, b, map);
}

void	ft_draw_slope(int *a, int *b, t_map *map)
{
	float	k;
	float	k2;
	int		f;
	int		c[3];

	c[0] = a[0];
	c[1] = a[1];
	c[2] = a[2];
	f = 1;
	k = (float)(b[0] - a[0]) / (float)(b[1] - a[1]);
	k2 = (float)(b[2] - a[2]) / (float)(b[1] - a[1]);
	if (b[1] < a[1])
		f = -1;
	while (c[1] != b[1])
	{
		c[1] += f;
		c[0] = (int)((float)a[0] + k * (float)(c[1] - a[1]));
		c[2] = (int)((float)a[2] + k2 * (float)(c[1] - a[1]));
		map->color = map->color_base - c[2] * map->dcolor;
		mlx_pixel_put(map->mlx, map->win, c[0], c[1], map->color);
	}
}

void	ft_draw_horizon(int *a, int *b, t_map *map)
{
	float	k;
	int		f;
	int		c[3];

	c[0] = a[0];
	c[1] = a[1];
	c[2] = a[2];
	f = 1;
	k = (float)(b[2] - a[2]) / (float)(b[0] - a[0]);
	if (b[0] < a[0])
		f = -1;
	while (c[0] != a[0])
	{
		c[0] += f;
		c[2] = (int)((float)a[2] + k * (float)(c[0] - a[0]));
		map->color = map->color_base - c[2] * map->dcolor;
		mlx_pixel_put(map->mlx, map->win, c[0], c[1], map->color);
	}
}

void	ft_draw_vertical(int *a, int *b, t_map *map)
{
	float	k;
	int		f;
	int		c[3];

	c[0] = a[0];
	c[1] = a[1];
	c[2] = a[2];
	f = 1;
	k = (float)(b[2] - a[2]) / (float)(b[1] - a[1]);
	if (b[1] < a[1])
		f = -1;
	while (c[1] != b[1])
	{
		c[1] += f;
		c[2] = (int)((float)a[2] + k * (float)(c[1] - b[1]));
		map->color = map->color_base - c[2] * map->dcolor;
		mlx_pixel_put(map->mlx, map->win, c[0], c[1], map->color);
	}
}

void	ft_strtoint(char **str, t_map *map)
{
	char	**temp;
	int		i;

	i = 0;
	while (str[i])
		i++;
	map->res = (int**)malloc(sizeof(int*) * i);
	while (str[map->y])
	{
		temp = ft_strsplit(str[map->y], ' ');
		i = 0;
		while (temp[i])
			i++;
		map->res[map->y] = (int*)malloc(sizeof(int) * (i));
		map->x = 0;
		while (map->x < i)
		{
			map->res[map->y][map->x] = ft_atoi(temp[map->x]);
			get_min_max(map->res[map->y][map->x], map);
			(map->x)++;
		}
		(map->y)++;
	}
}
