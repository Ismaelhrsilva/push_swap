/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_handler_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:15:09 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/03 21:12:01 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void	min_top(t_stack * stack, t_stack *stack_b, int max)
{
	if (stack_b->size == 3)
	{
		operations(RB, stack, stack_b);
		if (*(int *)stack_b->head->next->content == max)
			operations(SB, stack, stack_b);
	}
	else
	{
		operations(SB, stack, stack_b);
		operations(RB, stack, stack_b);
		operations(SB, stack, stack_b);
		operations(RRB, stack, stack_b);
		if (*(int *)stack_b->head->next->content == max)
			operations(SB, stack, stack_b);
	}
}

static void	min_middle(t_stack *stack, t_stack *stack_b, int max)
{
	if (stack_b->size == 3)
	{
		operations(RRB, stack, stack_b);
		if (*(int *)stack_b->head->next->content == max)
			operations(SB, stack, stack_b);
	}
	else
	{
		operations(RB, stack, stack_b);
		operations(SB, stack, stack_b);
		operations(RRB, stack, stack_b);
		if (*(int *)stack_b->head->next->content == max)
			operations(SB, stack, stack_b);
	}
}

static void	min_bottom(t_stack *stack, t_stack *stack_b, int max)
{
	if (*(int *)stack_b->head->next->content == max)
		operations(SB, stack, stack_b);
}

void	three_handler_b(t_stack *stack, t_stack *stack_b)
{
	int		min;
	int		max;

	min = smaller_middler(stack_b, 3);
	max = bigger_middler(stack_b, 3);
	if (*(int *)stack_b->head->content == min)
		min_top(stack, stack_b, max);
	else if (*(int *)stack_b->head->next->content == min)
		min_middle(stack, stack_b, max);
	else if (*(int *)stack_b->head->next->next->content== min)
		min_bottom(stack, stack_b, max);
	operations(PA, stack, stack_b);
	operations(PA, stack, stack_b);
	operations(PA, stack, stack_b);
}
