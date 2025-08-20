/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:51:04 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:51:04 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_of_word(char *str, char c)
{
	int	x;

	x = 0;
	while (str[x] != '\0' && str[x] != c)
		++x;
	return (x);
}

static char	*ft_dupe(char *str, char c)
{
	int		x;
	int		len;
	char	*s;

	x = 0;
	len = ft_len_of_word(str, c);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (x < len)
	{
		s[x] = str[x];
		++x;
	}
	return (s);
}

static char	**ft_remplissage(char **array, char *str, char c, int n_words)
{
	int	index;

	index = 0;
	while (*str == c)
		++str;
	while (*str != '\0')
	{
		array[index] = ft_dupe(str, c);
		++index;
		while (*str != '\0' && *str != c)
			++str;
		while (*str == c)
			++str;
	}
	array[n_words] = NULL;
	return (array);
}

static int	ft_comptage(char *str, char c)
{
	int	n_words;

	n_words = 0;
	while (*str == c)
		++str;
	while (*str != '\0')
	{
		++n_words;
		while (*str != '\0' && *str != c)
			++str;
		while (*str == c)
			++str;
	}
	return (n_words);
}

char	**ft_split(char const *str, char c)
{
	int		n_words;
	char	**final_result;

	if (str[0] == '\0')
	{
		final_result = malloc(sizeof(char *) * 1);
		if (!final_result)
			return (NULL);
		final_result[0] = NULL;
		return (final_result);
	}
	if (!ft_strchr(str, c) || !c)
	{
		final_result = malloc(sizeof(char *) * 2);
		if (!final_result)
			return (NULL);
		final_result[0] = ft_strdup(str);
		final_result[1] = NULL;
		return (final_result);
	}
	n_words = ft_comptage((char *)str, c);
	final_result = malloc(sizeof(char *) * (n_words + 1));
	if (!final_result)
		return (NULL);
	return (ft_remplissage(final_result, (char *)str, c, n_words));
}
