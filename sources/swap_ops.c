/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:24:19 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/31 11:46:23 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_elem **stack)
{
	t_elem	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	push(t_elem **from, t_elem **to)
{
	t_elem	*tmp_from_next;
	t_elem	*tmp_to;

	if (!*from)
		return ;
	tmp_from_next = (*from)->next;
	tmp_to = *to;
	*to = *from;
	(*to)->next = tmp_to;
	*from = tmp_from_next;
}

void	rotate(t_elem **stack)
{
	t_elem	*first;
	t_elem	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	first = *stack;
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	rev_rotate(t_elem **stack)
{
	t_elem	*before_last;
	t_elem	*last;

	if (!*stack || !(*stack)->next)
		return ;
	before_last = *stack;
	last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
}
