/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:43:02 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/31 11:42:58 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_elem **stack)
{
	t_elem	*previous;

	if (!*stack)
		return ;
	while (*stack)
	{
		previous = *stack;
		*stack = (*stack)->next;
		free(previous);
	}
}
