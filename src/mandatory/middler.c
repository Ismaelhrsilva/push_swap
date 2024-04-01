/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:01:29 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/01 19:45:51 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

int	smaller_middler(t_stack *stack, int size)
{
	t_list	*node;
	int		small;

	node = stack->head;
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

int	bigger_middler(t_stack *stack, int size)
{
	t_list	*node;
	int		big;

	node = stack->head;
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
	t_list	*tmp;
	int		i;
	int		min;
	int		big;
	int		small;

	big = bigger_middler(stack, size);
	small = smaller_middler(stack, size);
	while (--range)
	{
		min = small;
		tmp = stack->head;
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
