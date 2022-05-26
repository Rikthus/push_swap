/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:58:29 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/26 10:58:37 by tulipe           ###   ########lyon.fr   */
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
	int				value;
	int				rank;
	struct s_elem	*next;
}	t_elem;

// PARSING
int		parsing(int argc, char **argv);

// INIT
int	init(t_elem **a, t_elem **b, int nb_args, char **args);

// SWAP_OPS
void	swap(t_elem **stack);
void	push(t_elem **from, t_elem **to);
void	rotate(t_elem **stack);
void	rev_rotate(t_elem **stack);

// UTILS
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);

// CLEANER
void	free_stack(t_elem **stack);

#endif