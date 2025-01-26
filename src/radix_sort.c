/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:13:50 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/26 20:15:40 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int		max;
	int		bits;
	t_node	*current;

	max = stack->top->value;
	bits = 0;
	current = stack->top;
	// Encuentra el valor máximo en la pila
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	// Calcula el número de bits necesarios para representar el máximo
	while (max >> bits)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;

	max_bits = get_max_bits(a);
	int i, j, size, num;
	size = a->size;
	for (i = 0; i < max_bits; i++) // Itera sobre cada bit
	{
		j = 0;
		while (j < size)
		{
			num = a->top->value;
			if ((num >> i) & 1) // Si el bit está activado
				ra(a);
			else // Si el bit está desactivado
				pb(a, b);
			j++;
		}
		while (b->size > 0) // Devuelve los elementos de B a A
			pa(a, b);
	}
}
