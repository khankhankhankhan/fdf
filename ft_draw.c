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

void ft_draw(char **new_file, int l)
{
  void *mlx;
  void *win;
  int x;
  int y;
  int **res;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 400, 400, "title");
  res = ft_strtoint(new_file, l, &x, &y);
  ft_display(res, x, y, mlx,win);
  mlx_loop(mlx);
}

void ft_display(int **res, int x, int y, void *mlx, void *win)
{
  int i;
  int j;


  i = 0;
  j = 0;
  int **cur;
  int temp[3];
  mlx = 0;
  win = 0;

  cur = (int**)malloc(sizeof(int*) * y);
  temp[0] = 150;
  temp[1] = 50;
  temp[2] = 0;
  cur[0] = (int*)malloc(sizeof(int) * 2);
  cur[0][0] = 150;
  cur[0][1] = 50;
  i = 1;
  while(i < y)
  {
    cur[i] = (int*)malloc(sizeof(int) * 2);
    cur[i][0] = temp[0] - i * 6 - res[0][i];
    cur[i][1] = temp[1] + i * 8 - res[0][i];
    printf("(%d,%d),",cur[i][0],cur[i][1]);
    //ft_draw_line(temp, cur[i], mlx,win);
    temp[2] = res[0][i];
    temp[0] = cur[i][0];
    temp[1] = cur[i][1];
    i++;
  }

  j = 1;
  while(j < y)
  {
    temp[0] = cur[0][0];
    temp[1] = cur[0][1];
    cur[0][0] = temp[0] - j * 6 - res[j][0];
    cur[0][1] = temp[1] + j * 8 - res[j][0];
    //ft_draw_line(temp, cur[0], mlx, win);
    temp[2] = res[j][0];
    i = 1;
    while(i < x)
    {
      temp[0] = cur[i][0];
      temp[1] = cur[i][1];
      temp[2] = res[j - 1][i];
      cur[i][0] = temp[0] - i * 6 - res[0][i];
      cur[i][1] = temp[1] + i * 8 - res[0][i];
      //ft_draw_line(temp, cur[i], mlx,win);
      //ft_draw_line(cur[i - 1], cur[i], mlx,win);
      i++;
    }
    j++;
  }
}
void ft_draw_line(int *a, int *b, void *mlx, void *win)
{
  int k;
  int f;

  f = 1;
  k = (b[1] - a[1]) / (b[0] - a[0]);
  if (b[1] > a[1])
    f = -1;
  mlx_pixel_put(mlx, win, a[0], a[1], 0x00ffffff);
  while (a[1] != b[1])
  {
    a[1] = a[1] + f;
    a[0] = a[0] + k;
    mlx_pixel_put(mlx, win, a[0], a[1], 0x00ffffff);
  }
}
int **ft_strtoint(char **str, int l, int *x, int *y)
{
  int **res;
  char **temp;
  int i;
  *x = 0;
  *y = 0;

  res = (int**)malloc(sizeof(int*) * l);
  while (*y < l)
  {
    printf("%s\n",str[*y]);
    temp = ft_strsplit(str[*y], ' ');
    (*x) = 0;
    while (temp[*x])
      (*x)++;
    res[*y] = (int*)malloc(sizeof(int) * (*x));
    i = 0;
    while (i < (*x))
    {
      res[*y][i] = ft_atoi(temp[i]);
      printf("%d ", res[*y][i]);
      i++;
    }
    printf("    res[%d]\n",*y);
    (*y)++;
  }
  return (res);
}
