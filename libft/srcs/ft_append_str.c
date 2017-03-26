/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:50:29 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/02/09 13:50:36 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_append_str(char **s1, char *s2)
{
	char	*p;
	size_t	len;

	if (!s1)
		return (-1);
	else if (!s2 || (!*s1 && !s2))
		return (0);
	else if (!*s1)
	{
		if ((*s1 = ft_strdup(s2)) == NULL)
			return (-1);
		return (1);
	}
	p = *s1;
	len = ft_strlen(*s1) + ft_strlen(s2);
	if ((*s1 = malloc(sizeof(**s1) * (len + 1))) == NULL)
		return (-1);
	(*s1)[0] = '\0';
	ft_strcat(ft_strcpy(*s1, p), s2);
	return (1);
}
