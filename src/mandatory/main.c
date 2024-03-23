/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/23 14:17:07 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"



int	main(int argc, char **argv)
{
	static t_stack	*stack;

	//stack = init_stack();
	
	stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->size = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(EXIT_FAILURE);
	/*else if (argc == 2)
		get_list(&pushswap->a, argv[1]);*/
	else
		get_list_2(stack, argv + 1);
	print_stack(stack);
	return (0);
}
