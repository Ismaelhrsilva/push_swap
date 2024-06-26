/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:49:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 16:33:04 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void	divide_stack_b_aux(t_stack *stack, t_stack *stack_b, t_aux *aux)
{
	if (*(int *)see_stack(stack_b) <= aux->medium)
	{
		operations(RB, stack, stack_b);
		aux->rb++;
		return ;
	}
	operations(PA, stack, stack_b);
	aux->pa++;
	if (*(int *)see_stack(stack) <= aux->big)
	{
		operations(RA, stack, stack_b);
		aux->ra++;
	}
}

static void	divide_stack_b(t_stack *stack, t_stack *stack_b, t_aux *aux,
			int *size)
{
	t_list	*temp;

	temp = stack_b->head->next;
	if (*size && *(int *)see_stack(stack_b) >= aux->medium
		&& *((int *)temp->content) <= aux->medium
		&& *(int *)see_stack(stack_b) <= aux->big)
	{
		operations(PA, stack, stack_b);
		aux->pa++;
		operations(RR, stack, stack_b);
		aux->ra++;
		aux->rb++;
		(*size)--;
		return ;
	}
	divide_stack_b_aux(stack, stack_b, aux);
}

static void	restore_stack_b(t_stack *stack, t_stack *stack_b, t_aux *aux)
{
	int	rrr;
	int	rrx;

	if (aux->ra > aux->rb)
	{
		rrr = aux->rb;
		rrx = aux->ra - rrr;
		loop(RRA, rrx, stack, stack_b);
	}
	else
	{
		rrr = aux->ra;
		rrx = aux->rb - rrr;
		loop(RRB, rrx, stack, stack_b);
	}
	loop(RRR, rrr, stack, stack_b);
}

void	ft_sort_b(int size, t_stack *stack, t_stack *stack_b, int *count)
{
	t_aux	*aux;

	(*count)++;
	if (size <= NUMBER)
	{
		sort_handler(stack, stack_b, STACK_B, size);
		return ;
	}
	aux = init_aux(stack_b, size);
	while (size--)
		divide_stack_b(stack, stack_b, aux, &size);
	ft_sort(aux->pa - aux->ra, stack, stack_b, count);
	restore_stack_b(stack, stack_b, aux);
	ft_sort(aux->ra, stack, stack_b, count);
	ft_sort_b(aux->rb, stack, stack_b, count);
	free(aux);
}
