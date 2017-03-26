/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:10:01 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:07:19 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	dp = (unsigned char *)dst;
	sp = (const unsigned char *)src;
	if (src < dst)
	{
		dp += len - 1;
		sp += len - 1;
		while (len--)
			*dp-- = *sp--;
		return (dst);
	}
	while (len--)
		*dp++ = *sp++;
	return (dst);
}
