/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_suport_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:59:21 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/09 17:52:58 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"

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
