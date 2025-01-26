/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:36:14 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/26 20:12:49 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/includes/ft_printf.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}	t_stack;

void	error_exit(const char *message);
t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		is_sorted(t_stack *stack);
void	radix_sort(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
int		get_max_bits(t_stack *stack);

#endif
