/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/09 18:31:49 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"

/*static void	push_move(t_move *move, void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
		exit(EXIT_FAILURE);
	ft_lstadd_back(&move->head, node);
	move->size++;
}*/

static int	read_from_stdin(t_stack *stack, t_stack *stack_b, t_move *move)
{
	char *buffer;
	int	result;

	move = 0;
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
			else
				continue ;
		}
		free(buffer);
	}
	return (result);
}

static void	print_stack(t_stack *stack)
{
	t_list	*node;

	if (!stack)
		return ;
	node = stack->head;
	ft_putchar('[');
	while (node != NULL)
	{
		ft_printf("%d", (*(int *)node->content));
		if (node->next != NULL)
			ft_putstr(", ");
		node = node->next;
	}
	ft_putchar(']');
	ft_putchar('\n');
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

t_move	*init_move(void)
{
	static t_move	move;

	return (&move);
}

int	main(int argc, char **argv)
{
	static t_stack	*stack;
	static t_stack	*stack_b;
	static t_move	*move;

	stack = init_stack();
	stack_b = init_stack_b();
	move = init_move();
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
	if (read_from_stdin(stack, stack_b, move))
	{
		print_stack(stack);
		print_stack(stack_b);
		if (sorted_stack(stack) && !stack_b->head)
			ft_printf("OK");
		else
			ft_printf("KO");
	}
	else
		ft_putstr_fd("Error", 2);	
	ft_end_after_begin(stack, stack_b);
	return (0);
}
