/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:48:03 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:48:03 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number(unsigned long nb)
{
	int	x;

	x = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		x++;
	}
	return (x);
}

static void	ft_result(unsigned long nb, char *res, int x)
{
	char	*ref;

	ref = "0123456789abcdef";
	ft_putchar('0');
	ft_putchar('x');
	while (x > 0)
	{
		res[x - 1] = ref[nb % 16];
		nb = nb / 16;
		x--;
	}
	ft_putstr(res);
}

int	ft_adress(unsigned long nb)
{
	char	*result;
	int		x;

	x = count_number(nb);
	if (nb == 0)
		return (ft_putstr("(nil)"));
	result = malloc(sizeof(char *) * x);
	if (!result)
		return (0);
	result[x] = '\0';
	ft_result(nb, result, x);
	free (result);
	return (x + 2);
}
