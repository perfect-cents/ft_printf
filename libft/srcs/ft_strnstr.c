/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:11:47 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 14:34:27 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	while (len && *big)
	{
		i = 0;
		while (len && big[i] == little[i])
		{
			i++;
			if (!little[i])
				return ((char *)big);
			len--;
		}
		len += i - 1;
		big++;
	}
	return (NULL);
}
