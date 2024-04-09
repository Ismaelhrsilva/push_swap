/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/09 19:17:24 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"

static int	read_from_stdin(t_stack *stack, t_stack *stack_b)
{
	char *buffer;
	int	result;

	result = 1;
	while(1)
	{
		buffer = get_next_line(STDIN_FILENO);
		if (!buffer)
			break ;
		if (!movement(stack, stack_b, buffer))
		{
			if (result == 1)
				result = 0;
		}
		free(buffer);
	}
	if (!buffer)
		free(buffer);
	return (result);
}

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
	if (read_from_stdin(stack, stack_b))
	{
		if (sorted_stack(stack) && !stack_b->head)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_putstr_fd("Error", 2);	
	ft_end_after_begin(stack, stack_b);
	return (0);
}
