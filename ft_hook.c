/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:43:31 by huakang           #+#    #+#             */
/*   Updated: 2017/12/11 13:39:26 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	ft_map_move(keycode, map);
	ft_map_zoom(keycode, map);
	return (0);
}

void	ft_map_move(int keycode, t_map *map)
{
	if (keycode == KEY_UP)
		map->offsety--;
	else if (keycode == KEY_DOWN)
		map->offsety++;
	else if (keycode == KEY_LEFT)
		map->offsetx--;
	else if (keycode == KEY_RIGHT)
		map->offsetx++;
	if (keycode == KEY_UP || keycode == KEY_DOWN ||
			keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		mlx_clear_window(map->mlx, map->win);
		ft_display(map);
	}
}

void	ft_map_zoom(int keycode, t_map *map)
{
	if (keycode == KEY_ZOOM_IN)
		ft_cal_zoom(map, 1);
	else if (keycode == KEY_ZOOM_OUT)
		ft_cal_zoom(map, -1);
}

void	ft_cal_zoom(t_map *map, int n)
{
	if (map->dx + n > 0 && map->dy + n > 0 && map->divid - n > 1)
	{
		map->dx += n;
		map->divid -= n;
		map->dy += n;
		map->multy += n;
		map->offsetx -= n * map->x / 2;
		map->offsety += n * map->y / 2;
	}
	mlx_clear_window(map->mlx, map->win);
	ft_display(map);
}
