/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:03:16 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/28 21:45:44 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	push_biggest(t_elem **a, t_elem **b)
{
	t_elem	*tmp;
	int		lst_size;

	tmp = *b;
	lst_size = ft_lstsize(*b) - 1;
	while (*b)
	{
		b_to_a(b, a, lst_size);
		lst_size--;
	}
}

void	chunk_sort(t_elem **a, t_elem **b, int pivot)
{
	t_elem	*tmp;
	int		base_pivot;

	tmp = *a;
	base_pivot = pivot;
	while (*a)
	{
		if (tmp->rank < pivot)
		{
			a_to_b(a, b, tmp->rank);
			tmp = *a;
		}
		else
			tmp = tmp->next;
		if (!tmp)
		{
			tmp = *a;
			pivot += base_pivot;
		}
	}
	push_biggest(a, b);
}
