/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:09:56 by hkang             #+#    #+#             */
/*   Updated: 2017/12/11 12:19:33 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	get_min_max(int n, t_map *map)
{
	int x;
	int y;

	x = map->x * map->dx + map->y * map->dy - n / map->divid;
	y = map->y * map->dy - map->x * map->dx - n * map->multy;
	if (x > map->max_x)
		map->max_x = x;
	if (x < map->min_x)
		map->min_x = x;
	if (y > map->max_y)
		map->max_y = y;
	if (y < map->min_y)
		map->min_y = y;
}

void	ft_calc_map(t_map *map)
{
	if (map->min_x >= 0)
		map->offsetx = (map->max_x - map->min_x) / 10;
	else
		map->offsetx = (map->max_x - map->min_x) / 10 - map->min_x;
	if (map->min_y >= 0)
		map->offsety = (map->max_y - map->min_y) / 10;
	else
		map->offsety = (map->max_y - map->min_y) / 10 - map->min_y;
	map->width = (map->max_x - map->min_x) + (map->max_x - map->min_x) / 5;
	map->hight = (map->max_y - map->min_y) + (map->max_y - map->min_y) / 5;
	while (map->hight > 1000 || map->width > 2000)
	{
		map->offsety = map->offsety / 2;
		map->dy = map->dy / 2;
		map->multy = map->multy / 2;
		map->hight = map->hight / 2;
		map->offsetx = map->offsetx / 2;
		map->dx = map->dx / 2;
		map->divid = map->divid * 2;
		map->width = map->width / 2;
	}
}
