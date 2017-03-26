/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:09:37 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:06:08 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	dp = (unsigned char *)dst;
	sp = (const unsigned char *)src;
	c = (unsigned char)c;
	while (n)
	{
		*dp++ = *sp;
		if (*sp++ == c)
			return ((void *)dp);
		n--;
	}
	return (NULL);
}
