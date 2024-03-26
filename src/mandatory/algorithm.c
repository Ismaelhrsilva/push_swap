/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:49:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/26 20:48:25 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void	*init_aux(t_stack *stack, t_aux *aux)
{
	aux->big = pos_median(bigger, stack, stack->size / 2);
	aux->medium = pos_median(bigger, stack, (stack->size / 4) * 3);
	aux->ra = 0;
	aux->rb = 0;
	aux->pa = 0;
	aux->pb = 0;
}

static void	divide_stack(t_stack *stack, t_stack *stack_b, t_aux *aux, int *size)
{
	if (*size && *(int *)stack->head->content->value < aux->big.value
		&& *(int *)stack->head->next->content->value > aux->big.value
		&& *(int *)stack->head->content->value > aux->medium.value)
	{
		push(stack_b, pop(stack));
		aux->pb++;
		rotate(stack);
		rotate(stack_b);
		aux->ra++;
		aux->rb++;
		(*size)--;
		return ;
	}
	if (*(int *)stack->head->content->value > aux->big.value)
	{
		rotate(stack);
		aux->ra++;
		return ;
	}
	push(stack_b, pop(stack));
	aux->pb++;
	if (*(int *)stack_b->head->content->value > aux->medium.value)
	{
		rotate(stack_b);
		aux->rb++;
	}
	return ;
}

static void	restore_stack(t_stack *stack, t_stack *stack_b, t_aux *aux, int *size)
{
	int	rrr;
	int	rrx;

	if (aux->ra > aux->rb)
	{
		rrr = aux->rb;
		rrx = aux->ra - rrr;
		if ((* size) > 0)
			loop(RRA, rrx, stack, NULL);
		else
			loop(RRB, rrr, NULL ,stack_b);
	}
	else
	{
		rrr = aux->ra;
		rrx = aux->rb - rrr;
		if ((* size) > 0)
			loop(RRB, rrx, NULL, stack_b);
		else
			loop(RRB, aux->rb, NULL, stack_b);
	}
	if ((* size) > 0)
	{
		loop(RRA, rrr, stack, NULL);
		loop(RRB, rrr, NULL, stack_b);
	}
}




void	ft_sort(int size, t_stack *stack, t_stack *stack_b, int *count)
{
	t_aux	*aux;

	if (size < 8)
	{
		sort_5(stack, stack_b);
		return ;
	}
	aux = init_aux(stack, aux);
	while (size--)
		divide_stack(stack, stack_b, aux, &size);
	restore_stack(stack, stack_b, aux, &size);
	ft_sort(aux->ra, stack, stack_b, count);
	ft_sort(aux->rb, stack, stack_b, count);
	ft_sort(aux->pb - aux->rb, stack, stack_b, count);
}
