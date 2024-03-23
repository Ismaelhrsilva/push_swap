/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 14:33:49 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static int *get_number(char *nbr)
{
	long	*number;

	number = malloc(sizeof(int *));
	if (!number)
		exit(EXIT_FAILURE);
	*number = ft_atol(nbr);
	return ((int *)number); 
}

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
	int	*number;

	i = 0;
	while (list_int[i] != NULL)
	{
		number = get_number(list_int[i]);
		if (!number)
			exit(EXIT_FAILURE);
		push(stack, number);
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
	t_list	*aux;
	int	number;

	if (!stack)
	{
		ft_putchar('\n');
		return ;
	}
	aux = stack->head;
	ft_putchar('[');
	while (aux)
	{
		number = *((int *)aux->content);
		ft_putnbr_fd(number, 1);
		//number = *(int *)stack->head->content;
		if (aux->next != NULL)
			ft_putstr(", ");
		aux = aux->next;
	}
	ft_putchar(']');
	ft_putchar('\n');

}
