/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_handler_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:06:05 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/03 20:27:44 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mandatory/push_swap.h"

static void	min_top(t_stack *stack, int max)
{
	if (*(int *)stack->head->next->content == max)
	{
		operations(RA, stack, NULL);
		operations(SA, stack, NULL);
		operations(RRA, stack, NULL);
	}
}

static void	min_middle(t_stack *stack, int max)
{
	operations(SA, stack, NULL);
	if (*(int *)stack->head->next->content == max)
	{
		operations(RA, stack, NULL);
		operations(SA, stack, NULL);
		operations(RRA, stack, NULL);
	}
}

static void	min_bottom(t_stack *stack, int max)
{
	if (*(int *)stack->head->content == max)
		operations(SA, stack, NULL);
	operations(RA, stack, NULL);
	operations(SA, stack, NULL);
	operations(RRA, stack, NULL);
	operations(SA, stack, NULL);
}

void	three_handler_a(t_stack *stack)
{
	int		min;
	int		max;

	min = smaller_middler(stack, 3);
	max = bigger_middler(stack, 3);
	if (stack->size == 3)
		sort_3(stack);
	else if (*(int *)stack->head->content == min)
		min_top(stack, max);
	else if (*(int *)stack->head->next->content == min)
		min_middle(stack, max);
	else if (*(int *)stack->head->next->next->content == min)
		min_bottom(stack, max);
}
