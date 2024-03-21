/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:32:30 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/21 18:53:52 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"


typedef struct s_stack
{
	int	value;
	struct s_stack *next;
	struct s_stack *previous;
}	t_stack;

typedef struct s_pushswap
{
	struct s_stack	*a;
	struct s_stack	*b;
}	t_pushswap;

t_stack	*add_node(int value);
void	add_back(t_stack **a, t_stack *node);
t_stack	*go_last_stack(t_stack *a);

#endif
