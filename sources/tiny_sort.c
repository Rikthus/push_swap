/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:44:54 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/31 11:46:36 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	sort_one_case(t_elem **stack)
{
	t_elem	*tmp;

	tmp = *stack;
	if (tmp->next->rank == 2)
	{
		rev_rotate(stack);
		write(1, "rra\n", 4);
	}
	else
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
}

static	void	sort_two_case(t_elem **stack)
{
	t_elem	*tmp;

	tmp = *stack;
	if (tmp->next->rank == 0)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}
	else
	{
		swap(stack);
		rev_rotate(stack);
		write(1, "sa\nrra\n", 7);
	}
}

void	tiny_sort(t_elem **stack)
{
	if ((*stack)->rank == 0)
	{
		rev_rotate(stack);
		swap(stack);
		write(1, "rra\nsa\n", 7);
	}
	else if ((*stack)->rank == 1)
		sort_one_case(stack);
	else
		sort_two_case(stack);
}
