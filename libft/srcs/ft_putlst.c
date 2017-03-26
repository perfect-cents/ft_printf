/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:31:49 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:03:56 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_putlst_helper(t_list *lst)
{
	if (lst)
		write(1, lst->content, lst->content_size);
}

void		ft_putlst(t_list *lst)
{
	ft_lstiter(lst, &ft_putlst_helper);
}
