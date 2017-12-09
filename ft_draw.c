/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:37:12 by huakang           #+#    #+#             */
/*   Updated: 2017/12/06 19:37:35 by huakang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void ft_draw(char **new_file, t_map *map)
{
  int **res;
  res = ft_strtoint(new_file, map);
  ft_calc_map(map);
  map->mlx = mlx_init();
  map->win = mlx_new_window(map->mlx, map->width, map->hight, map->title);
  ft_display(res, map);
  mlx_loop(map->mlx);
}

void ft_display(int **res, t_map *map)
{
  int i;
  int j;

  j = 0;
  while(j < map->y)
  {
    i = 0;
    while(i < map->x)
    {
      if(j > 0)
        ft_draw_xline(res, i, j, map);
      if(i > 0)
        ft_draw_yline(res, i, j, map);
      i++;
    }
    j++;
  }
}

void ft_draw_xline(int **res, int i, int j, t_map *map)
{
    int temp[2][3];
    temp[0][2] = res[j - 1][i];
    temp[0][0] = map->offsetx + i * map->dx + (j - 1) * map->dy -  res[j - 1][i] / map->divid;
    temp[0][1] = map->offsety - i * map->dx + (j - 1) * map->dy - res[j - 1][i] * map->multy;
    temp[1][2] = res[j][i];
    temp[1][0] = map->offsetx + i * map->dx + j * map->dy -  res[j][i] / map->divid;
    temp[1][1] = map->offsety - i * map->dx + j * map->dy - res[j][i] * map->multy;
    ft_draw_line(temp[0], temp[1], map);
}

void ft_draw_yline(int **res, int i, int j, t_map *map)
{
    int temp[2][3];
    temp[0][2] = res[j][i - 1];
    temp[0][0] = map->offsetx + (i - 1) * map->dx + j * map->dy -  res[j][i - 1] / map->divid;
    temp[0][1] = map->offsety - (i - 1) * map->dx + j * map->dy - res[j][i - 1] * map->multy;
    temp[1][2] = res[j][i];
    temp[1][0] = map->offsetx + i * map->dx + j * map->dy - res[j][i] / map->divid;
    temp[1][1] = map->offsety - i * map->dx + j * map->dy - res[j][i] * map->multy;
    ft_draw_line(temp[0], temp[1], map);
}

void ft_draw_line(int *a, int *b, t_map *map)
{
  float k;
  float k2;
  int f;
  int x;
  int y;
  int z;

  x = a[0];
  y = a[1];
  z = a[2];
  //printf(" a = {%d,%d}, b = {%d,%d}\n",a[0], a[1], b[0],b[1]);

  f = 1;
  if (b[1] == a[1])
    k = 0;
  else
    k =  (float)(b[0] - a[0]) / (float)(b[1] - a[1]);
  if (b[1] == a[1])
      k2 = 0;
  else
      k2 =  (float)(b[2] - a[2]) / (float)(b[1] - a[1]);
  if (b[1] < a[1])
    f = -1;
  map->color = 0x00FFFFFF - z * 12000;
  //printf("f = %d, k = %f, a = {%d,%d}, b = {%d,%d}\n",f, k, a[0], a[1], b[0],b[1]);
  mlx_pixel_put(map->mlx, map->win, a[0], a[1], map->color);

  while (y != b[1])
  {
    y = y + f;
    x = (int)((float)a[0] + k * (float)(y - a[1]));
    z = (int)((float)a[2] + k2 * (float)(y - a[1]));
    map->color = 0x00FFFFFF - z * 12000;
  //  printf("f = %d, k = %f, a = {%d,%d}, b = {%d,%d}\n",f, k, x, y, b[0],b[1]);
    mlx_pixel_put(map->mlx, map->win, x, y, map->color);
  }

}
int **ft_strtoint(char **str, t_map *map)
{
  int **res;
  char **temp;
  int i;

  i = 0;
  while (str[i])
    i++;
  res = (int**)malloc(sizeof(int*) * i);
  while (str[map->y])
  {
    temp = ft_strsplit(str[map->y], ' ');
    i = 0;
    while (temp[i])
      i++;
    res[map->y] = (int*)malloc(sizeof(int) * (i));
    map->x = 0;
    while (map->x < i)
    {
      res[map->y][map->x] = ft_atoi(temp[map->x]);
      get_min_max(res[map->y][map->x], map);
      (map->x)++;
    }
    (map->y)++;
  }
  return (res);
}
