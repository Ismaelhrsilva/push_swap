/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/21 18:53:37 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

t_stack	*add_node(int value)
{
	t_stack	*a;

	a = malloc(1 * sizeof(t_stack));
	if (a == NULL)
		return (NULL);
	a->value = value;
	a->next = NULL;
	a->previous = NULL;
	return (a);
}

t_stack	*go_last_stack(t_stack *a)
{
	if (!a)
		return (0);
	else
	{
		while (a && a->next != NULL)
			a = a->next;
		return (a);
	}
}

void	add_back(t_stack **a, t_stack *node)
{
	t_stack *temp;

	if (node == NULL)
		return  ;
	if (*a == NULL)
		*a = node;
	else
	{
		temp = go_last_stack(*a);
		//while (temp && temp->next != NULL)
		//	temp = temp->next;
		temp->next = node;
	}
}
