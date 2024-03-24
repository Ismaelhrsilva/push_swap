/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:28:26 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 21:18:42 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

void	sort_3(t_stack *stack)
{
	t_pos	small;
	t_pos	big;

	if (stack->size == 1)
		return ;
	else if (stack->size == 2)
		return (operations(SA, stack, NULL));
	small = pos_(smaller, stack);
	big = pos_(bigger, stack);
	if (big.pos == 0)
		operations(RA, stack, NULL);
	else if (big.pos == 1)
		operations(RRA, stack, NULL);
	if (*(int *)see_stack(stack) != small.value)
		operations(SA, stack, NULL);
}

static void	sort_4(t_stack *stack, t_stack *stack_b)
{
	t_pos	small;

	if (stack->size <= 3)
		return (sort_3(stack));
	small = pos_(smaller, stack);
	if (small.pos == 1)
		operations(RA, stack, NULL);
	else if (small.pos == 2)
		loop(RA, 2, stack, NULL);
	else if (small.pos == 3)
		operations(RRA, stack, NULL);
	if (!sorted_stack(stack))
		return ;
	operations(PB, stack, stack_b);
	sort_3(stack);
	operations(PA, stack, stack_b);
}

void	sort_5(t_stack *stack, t_stack *stack_b)
{
	t_pos	small;

	if (stack->size <= 4)
		return (sort4(stack, stack_b));
	small = pos_(smaller, stack);
	if (small.pos == 1)
		operations(RA, stack, NULL);
	else if (small.pos == 2)
		loop(RA, 2, stack, NULL);
	else if (small.pos == 3)
		loop(RRA, 2, stack, NULL);
	else if (small.pos == 4)
		operations(RRA, stack, NULL);
	if (!sorted_stack(stack))
		return ;
	operations(PB, stack, stack_b);
	sort_4(stack, stack_b);
	operations(PA, stack, stack_b);
}
