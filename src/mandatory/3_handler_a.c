/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_handler_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:06:05 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/03 21:09:43 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mandatory/push_swap.h"

static void	min_top(t_stack *stack, t_stack *stack_b, int max)
{
	if (*(int *)stack->head->next->content == max)
	{
		operations(RA, stack, stack_b);
		operations(SA, stack, stack_b);
		operations(RRA, stack, stack_b);
	}
}

static void	min_middle(t_stack *stack, t_stack *stack_b, int max)
{
	operations(SA, stack, stack_b);
	if (*(int *)stack->head->next->content == max)
	{
		operations(RA, stack, stack_b);
		operations(SA, stack, stack_b);
		operations(RRA, stack, stack_b);
	}
}

static void	min_bottom(t_stack *stack, t_stack *stack_b, int max)
{
	if (*(int *)stack->head->content == max)
		operations(SA, stack, stack_b);
	operations(RA, stack, stack_b);
	operations(SA, stack, stack_b);
	operations(RRA, stack, stack_b);
	operations(SA, stack, stack_b);
}

void	three_handler_a(t_stack *stack, t_stack *stack_b)
{
	int		min;
	int		max;

	min = smaller_middler(stack, 3);
	max = bigger_middler(stack, 3);
	if (stack->size == 3)
		sort_3(stack);
	else if (*(int *)stack->head->content == min)
		min_top(stack, stack_b, max);
	else if (*(int *)stack->head->next->content == min)
		min_middle(stack, stack_b, max);
	else if (*(int *)stack->head->next->next->content == min)
		min_bottom(stack, stack_b, max);
}
