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

char **ft_read_file(char *file)
{
	int		fd;
	t_queue	*que;
	int		index;
	char *line;
	char	**new_file;

	fd = 0;
	index = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	que = ft_queue_init();
	line = ft_strnew(1);

	while (get_next_line(fd, &line) == 1)
	{

		ft_enqueue(que, line);
		printf("%s   point= %p\n", que->last->content,que->last->content);
		index++;
	}
	new_file = (char**)malloc(sizeof(char*) + (index + 1));
	int i;
	i = 0;
	printf("\n");
	while (i < index)
	{
		new_file[i] = ft_strnew(1);
		printf("%s   point= %p\n", que->first->content,que->first->content);
		new_file[i] = ft_dequeue(que);
		//printf("%s\n", new_file[i]);
		i++;
	}
	close(fd);
	return (new_file);
}
