/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:00:11 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/24 15:41:56 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;
	
	if (argc < 2)
		return (0);
	else if (!parsing(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	// if (!init(&a, &b, argv[1]))
	// {
	// 	write(2, "Error\n", 6);
	// 	return (2);
	// }
	// swap(&a, &b);
	// free_stack(a);
	return (0);
}