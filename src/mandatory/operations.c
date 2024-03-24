/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:13:30 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 21:20:30 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

void	operations(t_operations operations, t_stack *stack, t_stack *stack_b)
{
	if (operations & SA || operations & SS)
		swap(stack);
	if (operations & SB || operations & SS)
		swap(stack_b);
	if ((operations & PA) && stack_b->size)
		push(stack, pop(stack_b));
	if ((operations & PB && stack->size)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  && stack->size)
		push(stack_b, pop(stack));
	if (operations & RA || operations & RR)
		rotate(stack);
	if (operations & RB || operations & RR)
		rotate(stack_b);
	if (operations & RRA || operations & RRR)
		reverse_rotate(stack);
	if (operations & RRB || operations & RRR)
		reverse_rotate(stack_b);
}

void	loop(t_operations operation, long x, t_stack *stack, t_stack *stack_b)
{
	long	i;

	i = 0;
	while (i < x)
	{
		operations(operation, stack, stack_b);
		i++;
	}
}
