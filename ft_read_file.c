/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:12:08 by hkang             #+#    #+#             */
/*   Updated: 2017/12/06 14:12:10 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

char **ft_read_file(char *file, int *l)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		rd;
	char *temp;
	char *temp2;
	char **newfile;
	fd = 0;
	*l = 0;
	fd = open(file, O_RDONLY);
	rd = read(fd, buf, BUFF_SIZE);
	temp = ft_strnew(BUFF_SIZE);
	temp = ft_strncpy(temp, buf, BUFF_SIZE);
	printf("%s\n",temp);
	while(rd > 0)
	{
		temp2 = temp;
		ft_bzero(buf, BUFF_SIZE + 1);
		rd = read(fd, buf, BUFF_SIZE);
		temp = ft_strjoin(temp, buf);
		free(temp2);
	}
	newfile = ft_strsplit(temp, '\n');
	*l = 0;
	while (newfile[*l])
	{
		printf("%s   temp\n", newfile[*l]);
		(*l)++;
	}
	printf("len = %d\n", *l);
	close(fd);
	return (newfile);
}
