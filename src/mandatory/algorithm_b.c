/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:49:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/28 19:58:01 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static t_aux	*init_aux(t_stack *stack)
{
	t_aux *aux;

	aux = malloc(sizeof(t_aux));
	if (!aux)
		return (0);
	aux->big = pos_median(bigger, stack, stack->size / 2);
	aux->medium = pos_median(bigger, stack, (stack->size / 4) * 3);
	aux->ra = 0;
	aux->rb = 0;
	aux->pa = 0;
	aux->pb = 0;
	return (aux);
}

static void	divide_stack_b(t_stack *stack, t_stack *stack_b, t_aux *aux, int *size)
{
	t_list	*temp;

	temp = stack_b->head->next;
	if (*size && *(int *)see_stack(stack_b) >= aux->medium.value
		&& *((int *)temp->content) <= aux->medium.value
		&& *(int *)see_stack(stack_b) <= aux->big.value)
	{
		//push(stack_b, pop(stack));
		operations(PA, stack, stack_b);
		aux->pa++;
		//rotate(stack);
		//rotate(stack_b);
		operations(RA, stack, stack_b);
		operations(RB, stack, stack_b);
		aux->ra++;
		aux->rb++;
		(*size)--;
		return ;
	}
	if (*(int *)see_stack(stack_b) <= aux->medium.value)
	{
		//rotate(stack);
		operations(RB, stack, stack_b);
		aux->rb++;
		return ;
	}
	operations(PA, stack, stack_b);
	//push(stack_b, pop(stack));
	aux->pa++;
	if (*(int *)see_stack(stack) <= aux->big.value)
	{
		operations(RA, stack, stack_b);
		//rotate(stack_b);
		aux->ra++;
	}
}

static void	restore_stack_b(t_stack *stack, t_stack *stack_b, t_aux *aux, int *size)
{
	int	rrr;
	int	rrx;

	if (aux->ra > aux->rb)
	{
		rrr = aux->rb;
		rrx = aux->ra - rrr;
		loop(RRA, rrx, stack, NULL);
	}
	else
	{
		rrr = aux->ra;
		rrx = aux->rb - rrr;
		if ((* size) > 0)
		loop(RRB, rrx, NULL, stack_b);
	}
	loop(RRA, rrr, stack, NULL);
	loop(RRB, rrr, NULL, stack_b);
}

void	ft_sort_b(int size, t_stack *stack, t_stack *stack_b, int *count)
{
	t_aux	*aux;

	if (size <= 5)
	{
		sort_5(stack, stack_b);
		ft_printf("Passei aqui \n");
		return ;
	}
	aux = init_aux(stack_b);
	while (size--)
		divide_stack_b(stack, stack_b, aux, &size);
	ft_sort(aux->pa - aux->ra, stack, stack_b, count);
	restore_stack_b(stack, stack_b, aux, &size);
	ft_sort(aux->ra, stack, stack_b, count);
	ft_sort_b(aux->rb, stack, stack_b, count);
}
