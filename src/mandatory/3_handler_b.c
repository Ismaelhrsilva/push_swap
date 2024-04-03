/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_handler_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:15:09 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/03 20:27:10 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void	min_top(t_stack *stack_b, int max)
{
	if (stack_b->size == 3)
	{
		operations(RB, NULL, stack_b);
		if (*(int *)stack_b->head->next->content == max)
			operations(SB, NULL, stack_b);
	}
	else
	{
		operations(SB, NULL, stack_b);
		operations(RB, NULL, stack_b);
		operations(SB, NULL, stack_b);
		operations(RRB, NULL, stack_b);
		if (*(int *)stack_b->head->next->content == max)
			operations(SB, NULL, stack_b);
	}
}

static void	min_middle(t_stack *stack_b, int max)
{
	if (stack_b->size == 3)
	{
		operations(RRB, NULL, stack_b);
		if (*(int *)stack_b->head->next->content == max)
			operations(SB, NULL, stack_b);
	}
	else
	{
		operations(RB, NULL, stack_b);
		operations(SB, NULL, stack_b);
		operations(RRB, NULL, stack_b);
		if (*(int *)stack_b->head->next->content == max)
			operations(SB, NULL, stack_b);
	}
}

static void	min_bottom(t_stack *stack_b, int max)
{
	if (*(int *)stack_b->head->next->content == max)
		operations(SB, NULL, stack_b);
}

void	three_handler_b(t_stack *stack, t_stack *stack_b)
{
	int		min;
	int		max;

	min = smaller_middler(stack_b, 3);
	max = bigger_middler(stack_b, 3);
	if (*(int *)stack_b->head->content == min)
		min_top(stack_b, max);
	else if (*(int *)stack_b->head->next->content == min)
		min_middle(stack_b, max);
	else if (*(int *)stack_b->head->next->next->content== min)
		min_bottom(stack_b, max);
	operations(PA, stack, NULL);
	operations(PA, stack, NULL);
	operations(PA, stack, NULL);
}
