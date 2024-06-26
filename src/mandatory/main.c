/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/07 15:14:05 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

t_stack	*init_stack(void)
{
	static t_stack	stack;

	return (&stack);
}

t_stack	*init_stack_b(void)
{
	static t_stack	stack_b;

	return (&stack_b);
}

void	ft_pushswap(t_stack *stack, t_stack *stack_b)
{
	int	count;

	count = 0;
	if (stack->size <= 5)
	{
		sort_5(stack, stack_b);
		return ;
	}
	if (sorted_stack(stack))
		return ;
	ft_sort(stack->size, stack, stack_b, &count);
}

int	main(int argc, char **argv)
{
	static t_stack	*stack;
	static t_stack	*stack_b;

	stack = init_stack();
	stack_b = init_stack_b();
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(EXIT_FAILURE);
	else if (argc == 2)
		get_list(stack, argv[1]);
	else
		get_list_2(stack, argv + 1, argc - 1);
	if (!stack->head)
	{
		ft_putstr_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	if (sorted_stack(stack))
	{
		ft_end_after_begin(stack, stack_b);
		return (0);
	}
	ft_pushswap(stack, stack_b);
	ft_end_after_begin(stack, stack_b);
	return (0);
}
