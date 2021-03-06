/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:24:01 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/31 11:43:21 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	create_elem(t_elem **a, int value)
{
	t_elem	*new_elem;
	t_elem	*elem_iter;

	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return (0);
	new_elem->value = value;
	new_elem->next = NULL;
	if (!*a)
		*a = new_elem;
	else
	{
		elem_iter = *a;
		while (elem_iter->next)
			elem_iter = elem_iter->next;
		elem_iter->next = new_elem;
	}
	return (1);
}

static	void	rank_stack_values(t_elem **stack)
{
	int		i;
	t_elem	*actual;
	t_elem	*to_rank;

	to_rank = *stack;
	while (to_rank)
	{
		i = 0;
		actual = *stack;
		while (actual)
		{
			if (to_rank->value > actual->value)
				i++;
			actual = actual->next;
		}
		to_rank->rank = i;
		to_rank = to_rank->next;
	}
}

int	init(t_elem **a, t_elem **b, int nb_args, char **args)
{
	int	i;

	i = 1;
	*a = NULL;
	*b = NULL;
	while (i < nb_args)
	{
		if (!create_elem(a, ft_atoi(args[i])))
		{
			free_stack(a);
			return (0);
		}
		i++;
	}
	rank_stack_values(a);
	return (1);
}
