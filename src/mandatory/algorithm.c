/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:49:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/26 20:03:09 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void	init_aux(t_stack *stack, t_aux *aux)
{
	aux->big = pos_median(bigger, stack, stack->size / 2);
	aux->medium = pos_median(bigger, stack, (stack->size / 4) * 3);
	counters->ra = 0;
	counters->rb = 0;
	counters->pa = 0;
	counters->pb = 0;
}

static void	divide_stack(t_stack *stack, t_stack *stack_b, t_aux *aux, int *size)
{
	if (*size && stack->value < aux->big.value && stack->next->value > aux->big.value
		&& stack->value > aux->medium.value)
	{
		push(stack_b, pop(stack_a));
		aux->pb++;
		rotate(stack);
		rotate(stack_b);
		aux->ra++;
		aux->rb++;
		(*size--);
		return ;
	}
	if (stack->value > aux->big.value)
	{
		rotate(stack);
		aux->ra++;
		return ;
	}
	push(stack_b, pop(stack_a));
	aux->pb++;
	if (stack_b->value > aux->median)
	{
		rotate(stack_b);
		aux->rb++;
	}
}






int	ft_sort(int size, t_stack *stack, t_stack *stack_b, int *count)
{
	t_aux	aux;

	if (size < 8)
	{
		sort_5(stack, stack_b);
		return ;
	}
	aux = init_aux(stack);
	while (size--)
		divide_stack(stack, stack_b, &aux, &size);
	ft_sort(aux.ra, stack, stack_b, count);
	ft_sort(aux.rb, stack, stack_b, count);
	ft_sort(aux.pb - aux.rb, stack, stack_b, count);
}
