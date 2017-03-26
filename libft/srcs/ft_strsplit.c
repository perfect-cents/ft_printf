/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:11:53 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:12:41 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		**ft_strsplit_cleanup(char **tab, size_t i)
{
	while (i--)
		ft_memfree(tab[i]);
	return (ft_memfree(tab));
}

static size_t	get_wc(const char *s, char c)
{
	char	f;
	size_t	wc;

	f = 0;
	wc = 0;
	while (*s)
	{
		if (!f && *s && *s != c)
		{
			f = 1;
			wc++;
		}
		else if (f && *s == c)
			f = 0;
		s++;
	}
	return (wc);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	wc;

	if (!s)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(*tab) * \
	((wc = get_wc(s, c)) + 1))) == NULL)
		return (ft_memfree(tab));
	j = 0;
	while (*s && j < wc)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if ((tab[j] = ft_strndup(s, i)) == NULL)
			return (ft_strsplit_cleanup(tab, j));
		s += i;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
