/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/21 18:58:30 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

void get_list(t_stack **a, char *list_int)
{
	char	**list;
	int i;
	t_stack	*node;

	i = 0;
	list = ft_split(list_int, ' ');
	while (list[i])
	{
		node = add_node(ft_atoi(list[i]));
		ft_printf("%d\n", node->value);
		if (*a == NULL)
		{
			add_back(a, node);
		}
		else 
			add_back(a, node);
		i++;
	}
	return ;
}

void get_list_2(t_stack **a, char **list_int)
{
	int i;
	t_stack	*node;

	i = 0;
	while (list_int[i] != NULL)
	{
		node = add_node(ft_atoi(list_int[i]));
		ft_printf("%d\n", node->value);
		if (*a == NULL)
		{
			add_back(a, node);
		}
		else 
			add_back(a, node);
		i++;
	}
	return ;
}

t_pushswap *init_pushswap(void)
{
	static t_pushswap pushswap;

	return (&pushswap);
}
