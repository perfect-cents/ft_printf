/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:12:06 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/17 14:12:07 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_tolower(int c)
{
	return (c >= 'A' && c <= 'Z' ? c + 32 : c);
}
