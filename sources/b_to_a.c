/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:12:20 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/28 00:50:52 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rt_down(t_elem **b, t_elem **a, int iter, int lst_size)
{
	while (iter < (lst_size + 1))
	{
		rev_rotate(b);
		write(1, "rrb\n", 4);
		iter++;
	}
	push(b, a);
	write(1, "pa\n", 3);
}

static void	rt_up(t_elem **b, t_elem **a, int iter)
{
	while (iter > 1)
	{
		rotate(b);
		write(1, "rb\n", 3);
		iter--;
	}
	push(b, a);
	write(1, "pa\n", 3);
}

void	b_to_a(t_elem **b, t_elem **a, int rk)
{
	int iter;
	int lst_size;
	t_elem *actual;

	actual = *b;
	iter = 1;
	lst_size = ft_lstsize(*b);
	while (actual->rank != rk)
	{
		actual = actual->next;
		iter++;
	}
	if (iter <= (lst_size / 2) || iter == 1)
		rt_up(b, a, iter);
	else
		rt_down(b, a, iter, lst_size);
}
