/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 09:59:48 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}


static void	check_number(char *nbr)
{
	if (!nbr)
		error();
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (!(*nbr))
		error();
	while (ft_isdigit(*nbr))
		nbr++;
	if (*nbr)
		error();
}

static void duplicate_number(t_stack *stack, long nbr)
{
	t_list	*temp;

	temp = stack->head;
	if (!stack || !nbr)
		return ;
	while (temp)
	{
		if (*(int *)temp->content == nbr)
			error();
		else
			temp = temp->next;
	}
}

long *get_number(char *nbr)
{
	long	*number;

	number = malloc(sizeof(int *));
	if (!number)
		exit(EXIT_FAILURE);
	check_number(nbr);
	*number = ft_atol(nbr);
	return (number); 
}

void get_list(t_stack *stack, char *list_int)
{
	char	**list;
	int i;
	long	*number;

	i = 0;
	list = ft_split(list_int, ' ');
	while (list[i] != NULL)
		i++;
	while (i > 0)
	{
		i--;
		number = get_number(list[i]);
		if (!number)
			exit(EXIT_FAILURE);
		if (*number > N_MAX || *number < N_MIN)
			error();
		duplicate_number(stack, *number);
		push(stack, number);
	}
	return ;
}

void get_list_2(t_stack *stack, char **list_int, int size)
{
	int i;
	long	*number;

	i = size;
	while (i > 0)
	{
		i--;
		number = get_number(list_int[i]);
		if (!number)
			exit(EXIT_FAILURE);
		if (*number > N_MAX || *number < N_MIN)
			error();
		duplicate_number(stack, *number);
		push(stack, number);
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
