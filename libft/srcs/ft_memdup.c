/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:33:41 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:06:59 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memdup(const void *src, size_t n)
{
	void	*mem;

	if ((mem = ft_memalloc(n)) == NULL)
		return (NULL);
	return (ft_memcpy(mem, src, n));
}
