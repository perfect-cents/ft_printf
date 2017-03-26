/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:11:57 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:12:49 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		i = 0;
		while (*big && big[i] == little[i])
		{
			i++;
			if (!little[i])
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
