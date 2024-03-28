/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:49:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/28 17:35:33 by ishenriq         ###   ########.fr       */
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

static void	divide_stack(t_stack *stack, t_stack *stack_b, t_aux *aux, int *size)
{
	t_list	*temp;

	temp = stack->head->next;
	//if (*size && *(int *)stack->head->content->value < aux->big.value
	//	&& *(int *)stack->head->next->content->value > aux->big.value
	//	&& *(int *)stack->head->content->value > aux->medium.value)
	if (*size && *(int *)see_stack(stack) < aux->big.value
		&& *((int *)temp->content) > aux->big.value
		&& *(int *)see_stack(stack) > aux->medium.value)
	{
		//push(stack_b, pop(stack));
		operations(PB, stack, stack_b);
		aux->pb++;
		//rotate(stack);
		//rotate(stack_b);
		operations(RA, stack, stack_b);
		operations(RB, stack, stack_b);
		aux->ra++;
		aux->rb++;
		(*size)--;
		return ;
	}
	if (*(int *)see_stack(stack) > aux->big.value)
	{
		//rotate(stack);
		operations(RA, stack, stack_b);
		aux->ra++;
		return ;
	}
	operations(PB, stack, stack_b);
	//push(stack_b, pop(stack));
	aux->pb++;
	if (*(int *)see_stack(stack_b) > aux->medium.value)
	{
		operations(RB, stack, stack_b);
		//rotate(stack_b);
		aux->rb++;
	}
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

	if (size <= 5)
	{
		sort_5(stack, stack_b);
		return ;
	}
	aux = init_aux(stack);
	while (size--)
		divide_stack(stack, stack_b, aux, &size);
	restore_stack(stack, stack_b, aux, &size);
	ft_sort(aux->ra, stack, stack_b, count);
	ft_sort(aux->rb, stack, stack_b, count);
	ft_sort(aux->pb - aux->rb, stack, stack_b, count);
}
