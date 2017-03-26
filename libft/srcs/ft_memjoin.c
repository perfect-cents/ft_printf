/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:31:09 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:07:09 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memjoin(void *dst, size_t dlen, const void *src, size_t slen)
{
	void	*mem;

	if ((mem = ft_memalloc(dlen + slen)) == NULL)
		return (NULL);
	ft_memcpy(mem, dst, dlen);
	ft_memcpy((void *)((char *)mem + dlen), src, slen);
	return (dst);
}
