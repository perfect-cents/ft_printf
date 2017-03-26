/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:05:59 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/02/09 11:06:08 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>

static t_list	*get_curr(t_list **lst, const int fd)
{
	t_list	*el;

	el = *lst;
	while (el)
	{
		if ((int)el->content_size == fd)
			return (el);
		el = el->next;
	}
	if (!(el = ft_lstnew("", 1)))
		return (el);
	el->content_size = fd;
	ft_lstadd(lst, el);
	return (*lst);
}

static int		setnxtline(t_list *curr, char **line)
{
	char	*p1;
	char	*p2;

	p1 = curr->content;
	if (!*p1)
		return ((int)(*line = NULL));
	p2 = curr->content;
	while (*p2 != '\n' && *p2)
		p2++;
	if (!(*line = ft_strndup(p1, p2 - p1)) \
	|| !(curr->content = *p2 ? ft_strdup(p2 + 1) : ""))
	{
		free(*line);
		free(p1);
		return ((int)(*line = NULL) \
		+ (int)(curr->content = NULL) - 1);
	}
	free(p1);
	return (1);
}

static int		read_in(t_list *curr)
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		status;

	if (ft_strchr(curr->content, '\n'))
		return (0);
	while ((status = read(curr->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[status] = '\0';
		tmp = curr->content;
		if (!(curr->content = ft_strjoin(tmp, buf)))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		if (ft_strchr(buf, '\n'))
			return (1);
	}
	return (status);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*curr;

	if (!line)
		return (-1);
	if (fd < 0 || !(curr = get_curr(&lst, fd)) || !curr->content \
	|| read_in(curr) < 0)
		return ((int)(*line = NULL) - 1);
	return (setnxtline(curr, line));
}
