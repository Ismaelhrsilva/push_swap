/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:01:29 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 15:26:16 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

t_aux	*init_aux(t_stack *stack, int size)
{
	t_aux	*aux;

	aux = malloc(sizeof(t_aux));
	if (!aux)
		return (0);
	aux->big = middler(stack, size / 2, size);
	aux->medium = middler(stack, size / 4 * 3, size);
	aux->ra = 0;
	aux->rb = 0;
	aux->pa = 0;
	aux->pb = 0;
	return (aux);
}

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
			if (*(int *)tmp->content > min && *(int *)tmp->content < big)
				min = *((int *)tmp->content);
			tmp = tmp->next;
		}
		big = min;
	}
	return (min);
}
