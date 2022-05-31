/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:30:17 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/31 11:43:50 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	ra(t_elem **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

static	void	pb(t_elem **a, t_elem **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

static	void	pa(t_elem **a, t_elem **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	radix_sort(t_elem **a, t_elem **b, int lst_size, int max_place)
{
	int		i;
	int		j;

	i = 0;
	while (i < max_place)
	{
		j = 0;
		while (j < lst_size)
		{
			if ((((*a)->rank >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
