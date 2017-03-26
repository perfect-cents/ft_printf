/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:32:29 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:04:25 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_list	*ft_ft_lstdup_helper(t_list *lst)
{
	return (lst);
}

t_list			*ft_lstdup(t_list *lst)
{
	return (ft_lstmap(lst, &ft_ft_lstdup_helper));
}
