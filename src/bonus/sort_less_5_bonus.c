/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:28:26 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 16:32:47 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"

void	sort_three(t_stack *stack, t_stack *stack_b)
{
	int	big;

	big = bigger_middler(stack, stack->size);
	if (*(int *)stack->head->content == big)
		operations(RA, stack, stack_b);
	else if (*(int *)stack->head->next->content == big)
		operations(RRA, stack, stack_b);
	if (*(int *)stack->head->content > *(int *)stack->head->next->content)
		operations(SA, stack, stack_b);
}

void	sort_4(t_stack *stack, t_stack *stack_b)
{
	t_pos	small;

	if (stack->size <= 3)
		return (sort_three(stack, stack_b));
	small = pos_(smaller, stack);
	if (small.pos == 1)
		operations(RA, stack, NULL);
	else if (small.pos == 2)
		loop(RA, 2, stack, NULL);
	else if (small.pos == 3)
		operations(RRA, stack, NULL);
	if (sorted_stack(stack))
		return ;
	operations(PB, stack, stack_b);
	sort_three(stack, stack_b);
	operations(PA, stack, stack_b);
}

void	sort_5(t_stack *stack, t_stack *stack_b)
{
	t_pos	small;

	if (stack->size <= 4)
		return (sort_4(stack, stack_b));
	small = pos_(smaller, stack);
	if (small.pos == 1)
		operations(RA, stack, NULL);
	else if (small.pos == 2)
		loop(RA, 2, stack, NULL);
	else if (small.pos == 3)
		loop(RRA, 2, stack, NULL);
	else if (small.pos == 4)
		operations(RRA, stack, NULL);
	if (sorted_stack(stack))
		return ;
	operations(PB, stack, stack_b);
	sort_4(stack, stack_b);
	operations(PA, stack, stack_b);
}
