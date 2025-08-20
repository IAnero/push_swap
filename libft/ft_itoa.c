/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:49:01 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:49:01 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_of_char(long n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

static char	*ft_utilisation_true_result(long n, char *result, int x)
{
	while (n != 0)
	{
		result[x - 1] = n % 10 + '0';
		n /= 10;
		x--;
	}
	return (result);
}

static char	*ft_test_other_cas(int i, int n, char *result)
{
	if (n == 0)
	{
		result[i] = '0';
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		x;
	int		i;
	char	*result;
	long	nb;

	nb = (long)n;
	x = length_of_char((long)n);
	i = 0;
	if (n < 0)
		x++;
	result = malloc(sizeof(char) * (x + 1));
	if (!result)
		return (NULL);
	if (n == 0)
		return (ft_test_other_cas(i, nb, result));
	if (n < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	result = ft_utilisation_true_result(nb, result, x);
	result[x] = '\0';
	return (result);
}
