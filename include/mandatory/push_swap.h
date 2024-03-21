/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:32:30 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/20 21:09:15 by ishenriq         ###   ########.fr       */
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
	int	value;
	struct s_stack	*a;
	struct s_stack	*b;
}	t_pushswap;

#endif
