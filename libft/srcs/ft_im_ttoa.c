/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_im_ttoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:49:09 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/02/09 13:49:15 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_im_ttoa_base(intmax_t n, char *base_str)
{
	intmax_t	tmp;
	int			i;
	char		*a;
	int			base;

	if (!n || n < -9223372036854775807)
		return (n ? ft_strdup("-9223372036854775808") : ft_strdup("0"));
	else if (!base_str)
		base_str = "0123456789";
	tmp = n;
	base = ft_strlen(base_str);
	i = 1 + (n < 0);
	while (tmp /= base)
		i++;
	if ((a = malloc(sizeof(*a) * i + 1)) == NULL)
		return (NULL);
	if (n < 0 && (n = -n))
		a[0] = '-';
	a[i--] = '\0';
	while (n)
	{
		a[i--] = base_str[n % base];
		n /= base;
	}
	return (a);
}
