/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:49:38 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:49:38 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*d1;
	size_t	i;

	s1 = (char *)src;
	d1 = (char *)dest;
	i = 0;
	if (!s1 && !d1)
		return (d1);
	if (d1 > s1)
	{
		while (n--)
		{
			d1[n] = s1[n];
		}
	}
	else
	{
		while (i < n)
		{
			d1[i] = s1[i];
			i++;
		}
	}
	return (d1);
}
