/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:28:56 by ishenriq          #+#    #+#             */
/*   Updated: 2024/03/20 18:57:23 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static void get_list(t_pushswap *pushswap, char *list_int)
{
	pushswap->a = ft_split(list_int, ' ');
	return ;
}



int	main(int argc, char **argv)
{
	t_pushswap	*pushswap;

	if (argc == 1 || (argc == 2 && !argv[1][0])
		return 1;
	else if (argc == 2)
		get_list(pushswap, argv[1]);
	else
		ft_printf("Aqui");
	return (0);
}
