/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 14:06:19 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

/*void get_list(t_stack **a, char *list_int)
{
	char	**list;
	int i;
	t_stack	*node;

	i = 0;
	list = ft_split(list_int, ' ');
	while (list[i])
	{
		node = add_node(ft_atoi(list[i]));
		ft_printf("%d\n", node->value);
		if (*a == NULL)
		{
			add_back(a, node);
		}
		else 
			add_back(a, node);
		i++;
	}
	return ;
}*/

void get_list_2(t_stack *stack, char **list_int)
{
	int i;

	i = 0;
	while (list_int[i] != NULL)
	{
		push(stack, (void *)ft_atol(list_int[i]));
		i++;
	}
	return ;
}


t_stack *init_stack(void)
{
	static t_stack stack;

	return (&stack);
}

void	print_stack(t_stack *stack)
{
	t_list	*node;
	int	number;

	if (!stack)
	{
		ft_putchar('\n');
		return ;
	}
	node = stack->head;
	ft_putchar('[');
	while (node != NULL)
	{
		//ft_putnbr(*(int *)node->content);
		//number = *(int *)node->content;
		number = *(int *)stack->head->content;
		ft_printf("%x", number);
		if (node->next != NULL)
			ft_putstr(", ");
		node = node->next;
	}
	ft_putchar(']');
	ft_putchar('\n');

}
