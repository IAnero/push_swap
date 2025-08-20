/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:52:49 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:52:49 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	result;
	int		x;

	x = 0;
	result = c;
	if (result == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[x] != '\0')
		x++;
	while (x >= 0)
	{
		if (s[x] == result)
			return ((char *)s + x);
		x--;
	}
	return (NULL);
}
