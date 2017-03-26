/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:11:38 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:11:54 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ns;
	size_t	len;

	len = ft_strlen(s1);
	len = len < n ? len : n;
	if ((ns = ft_strnew(len)) == NULL)
		return (NULL);
	return (ft_strntilcpy(ns, s1, len));
}
