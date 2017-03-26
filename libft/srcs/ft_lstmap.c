/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:31:32 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:04:52 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	*ft_lstmap_cleanup(t_list *head)
{
	ft_lstdel(&head, &ft_bzero);
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	tail = NULL;
	tmp = NULL;
	while (lst)
	{
		if ((tmp = ft_lstnew(lst->content, lst->content_size)) == NULL)
			return (ft_lstmap_cleanup(head));
		tmp = f(tmp);
		if (tail)
			tail->next = tmp;
		else
			head = tmp;
		tail = tmp;
		lst = lst->next;
	}
	return (head);
}
