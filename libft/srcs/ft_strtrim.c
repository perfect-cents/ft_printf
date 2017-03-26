/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:12:03 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:13:03 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(const char *s)
{
	const char	*p;
	size_t		n;

	if (!s)
		return (NULL);
	else if ((n = ft_strlen(s)) == 0 || (\
	!(*s == ' ' || *s == '\t' || *s == '\n') && \
	!(s[n - 1] == ' ' || s[n - 1] == '\t' || s[n - 1] == '\n')))
		return (ft_strdup(s));
	p = s + n - 1;
	while ((*p == ' ' || *p == '\t' || *p == '\n') && s < p)
		p--;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && s < p)
		s++;
	return (s == p ? ft_strdup("") : ft_strndup(s, p - s + 1));
}
