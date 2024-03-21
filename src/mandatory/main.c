/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/21 20:02:10 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"


static void 	push_b(t_stack **a, t_stack **b)
{
	t_stack *temp;
	t_stack *tempb;
	t_stack *tempa;

	if (*a == NULL)
	{
		return ;
	}
	if (*b == NULL)
	{
		temp = *a;
		*a = temp->next;
		*b = temp;
		temp->next = NULL;
		temp->previous = NULL;
		tempa = *a;
		tempa->previous = NULL;
	}
	else
	{
		temp = *a;
		tempb = *b;
		*a = temp->next;
		tempa = *a;
		tempa->previous = NULL;
		temp->next = tempb;
		tempb->previous = temp;
		*b = temp;
	}


}


int	main(int argc, char **argv)
{
	static t_pushswap	*pushswap;

	pushswap = init_pushswap();
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		get_list(&pushswap->a, argv[1]);
	else
		get_list_2(&pushswap->a, argv + 1);
	push_b(&pushswap->a, &pushswap->b);
	push_b(&pushswap->a, &pushswap->b);
	return (0);
}
