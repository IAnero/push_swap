/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:48:23 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:48:23 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*test;
	size_t	x;

	x = 0;
	test = malloc(nmemb * size);
	if (!test)
		return (0);
	while (x < nmemb * size)
	{
		test[x] = 0;
		x++;
	}
	return (test);
}
