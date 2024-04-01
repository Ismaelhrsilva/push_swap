/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:01:29 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/01 19:08:15 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

int	smaller(t_stack *stack, int size)
{
	t_stack	*node;
	int		small;

	node = stack;
	small = *((int *)node->content);
	while (node && size--)
	{
		if (*((int *)node->content) < small)
			small = *((int *)node->content);
		if (node->next)
			node = node->next;
	}
	return (small);
}

int	bigger(t_stack *stack, int size)
{
	t_stack	*node;
	int		big;

	node = stack;
	big = *((int *)node->content);
	while (node && size--)
	{
		if (*((int *)node->content) > big)
			big = *((int *)node->content);
		if (node->next)
			node = node->next;
	}
	return (big);
}

int	middler(t_stack *stack, int range, int size)
{
	t_stack	*tmp;
	int		i;
	int		min;
	int		big;
	int		small;

	big = bigger(stack, size);
	small = smaller(stack, size);
	while (--range)
	{
		min = small;
		tmp = stack;
		i = 0;
		while (tmp && i++ < size)
		{
			if (*(int *)see_stack(stack) > min && *(int *)see_stack(stack) < big)
				min = *((int *)tmp->content);
			tmp = tmp->next;
		}
		big = min;
	}
	return (min);
}
