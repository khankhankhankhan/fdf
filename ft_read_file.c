/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:12:08 by hkang             #+#    #+#             */
/*   Updated: 2017/12/11 13:40:08 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

char	**ft_read_file(char *file)
{
	int		fd[2];
	char	buf[BUFF_SIZE + 1];
	char	**temp;
	char	**newfile;

	fd[0] = open(file, O_RDONLY);
	fd[1] = read(fd[0], buf, BUFF_SIZE);
	temp = (char**)malloc(sizeof(char*) * 2);
	temp[0] = ft_strnew(BUFF_SIZE);
	temp[0] = ft_strncpy(temp[0], buf, BUFF_SIZE);
	while (fd[1] > 0)
	{
		temp[1] = temp[0];
		ft_bzero(buf, BUFF_SIZE + 1);
		fd[1] = read(fd[0], buf, BUFF_SIZE);
		temp[0] = ft_strjoin(temp[0], buf);
		free(temp[1]);
	}
	newfile = ft_strsplit(temp[0], '\n');
	free(temp[0]);
	close(fd[0]);
	return (newfile);
}
