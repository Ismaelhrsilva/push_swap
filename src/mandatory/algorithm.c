/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:49:14 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/25 21:11:40 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static int	middler(t_stack *stacke)
{
	int	i;
	t_list	temp;
	int	value;

	temp = stack->head;
	while (i < stack->size)
	{
		temp = temp->next;
	}
	value = *(int *)temp->content;
	return (value);
}


static void	init_aux(t_stack *stack, t_aux *aux)
{
	counters->medium = middler(stack);
	counters->ra = 0;
	counters->rb = 0;
	counters->pa = 0;
	counters->pb = 0;
}

int	ft_sort(t_stack *stack, t_stack *stack_b, int *count)
{
	t_aux	aux;

	if (stack->size < 8)
	{
		sort_5(stack, stack_b);
		return ;
	}
	aux = init_aux(stack);

}
