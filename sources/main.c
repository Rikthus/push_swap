/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:00:11 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/28 01:37:46 by tulipe           ###   ########lyon.fr   */
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

static	void	mini_sort(t_elem **a, t_elem **b, int lst_size)
{
	(void)lst_size;
	(void)b;
	if (lst_size == 2)
	{
		write(1, "ra\n", 3);
		rotate(a);
	}
	else if (lst_size == 3)
		tiny_sort(a);
	// else
	// 	small_sort(a, b, lst_size);
}

static	int	get_max_place(int max_rank)
{
	int	i;
	
	i = 0;
	while ((max_rank >> i) != 0)
		i++;
	return (i);
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
		return (0);
	}
	if (!init(&a, &b, argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc < 7 && !sorted(&a))
		mini_sort(&a, &b, argc - 1);
	else if (!sorted(&a))
		radix_sort(&a, &b, argc - 1, get_max_place(argc - 2));
	test_stack(&a);
	free_stack(&a);
	return (0);
}