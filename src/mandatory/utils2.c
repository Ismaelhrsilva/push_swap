/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 15:20:31 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

void	duplicate_number(t_stack *stack, long *nbr, char **str)
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
