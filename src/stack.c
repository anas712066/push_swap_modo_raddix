/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:11:04 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/29 16:01:01 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *stack, int value)
{
	stack->data[++stack->top] = value;
}

int	pop(t_stack *stack)
{
	if (stack->top == -1)
		print_error_and_exit();
	return (stack->data[stack->top--]);
}

void	swap(t_stack *stack, const char *op)
{
	int	temp;

	if (stack->top < 1)
		return ;
	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
	ft_printf("%s\n", op);
}

void	rotate(t_stack *stack, const char *op)
{
	int	temp;
	int	i;

	if (stack->top < 1)
		return ;
	temp = stack->data[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = temp;
	ft_printf("%s\n", op);
}
