/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:23:47 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/31 11:43:40 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	is_all_num(int nb_args, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (i < nb_args)
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && (args[i][j] > '9' || args[i][j] < '0'))
			{
				if (args[i][j] != '-')
					return (0);
			}
			else if (args[i][j] > '9' || args[i][j] < '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static	int	is_all_int(int nb_args, char **args)
{
	int	i;

	i = 1;
	while (i < nb_args)
	{
		if (ft_atoi(args[i]) == 0 && ft_strcmp(args[i], "0") != 0
			&& ft_strcmp(args[i], "-0") != 0)
			return (0);
		i++;
	}
	return (1);
}

static	int	is_no_double(int nb_args, char **args)
{
	int	i;
	int	j;

	i = 1;
	while (i < nb_args)
	{
		j = i + 1;
		while (j < nb_args)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(int nb_args, char **args)
{
	if (!is_all_num(nb_args, args))
		return (0);
	if (!is_all_int(nb_args, args))
		return (0);
	if (!is_no_double(nb_args, args))
		return (0);
	return (1);
}
