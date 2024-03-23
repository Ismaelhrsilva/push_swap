/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 17:25:03 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

int *get_number(char *nbr)
{
	long	*number;

	number = malloc(sizeof(int *));
	if (!number)
		exit(EXIT_FAILURE);
	*number = ft_atol(nbr);
	return ((int *)number); 
}

void get_list(t_stack *stack, char *list_int)
{
	char	**list;
	int i;
	int	*number;

	i = 0;
	list = ft_split(list_int, ' ');
	while (list[i])
	{
		number = get_number(list[i]);
		push(stack, number);
		i++;
	}
	return ;
}

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

t_stack *init_stack_b(void)
{
	static t_stack stack_b;

	return (&stack_b);
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
		if (aux->next != NULL)
			ft_putstr(", ");
		aux = aux->next;
	}
	ft_putchar(']');
	ft_putchar('\n');

}
