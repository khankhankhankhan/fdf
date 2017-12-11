/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:46:30 by hkang             #+#    #+#             */
/*   Updated: 2017/12/11 12:21:43 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_map_init(t_map *map)
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
	map->color_base = 0x00FFFFFF;
	map->dcolor = 12000;
}

int		main(int ac, char **av)
{
	char	**new_file;
	t_map	*map;
	char	*comment;

	if (ac != 2)
	{
		write(1, "usage: ./fdf target_file\n", 25);
		return (0);
	}
	comment = "use i/o to zoom in/out\nuse arrows to move\npress esc to exit\n";
	write(1, comment, ft_strlen(comment));
	map = (t_map*)malloc(sizeof(t_map));
	ft_map_init(map);
	new_file = ft_read_file(av[1]);
	map->title = ft_strjoin("FDF - ", av[1]);
	ft_draw(new_file, map);
	mlx_key_hook(map->win, ft_key_hook, map);
	mlx_loop(map->mlx);
	return (0);
}
