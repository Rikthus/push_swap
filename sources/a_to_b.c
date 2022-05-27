/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:12:34 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/28 00:48:31 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	rt_down(t_elem **a, t_elem **b, int iter, int lst_size)
{
	while (iter < (lst_size + 1))
	{
		rev_rotate(a);
		write(1, "rra\n", 4);
		iter++;
	}
	push(a, b);
	write(1, "pb\n", 3);
}

static	void	rt_up(t_elem **a, t_elem **b, int iter)
{
	while (iter > 1)
	{
		rotate(a);
		write(1, "ra\n", 3);
		iter--;
	}
	push(a, b);
	write(1, "pb\n", 3);
}

void	a_to_b(t_elem **a, t_elem **b, int rk)
{
	int		iter;
	int		lst_size;
	t_elem	*actual;

	actual = *a;
	iter = 1;
	lst_size = ft_lstsize(*a);
	while (actual->rank != rk)
	{
		actual = actual->next;
		iter++;
	}
	if (iter <= (lst_size / 2) || iter == 1)
		rt_up(a, b, iter);
	else
		rt_down(a, b, iter, lst_size);
}
