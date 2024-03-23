/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 15:03:23 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

void	push(t_stack *stack, void *content)
{
	t_list *node;

	node = ft_lstnew(content);
	if (!node)
		exit(EXIT_FAILURE);
	ft_lstadd_front(&stack->head, node);
	stack->head = node;
	stack->size++;
}

void	*pop(t_stack *stack)
{
	t_list	*temp;
	void	*value;

	if (stack == NULL)
		return (NULL);
	temp = stack->head;
	value = temp->content;
	stack->head = temp->next;
	ft_lstdelone(temp, NULL);
	stack->size--;
	return (value);
}

void	swap(t_stack *stack)
{
	void	*a;
	void	*b;

	if (stack->size < 2)
		return ;
	a = pop(stack);
	b = pop(stack);
	push(stack, a);
	push(stack, b);
}

void	rotate(t_stack *stack)
{
	void	*value;
	t_list	*node;

	if (stack->size < 2)
		return ;
	value = pop(stack);
	node = ft_lstnew(value);
	if (!node)
		exit(EXIT_FAILURE);
	ft_lstadd_back(&stack->head, node);
	stack->head = node;
	stack->size++;
}
