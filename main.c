/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:46:30 by hkang             #+#    #+#             */
/*   Updated: 2017/12/06 11:46:33 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"
void ft_map_init(t_map *map)
{
	map->width = 0;
	map->hight = 0;
	map->offsetx = 0;
	map->offsety = 0;
	map->dx = 12;
	map->dy = 8;
	map->divid = 10;
	map->multy = 20;
	map->min_x = 100000;
	map->min_y = 100000;
	map->max_x = -100000;
	map->max_y = -100000;
	map->x = 0;
	map->y = 0;
	map->color = 0x00FFFFFF;
}

int			main(int ac, char **av)
{
	char **new_file;
	t_map *map;

	if (ac != 2)
  {
    write(1, "Error\n", 6);
		return (0);
  }
	map = (t_map*)malloc(sizeof(t_map));
	ft_map_init(map);
	new_file = ft_read_file(av[1]);
	map->title = ft_strjoin("FDF - ", av[1]);
	ft_draw(new_file, map);
	mlx_key_hook(map->win, ft_key_hook, map);
	mlx_loop(map->mlx);
	return (0);
}
