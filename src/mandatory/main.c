/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 17:14:29 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void	ft_pushswap(t_stack *stack, t_stack *stack_b)
{
	ft_printf("Começa aqui a ordenação\n");
	ft_printf("Stack A --> %d\n", sorted_stack(stack));
	ft_printf("Stack B --> %d\n", sorted_stack(stack_b));
}

int	main(int argc, char **argv)
{
	static t_stack	*stack;
	static t_stack	*stack_b;

	stack = init_stack();
	stack_b = init_stack();
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(EXIT_FAILURE);
	else if (argc == 2)
		get_list(stack, argv[1]);
	else
		get_list_2(stack, argv + 1);
	if (!stack->head)
	{
		ft_putstr_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	ft_pushswap(stack, stack_b);
	print_stack(stack);
	rotate(stack);
	print_stack(stack);
	reverse_rotate(stack);
	print_stack(stack);
	swap(stack);
	print_stack(stack);
	pop(stack);
	print_stack(stack);

	return (0);
}
