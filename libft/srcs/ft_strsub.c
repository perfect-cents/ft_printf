/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:12:00 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:12:56 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ss;

	if (!s || (ss = ft_strnew(len)) == NULL)
		return (NULL);
	return (ft_strntilcpy(ss, s + start, len));
}
