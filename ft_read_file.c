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
	t_queue	*que;
	char *line;
	char	**new_file;
	//char  **test;
	char *temp_line;
	//t_node *temp;
	fd = 0;
	*l = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	que = ft_queue_init();
	line = ft_strnew(1);

	while (get_next_line(fd, &line) == 1)
	{
		temp_line = ft_strnew(1);
		temp_line = ft_strjoin(temp_line, line);
		ft_enqueue(que, temp_line);
		(*l)++;
	}
	new_file = (char**)malloc(sizeof(char*) + (*l));
	int i;
	i = 0;
	while (i < *l)
	{

		new_file[i] = ft_dequeue(que);
		printf("%s   temp\n", new_file[i]);
		i++;
	}
	close(fd);
	return (new_file);
}
