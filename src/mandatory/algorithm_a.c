/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:49:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 15:26:35 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void	divide_stack(t_stack *stack, t_stack *stack_b, t_aux *aux, int *size)
{
	t_list	*temp;

	temp = stack->head->next;
	if (*size && *(int *)see_stack(stack) < aux->big &&
		*((int *)temp->content) > aux->big &&
		*(int *)see_stack(stack) > aux->medium)
	{
		operations(PB, stack, stack_b);
		aux->pb++;
		operations(RR, stack, stack_b);
		aux->ra++;
		aux->rb++;
		(*size)--;
		return ;
	}
	if (*(int *)see_stack(stack) > aux->big)
	{
		operations(RA, stack, stack_b);
		aux->ra++;
		return ;
	}
	operations(PB, stack, stack_b);
	aux->pb++;
	if (*(int *)see_stack(stack_b) > aux->medium)
	{
		operations(RB, stack, stack_b);
		aux->rb++;
	}
}

static void	restore_stack(t_stack *stack, t_stack *stack_b, t_aux *aux,
				int *size)
{
	int	rrr;
	int	rrx;

	if (aux->ra > aux->rb)
	{
		rrr = aux->rb;
		rrx = aux->ra - rrr;
		if ((*size) > 0)
			loop(RRA, rrx, stack, stack_b);
		else
			loop(RRB, rrr, stack, stack_b);
	}
	else
	{
		rrr = aux->ra;
		rrx = aux->rb - rrr;
		if ((*size) > 0)
			loop(RRB, rrx, stack, stack_b);
		else
			loop(RRB, aux->rb, stack, stack_b);
	}
	if ((*size) > 0)
		loop(RRR, rrr, stack, stack_b);
}

void	ft_sort(int size, t_stack *stack, t_stack *stack_b, int *count)
{
	t_aux	*aux;

	if (size <= NUMBER)
	{
		sort_handler(stack, stack_b, STACK_A, size);
		return ;
	}
	aux = init_aux(stack, size);
	while (size--)
		divide_stack(stack, stack_b, aux, &size);
	restore_stack(stack, stack_b, aux, count);
	ft_sort(aux->ra, stack, stack_b, count);
	ft_sort_b(aux->rb, stack, stack_b, count);
	ft_sort_b(aux->pb - aux->rb, stack, stack_b, count);
	free(aux);
	return ;
}
