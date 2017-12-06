/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:50:13 by hkang             #+#    #+#             */
/*   Updated: 2017/12/06 11:50:16 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_node
{
	char *content;
	struct s_node *next;
}       t_node;

typedef struct s_queue
{
	struct s_node *first;
	struct s_node *last;
}       t_queue;


t_queue *ft_queue_init(void);
void	ft_enqueue(t_queue *queue, char *content);
char	*ft_dequeue(t_queue *queue);
char	*ft_queue_peek(t_queue *queue);
int		ft_queue_isEmpty(t_queue *queue);

char **ft_read_file(char *file);
#endif
