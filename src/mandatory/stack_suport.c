/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_suport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:59:21 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 14:28:36 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

int	sorted_stack(t_stack *stack)
{
	t_list	*temp;
	int		size;

	temp = stack->head;
	if (!temp)
		return (0);
	size = stack->size - 1;
	while (size > 0)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
		size--;
	}
	return (1);
}

t_pos	pos_(t_weight weight, t_stack *stack)
{
	t_pos	pos;
	t_list	*temp;
	long	number;
	int		actual;

	temp = stack->head;
	pos.value = *(int *)temp->content;
	pos.pos = 0;
	number = 0;
	while (temp != NULL)
	{
		actual = *(int *)temp->content;
		if (weight(actual, pos.value))
		{
			pos.value = actual;
			pos.pos = number;
		}
		temp = temp->next;
		number++;
	}
	return (pos);
}

int	bigger(int a, int b)
{
	if (a > b)
		return (1);
	else
		return (0);
}

int	smaller(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (0);
}

void	*see_stack(t_stack *stack)
{
	if (!stack->size)
		return (NULL);
	return (stack->head->content);
}
