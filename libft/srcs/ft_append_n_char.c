/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_n_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:47:04 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/02/09 13:47:07 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_append_n_char(char **s, char c, size_t n)
{
	char	*p;
	size_t	len;

	if (!s)
		return (-1);
	else if (!n)
		return (0);
	else if (!*s)
	{
		if ((*s = malloc(sizeof(**s) * n + 1)) == NULL)
			return (-1);
		ft_memset(*s, c, n);
		*s[n] = '\0';
		return (1);
	}
	len = ft_strlen(*s);
	if ((p = malloc(sizeof(*p) * (len + n) + 1)) == NULL)
		return (-1);
	ft_memset(ft_strcpy(p, *s) + len, c, n);
	p[len + n] = '\0';
	*s = p;
	return (1);
}
