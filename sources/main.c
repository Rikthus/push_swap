/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:00:11 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/26 10:15:58 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	test_stack(t_elem **stack)
{
	t_elem	*actual;

	if (!*stack)
		return ;
	actual = *stack;
	while (actual)
	{
		printf("\nvalue: %d\nrank: %d\n", actual->value, actual->rank);
		actual = actual->next;
	}
}

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
	if (!init(&a, argc, argv))
	{
		write(2, "Error\n", 6);
		return (2);
	}
	// swap(&a, &b);
	test_stack(&a);
	free_stack(&a);
	return (0);
}