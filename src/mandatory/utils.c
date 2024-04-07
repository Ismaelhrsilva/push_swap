/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 15:13:17 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void	ft_end_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	ft_end(t_stack *stack)
{
	t_list	*temp;

	if (!stack->head)
		return ;
	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp->content);
		free(temp);
	}
	stack->head = NULL;
}

void	ft_end_after_begin(t_stack *stack, t_stack *stack_b)
{
	if (stack->head)
		ft_end(stack);
	if (stack_b->head)
		ft_end(stack_b);
}

static void	error(t_stack *stack)
{
	ft_end(stack);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int	check_number(char *nbr)
{
	if (!nbr)
		return (1);
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (!(*nbr))
		return (1);
	while (ft_isdigit(*nbr))
		nbr++;
	if (*nbr)
		return (1);
	return (0);
}

static void	duplicate_number(t_stack *stack, long *nbr, char **str)
{
	t_list	*temp;

	temp = stack->head;
	if (!stack || !nbr)
		return ;
	while (temp)
	{
		if (*(int *)temp->content == *(int *)nbr)
		{
			if (str)
				ft_end_split(str);
			if (nbr)
				free(nbr);
			error(stack);
		}
		else
			temp = temp->next;
	}
}

long	*get_number(t_stack *stack, char *nbr, char **str)
{
	long	*number;

	number = malloc(sizeof(int *));
	if (!number)
		error(stack);
	if (check_number(nbr))
	{
		free(number);
		ft_end_split(str);
		error(stack);
	}
	*number = ft_atol(nbr);
	return (number);
}

void	get_list(t_stack *stack, char *list_int)
{
	char	**list;
	int		i;
	long	*number;

	i = 0;
	list = ft_split(list_int, ' ');
	while (list[i] != NULL)
		i++;
	while (i > 0)
	{
		i--;
		number = get_number(stack, list[i], list);
		if (!number)
		{
			ft_end_split(list);
			error(stack);
		}
		if (*number > N_MAX || *number < N_MIN)
		{
			ft_end_split(list);
			free(number);
			error(stack);
		}
		duplicate_number(stack, number, list);
		push(stack, number);
	}
	ft_end_split(list);
	return ;
}

void	get_list_2(t_stack *stack, char **list_int, int size)
{
	int		i;
	long	*number;

	i = size;
	while (i > 0)
	{
		i--;
		number = get_number(stack, list_int[i], NULL);
		if (!number)
			exit(EXIT_FAILURE);
		if (*number > N_MAX || *number < N_MIN)
		{
			free(number);
			error(stack);
		}
		duplicate_number(stack, number, NULL);
		push(stack, number);
	}
	return ;
}



void	print_stack(t_stack *stack)
{
	t_list	*aux;
	int		number;

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
