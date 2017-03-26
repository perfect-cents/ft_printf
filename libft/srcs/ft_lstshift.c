/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:29:36 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:05:36 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstshift(t_list **alst)
{
	t_list	*sft;

	if (alst && *alst)
	{
		sft = *alst;
		*alst = (*alst)->next;
		sft->next = NULL;
		return (sft);
	}
	else
	{
		return (NULL);
	}
}
