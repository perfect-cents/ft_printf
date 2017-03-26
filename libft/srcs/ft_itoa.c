/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:09:22 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/02/09 13:48:21 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	int			tmp;
	int			i;
	char		*a;

	if (!n || n < -2147483648)
		return (n ? ft_strdup("-2147483648") : ft_strdup("0"));
	tmp = n;
	i = 1 + (n < 0);
	while (tmp /= 10)
		i++;
	if ((a = malloc(sizeof(*a) * i + 1)) == NULL)
		return (NULL);
	if (n < 0 && (n = -n))
		a[0] = '-';
	a[i--] = '\0';
	while (n)
	{
		a[i--] = n % 10 + '0';
		n /= 10;
	}
	return (a);
}
