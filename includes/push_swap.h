/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:36:14 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/29 20:53:43 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/includes/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int		*data;// data es next_node?
	int		top;// top es el numero/value?
}	t_stack;

void	radix_sort(t_stack *a, t_stack *b, int size);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap(t_stack *stack, const char *op);
void	rotate(t_stack *stack, const char *op);
void	reverse_rotate(t_stack *stack, const char *op);
void	push_to(t_stack *src, t_stack *dst, const char *op);
void	print_error_and_exit(void);

#endif
