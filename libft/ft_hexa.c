/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:48:29 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:48:29 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number(unsigned int nb)
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

static void	ft_upper(unsigned int nb, char *result, int x, char *ref_upper)
{
	while (nb)
	{
		result[x - 1] = ref_upper[nb % 16];
		nb = nb / 16;
		x--;
	}
	ft_putstr(result);
}

static void	ft_lower(unsigned int nb, char *result, int x, char *ref_lower)
{
	while (nb)
	{
		result[x - 1] = ref_lower[nb % 16];
		nb = nb / 16;
		x--;
	}
	ft_putstr(result);
}

int	ft_hexa(char format_type, unsigned int nb)
{
	char	*result;
	int		x;
	char	*ref_upper;
	char	*ref_lower;

	ref_upper = "0123456789ABCDEF";
	ref_lower = "0123456789abcdef";
	x = count_number(nb);
	if (nb == 0)
		return (ft_putchar('0'));
	result = malloc(sizeof(char *) * x);
	if (!result)
		return (0);
	result[x] = '\0';
	if (format_type == 'X')
		ft_upper(nb, result, x, ref_upper);
	else
		ft_lower(nb, result, x, ref_lower);
	free (result);
	return (x);
}
