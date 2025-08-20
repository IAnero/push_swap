/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:52:56 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:52:56 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search_set(const char *set, char c)
{
	int	x;

	x = 0;
	while (set[x] != '\0')
	{
		if (set[x] == c)
		{
			return (1);
		}
		x++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		x;
	int		i;
	int		a;
	char	*s2;
	int		result;

	x = 0;
	a = 0;
	i = ft_strlen(s1) - 1;
	while (s1[x] != '\0' && ft_search_set(set, s1[x]))
		x++;
	while (ft_search_set(set, s1[i]))
		i--;
	result = i - x + 1;
	if (result <= 0)
		return (ft_strdup(""));
	s2 = malloc(sizeof (char) * (result + 1));
	if (s2 == NULL)
		return (0);
	while (x <= i)
	{
		s2[a++] = s1[x++];
	}
	s2[a] = '\0';
	return (s2);
}
