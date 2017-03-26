/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uim_ttoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:47:23 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/02/09 13:47:27 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_uim_ttoa_base(uintmax_t n, char *base_str)
{
	uintmax_t	tmp;
	int			i;
	char		*a;
	int			base;

	if (!base_str)
			base_str = "0123456789";
	if (!n)
		return (ft_strndup(base_str, 1));
	tmp = n;
	base = ft_strlen(base_str);
	i = 1;
	while (tmp /= base)
		i++;
	if ((a = malloc(sizeof(*a) * i + 1)) == NULL)
		return (NULL);
	a[i--] = '\0';
	while (n)
	{
		a[i--] = base_str[n % base];
		n /= base;
	}
	return (a);
}
