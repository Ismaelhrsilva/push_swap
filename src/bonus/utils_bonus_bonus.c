/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 16:32:51 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"

void	ft_end_split(char **str)
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

void	ft_end(t_stack *stack)
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

void	error(t_stack *stack)
{
	ft_end(stack);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	check_number(char *nbr)
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
