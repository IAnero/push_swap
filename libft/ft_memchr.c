/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:49:22 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:49:22 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		x;

	x = 0;
	str = (const char *)s;
	while (x < n)
	{
		if (str[x] == (char)c)
		{
			return ((void *)str + x);
		}
		x++;
	}
	return (NULL);
}
