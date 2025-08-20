/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:51:24 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:51:24 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		x;
	int		i;
	char	*new;
	int		a;

	x = 0;
	i = 0;
	new = malloc(sizeof (char) * ft_strlen(s) + 1);
	if (new == NULL)
		return (0);
	a = ft_strlen(s);
	new[a] = '\0';
	while (s[x] != '\0')
	{
		new[i] = s[x];
		x++;
		i++;
	}
	return (new);
}
