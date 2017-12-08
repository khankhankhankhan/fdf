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
  win = mlx_new_window(mlx, 800, 800, "mlx 42");
  res = ft_strtoint(new_file, l, &x, &y);
  ft_display(res, x, y, mlx, win);
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

  cur = (int**)malloc(sizeof(int*) * y);
  cur[0] = (int*)malloc(sizeof(int) * 2);
  cur[0][0] = 300;
  cur[0][1] = 500;
  cur[0][2] = 0;
  temp[2] = 0;
  i = 1;
  printf("cur[00]=%d cur[01] = %d\n", cur[0][0],cur[0][1]);
  while(i < y)
  {
    cur[i] = (int*)malloc(sizeof(int) * 2);
    temp[2] = res[0][i - 1];
    temp[0] = cur[i - 1][0] + 8 + res[0][i] - temp[2];
    temp[1] = cur[i - 1][1] + 12 + res[0][i] - temp[2];

    ft_draw_line(cur[i - 1], temp, mlx,win);
    cur[i][0] = temp[0];
    cur[i][1] = temp[1];
    printf("cur[%d][0]=%d cur[%d][1] = %d\n", i,cur[i][0],i,cur[i][1]);
    i++;
  }
  //mlx_loop(mlx);
  printf("cur[00]=%d cur[01] = %d\n", cur[0][0],cur[0][1]);
  j = 1;
  while(j < x)
  {
    i = 0;
    temp[0] = cur[0][0] + 12 + res[0][j] - res[0][j - 1];
    temp[1] = cur[0][1] - 8 + res[0][j] - res[0][j - 1];
    printf("cur[%d][0]=%d cur[%d][1] = %d\n", i,cur[i][0],i,cur[i][1]);
    printf("temp= {%d, %d}\n", temp[0],temp[1]);
    ft_draw_line(cur[0],temp,mlx, win);
    cur[0][0] = temp[0];
    cur[0][1] = temp[1];
    //mlx_loop(mlx);

    i = 1;
    while(i < y)
    {
      temp[2] = res[i - 1][j];
      temp[0] = cur[i - 1][0] + 8 + (res[i][j] - temp[2]) / 10;
      temp[1] = cur[i - 1][1] + 12 - (res[i][j] - temp[2]) * 20;
      ft_draw_line(cur[i - 1], temp, mlx,win);
      ft_draw_line(cur[i], temp, mlx,win);
      cur[i][0] = temp[0];
      cur[i][1] = temp[1];
      i++;
    }
    j++;
  }
}
void ft_draw_line(int *a, int *b, void *mlx, void *win)
{
  float k;
  int f;
  int x;
  int y;

  x = a[0];
  y = a[1];
  //printf(" a = {%d,%d}, b = {%d,%d}\n",a[0], a[1], b[0],b[1]);

  f = 1;
  if (b[1] == a[1])
    k = 0;
  else
    k =  (float)(b[0] - a[0]) / (float)(b[1] - a[1]);
  if (b[1] < a[1])
    f = -1;
  printf("f = %d, k = %f, a = {%d,%d}, b = {%d,%d}\n",f, k, a[0], a[1], b[0],b[1]);
  mlx_pixel_put(mlx, win, a[0], a[1], 0x00FFFFFF);

  while (y != b[1])
  {
    y = y + f;
    x = (int)((float)a[0] + k * (float)(y - a[1]));
    printf("f = %d, k = %f, a = {%d,%d}, b = {%d,%d}\n",f, k, x, y, b[0],b[1]);
    mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
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
    temp = ft_strsplit(str[*y], ' ');
    (*x) = 0;
    while (temp[*x])
      (*x)++;
    res[*y] = (int*)malloc(sizeof(int) * (*x));
    i = 0;
    while (i < (*x))
    {
      res[*y][i] = ft_atoi(temp[i]);
      i++;
    }
    (*y)++;
  }
  return (res);
}
