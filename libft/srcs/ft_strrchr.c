/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:11:50 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:12:32 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_instance;

	last_instance = NULL;
	c = (char)c;
	while (*s)
	{
		if (*s == c)
			last_instance = s;
		s++;
	}
	return ((char *)(*s == c ? s : last_instance));
}
