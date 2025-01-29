/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:14:31 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/29 16:02:10 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to(t_stack *src, t_stack *dst, const char *op)
{
	if (src->top == -1)
		return ;
	push(dst, pop(src));
	ft_printf("%s\n", op);
}
