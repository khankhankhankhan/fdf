/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:50:13 by hkang             #+#    #+#             */
/*   Updated: 2017/12/11 13:50:03 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# define BUFF_SIZE 20

/*
**	Key code
*/
# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_ZOOM_IN 31
# define KEY_ZOOM_OUT 34

typedef struct	s_map
{
	void	*mlx;
	void	*win;
	char	*title;
	int		**res;
	int		width;
	int		hight;
	int		offsetx;
	int		offsety;
	int		dx;
	int		dy;
	int		divid;
	int		multy;
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
	int		x;
	int		y;
	int		color;
	int		color_base;
	int		dcolor;
}				t_map;

void			ft_map_init(t_map *map);
void			ft_draw(char **new_file, t_map *map);
void			ft_display(t_map *map);
void			ft_draw_xline(int **res, int i, int j, t_map *map);
void			ft_draw_yline(int **res, int i, int j, t_map *map);
void			ft_draw_line(int *a, int *b, t_map *map);
void			ft_draw_slope(int *a, int *b, t_map *map);
void			ft_draw_horizon(int *a, int *b, t_map *map);
void			ft_draw_vertical(int *a, int *b, t_map *map);

void			ft_strtoint(char **str, t_map *map);
void			get_min_max(int n, t_map *map);
void			ft_calc_map(t_map *map);
char			**ft_read_file(char *file);

int				ft_key_hook(int keycode, t_map *map);
void			ft_map_move(int keycode, t_map *map);
void			ft_map_zoom(int keycode, t_map *map);
void			ft_cal_zoom(t_map *map, int n);
#endif
