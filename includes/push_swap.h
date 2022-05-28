/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:58:29 by tulipe            #+#    #+#             */
/*   Updated: 2022/05/28 22:08:54 by tulipe           ###   ########lyon.fr   */
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
int		init(t_elem **a, t_elem **b, int nb_args, char **args);

// SWAP_OPS
void	swap(t_elem **stack);
void	push(t_elem **from, t_elem **to);
void	rotate(t_elem **stack);
void	rev_rotate(t_elem **stack);

// RADIX_SORT
void	radix_sort(t_elem **a, t_elem **b, int lst_size, int max_place);

// CHUNK_SORT
void	chunk_sort(t_elem **a, t_elem **b, int pivot);

// SMALL_SORT
void	small_sort(t_elem **a, t_elem **b, int lst_size);

// A_TO_B
void	a_to_b(t_elem **a, t_elem **b, int rk);

// B_TO_A
void	b_to_a(t_elem **b, t_elem **a, int rk);

// TINY_SORT
void	tiny_sort(t_elem **stack);

// UTILS
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_lstsize(t_elem *lst);
int		sorted(t_elem **stack);

// CLEANER
void	free_stack(t_elem **stack);

#endif
