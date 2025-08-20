/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:51:10 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:51:10 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	char	result;
	int		x;

	x = 0;
	result = c;
	while (s[x] != '\0')
	{
		if (s[x] == result)
		{
			return (1);
		}
		x++;
	}
	return (0);
}
