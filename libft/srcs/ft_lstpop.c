/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:38:22 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:05:13 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstpop(t_list **alst)
{
	t_list	*pop;
	t_list	*tmp;
	t_list	*strt;

	if (!alst)
		return (NULL);
	if (*alst && (*alst)->next)
	{
		strt = *alst;
		tmp = *alst;
		pop = (*alst)->next;
		while (pop->next)
		{
			*alst = (*alst)->next;
			tmp = *alst;
			pop = (*alst)->next;
		}
		tmp->next = NULL;
		*alst = strt;
		return (pop);
	}
	pop = *alst;
	*alst = NULL;
	return (pop);
}
