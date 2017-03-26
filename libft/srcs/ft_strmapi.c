/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:11:27 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:11:12 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	if (!s || !f || (map = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		map[i] = f(i, *s);
		i++;
		s++;
	}
	return (map);
}
