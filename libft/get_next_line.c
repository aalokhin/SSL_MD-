/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:17:25 by aalokhin          #+#    #+#             */
/*   Updated: 2018/04/24 19:17:30 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*reallocate(char *savein, char *temp, int symb)
{
	t_j				rlc;

	ft_bzero(&rlc, sizeof(rlc));
	if (savein == NULL)
		(rlc.res) = ft_strdup(temp);
	else
	{
		rlc.l = ft_strlen(savein);
		rlc.res = ft_strnew(symb + rlc.l);
		(rlc.res)[symb + rlc.l] = '\0';
		while ((rlc.c1) < (symb + rlc.l))
		{
			if (savein[rlc.i] != '\0')
				(rlc.res)[(rlc.c1)] = savein[rlc.i++];
			else
				(rlc.res)[(rlc.c1)] = temp[rlc.c2++];
			(rlc.c1)++;
		}
	}
	ft_strdel(&savein);
	return ((rlc.res));
}

char		*the_line(char *savein, size_t *a)
{
	size_t			b;
	char			*ret;

	b = 0;
	ret = NULL;
	while (savein[*a] && savein[*a] != '\n')
		(*a)++;
	ret = ft_strnew(*a);
	while (b < *a)
	{
		ret[b] = savein[b];
		b++;
	}
	ret[b] = '\0';
	return (ret);
}

void		iter(t_list **cur, int fd)
{
	t_list		**node_holder;
	t_list		*node;

	while ((*cur)->next)
	{
		if ((int)((*cur)->content_size) == fd)
			return ;
		(*cur) = (*cur)->next;
	}
	if ((int)((*cur)->content_size) == fd)
		return ;
	node = ft_lstnew(NULL, 0);
	node->content_size = (size_t)fd;
	node_holder = &node;
	ft_lstadd(node_holder, *cur);
	(*cur) = (*cur)->next;
}

int			kos(t_h *gnl, const int *fd, char **line)
{
	if ((char*)((*gnl).j->content) != NULL)
		((*gnl).si) = ft_strdup((char*)((*gnl).j->content));
	else
		((*gnl).si) = NULL;
	((*gnl).tm) = ft_strnew(BUFF_SIZE);
	while (((*gnl).s = read((*fd), ((*gnl).tm), BUFF_SIZE)) > 0)
	{
		((*gnl).tm)[(*gnl).s] = '\0';
		((*gnl).si) = reallocate(((*gnl).si), ((*gnl).tm), (*gnl).s);
		if (ft_strchr(((*gnl).tm), '\n') != 0)
			break ;
	}
	ft_strdel(&((*gnl).tm));
	(*gnl).c = 0;
	if ((*gnl).s == 0 && ((char*)((*gnl).j->content) == NULL ||\
	((char*)((*gnl).j->content))[0] == '\0') && (!((*gnl).si) \
	|| ((*gnl).si)[0] == '\0'))
		return (0);
	*line = the_line(((*gnl).si), &(*gnl).c);
	ft_strdel(&((*gnl).si));
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	t_h				gnl;
	static t_list	*y;
	int				ret;

	ret = 0;
	if (line == NULL || fd < 0 || BUFF_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (y == NULL)
	{
		y = ft_lstnew(NULL, 0);
		(y->content_size) = (size_t)fd;
		gnl.j = y;
	}
	else
	{
		gnl.j = y;
		iter(&gnl.j, fd);
	}
	*line = NULL;
	ret = kos(&gnl, &fd, &(*line));
	return (ret);
}
