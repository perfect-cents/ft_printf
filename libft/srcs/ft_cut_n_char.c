/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_n_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:50:15 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/02/09 13:50:18 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_cut_n_char(char **s, size_t f, size_t b)
{
	char	*p;
	size_t	len;

	if (!s)
		return (-1);
	else if ((!f && !b) || !*s)
		return (0);
	len = ft_strlen(*s) - f - b;
	p = *s;
	if ((*s = malloc(sizeof(**s) * len + 1)) == NULL)
		return (-1);
	ft_strntilcpy(*s, p + f, len);
	return (1);
}
