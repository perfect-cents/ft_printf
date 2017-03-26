/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:30:08 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:05:26 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*strt;

	if (!alst)
		return ;
	if (*alst)
	{
		strt = *alst;
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = new;
		*alst = strt;
	}
	else
	{
		*alst = new;
	}
}
