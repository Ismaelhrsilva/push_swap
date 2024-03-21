/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/21 17:39:06 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static t_stack	*add_node(int value)
{
	t_stack	*a;

	a = malloc(1 * sizeof(t_stack));
	if (a == 0)
		return (0);
	a->value = value;
	a->next = NULL;
	a->previous = NULL;
	return (a);
}

static t_stack	*go_last_stack(t_stack *a)
{
	if (!a)
		return (0);
	else
	{
		while (a->next != NULL)
			a = a->next;
		return (a);
	}
}

static void	add_back(t_stack **a, t_stack *node)
{
	t_stack *temp;

	if (*a == NULL)
		*a = node;
	else
	{
		temp = go_last_stack(*a);
		temp->next = node;
	}
}

static void get_list(t_stack **a, char *list_int)
{
	char	**list;
	int i;
	t_stack	*node;

	i = 0;
	list = ft_split(list_int, ' ');
	while (list[i])
	{
		node = add_node(list[i][0]);
		if (a == NULL)
		{
			add_back(a, node);
		}
		else 
			add_back(a, node);
		i++;
	}
	return ;
}



int	main(int argc, char **argv)
{
	t_pushswap	*pushswap;

	pushswap = NULL;
	pushswap = malloc(1 * sizeof(t_pushswap));
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		get_list(&pushswap->a, argv[1]);
	else
		ft_printf("Aqui");
	return (0);
}
