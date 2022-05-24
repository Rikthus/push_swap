/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:58:29 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/24 16:02:14 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_elem
{
	int	value;
	int	rank;
}	t_elem;

// PARSING
int		parsing(int argc, char **argv);

// UTILS
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif