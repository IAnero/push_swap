/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:46:10 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:46:10 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = init_stack_node(stack);
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	if_need_split(int i, t_stack_node **a, char **argv)
{
	int		x;
	char	**tmp;
	long	n;

	x = 1;
	tmp = split(argv[i], ' ');
	while (tmp[x])
	{
		if (error_syntax(tmp[x]))
		{
			free_av (tmp);
			free_errors(a);
		}
		n = ft_atol(tmp[x]);
		if ((n > INT_MAX || n < INT_MIN) || error_duplicate(*a, (int)n))
		{
			free_av(tmp);
			free_errors(a);
		}
		append_node(a, (int)n);
		x++;
	}
	free_av (tmp);
}

void	init_stack_a(t_stack_node **a, char **argv, int ac)
{
	long	n;
	int		i;

	i = 0;
	(void)ac;
	while (argv[i])
	{
		if (!spacee(argv[i]))
			free_errors(a);
		if (ft_strchr(argv[i], ' '))
			if_need_split(i, a, argv);
		else
		{
			if (error_syntax(argv[i]))
				free_errors (a);
			n = ft_atol(argv[i]);
			if (n > INT_MAX || n < INT_MIN)
				free_errors(a);
			if (error_duplicate(*a, (int)n))
				free_errors(a);
			append_node(a, (int)n);
		}
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
