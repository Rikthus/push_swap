/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:08:31 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/28 00:50:09 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	check_caseA(t_elem **a)
{
	t_elem	*comp;

	comp = *a;
	if (comp->rank != 4)
		return (0);
	comp = comp->next;
	if (comp->rank != 1)
		return (0);
	comp = comp->next;
	if (comp->rank != 5)
		return (0);
	comp = comp->next;
	if (comp->rank != 3)
		return (0);
	comp = comp->next;
	if (comp->rank != 2)
		return (0);
	return (1);
}

static	int	check_caseB(t_elem **a)
{
	t_elem	*comp;

	comp = *a;
	if (comp->rank != 4)
		return (0);
	comp = comp->next;
	if (comp->rank != 3)
		return (0);
	comp = comp->next;
	if (comp->rank != 5)
		return (0);
	comp = comp->next;
	if (comp->rank != 2)
		return (0);
	comp = comp->next;
	if (comp->rank != 1)
		return (0);
	return (1);
}

static	void	resolveA(t_elem **a, t_elem **b)
{
	rotate(a);
	rotate(a);
	push(a, b);
	swap(a);
	rev_rotate(a);
	push(b, a);
	rotate(a);
	write(1, "ra\nra\npb\nsa\nrra\npa\nra\n", 23);
}

static	void	resolveB(t_elem **a, t_elem **b)
{
	push(a, b);
	rev_rotate(a);
	rev_rotate(a);
	swap(a);
	rev_rotate(a);
	push(b, a);
	rotate(a);
	rotate(a);
	write(1, "pb\nrra\nrra\nsa\nrra\npa\nra\nra\n", 28);
}

void	small_sort(t_elem **a, t_elem **b, int lst_size)
{
	t_elem	*tmp;

	if (check_caseA(a))
		return (resolveA(a, b));
	if (check_caseB(a))
		return (resolveB(a, b));
	tmp = *a;
	if (lst_size == 5)
		a_to_b(a, b, 5);
	a_to_b(a, b, 4);
	if (!sorted(a))
		tiny_sort(a);
	b_to_a(b, a, 4);
	rotate(a);
	write(1, "ra\n", 3);
	if (lst_size == 5)
	{
		b_to_a(b, a, 5);
		rotate(a);
		write(1, "ra\n", 3);
	}
}
