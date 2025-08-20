/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:50:28 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:50:28 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_number(unsigned int nb)
{
	int	x;

	x = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		x++;
	}
	return (x);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	x;

	x = count_number(nb);
	if (nb == 0)
		x = x + 1;
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	return (x);
}
