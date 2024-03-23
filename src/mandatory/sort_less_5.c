/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:28:26 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 20:56:49 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

void	sort_3(t_stack *stack)
{
	t_pos	small;
	t_pos	big;

	print_stack(stack);
	if (stack->size == 1)
		return ;
	else if (stack->size ==2)
		return (operations(SA, stack, NULL));
	small = pos_(smaller, stack);
	big = pos_(bigger, stack);
	if (big.pos == 0)
		operations(RA, stack, NULL);
	else if (big.pos == 1)
		operations(RRA, stack, NULL);
	if (*(int *)see_stack(stack) != small.value)
		operations(SA, stack, NULL);
	print_stack(stack);
}
