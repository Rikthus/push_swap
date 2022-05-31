/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:47:00 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/31 11:46:49 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(char *str)
{
	int			i;
	long long	nb;
	int			minus;

	i = 0;
	nb = 0;
	minus = 1;
	if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	nb *= minus;
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	sorted(t_elem **stack)
{
	t_elem	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (tmp->rank != i)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	ft_lstsize(t_elem *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
