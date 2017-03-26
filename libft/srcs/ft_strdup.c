/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:11:00 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:09:51 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*ns;

	if ((ns = ft_strnew(ft_strlen(s1))) == NULL)
		return (NULL);
	return (ft_strcpy(ns, s1));
}
