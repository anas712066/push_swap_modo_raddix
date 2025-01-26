/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:14:14 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/26 20:15:19 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		push(b, pop(a));
		ft_printf("pb\n");
	}
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		push(a, pop(b));
		ft_printf("pa\n");
	}
}

void	ra(t_stack *a)
{
	t_node *top_node, *last_node;
	if (a->size < 2)
		return ;
	top_node = a->top;
	a->top = top_node->next;
	last_node = a->top;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = top_node;
	top_node->next = NULL;
	ft_printf("ra\n");
}
