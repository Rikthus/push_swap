/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:08:31 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/31 11:45:25 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	check_case_a(t_elem **a)
{
	t_elem	*tmp;

	tmp = *a;
	if (tmp->rank != 3)
		return (0);
	tmp = tmp->next;
	if (tmp->rank != 0)
		return (0);
	tmp = tmp->next;
	if (tmp->rank != 4)
		return (0);
	tmp = tmp->next;
	if (tmp->rank != 2)
		return (0);
	tmp = tmp->next;
	if (tmp->rank != 1)
		return (0);
	return (1);
}

static	int	check_case_b(t_elem **a)
{
	t_elem	*tmp;

	tmp = *a;
	if (tmp->rank != 3)
		return (0);
	tmp = tmp->next;
	if (tmp->rank != 2)
		return (0);
	tmp = tmp->next;
	if (tmp->rank != 4)
		return (0);
	tmp = tmp->next;
	if (tmp->rank != 1)
		return (0);
	tmp = tmp->next;
	if (tmp->rank != 0)
		return (0);
	return (1);
}

static	void	resolve_a(t_elem **a, t_elem **b)
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

static	void	resolve_b(t_elem **a, t_elem **b)
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

	if (check_case_a(a))
		return (resolve_a(a, b));
	if (check_case_b(a))
		return (resolve_b(a, b));
	tmp = *a;
	if (lst_size == 5)
		a_to_b(a, b, 4);
	a_to_b(a, b, 3);
	if (!sorted(a))
		tiny_sort(a);
	b_to_a(b, a, 3);
	rotate(a);
	write(1, "ra\n", 3);
	if (lst_size == 5)
	{
		b_to_a(b, a, 4);
		rotate(a);
		write(1, "ra\n", 3);
	}
}
