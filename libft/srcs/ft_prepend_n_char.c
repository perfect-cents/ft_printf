/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend_n_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:48:41 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/02/09 13:48:53 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_prepend_n_char(char **s, char c, size_t n)
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
	ft_memset(p, c, n);
	p[n] = '\0';
	ft_strcat(p, *s);
	*s = p;
	return (1);
}
