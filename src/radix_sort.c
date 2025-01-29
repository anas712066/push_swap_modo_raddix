/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:16:01 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/29 16:09:50 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_num(t_stack *a)
{
	int	max_num;
	int	i;

	max_num = a->data[0];
	i = 1;
	while (i <= a->top)
	{
		if (a->data[i] > max_num)
			max_num = a->data[i];
		i++;
	}
	return (max_num);
}

static int	get_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	sort_stack(t_stack *a, t_stack *b, int size, int max_bits)
{
	int	i;
	int	j;
	int	num;

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = a->data[a->top];
            if (((num >> i) & 1) == 1)
                rotate(a, "ra");
            else
                push_to(a, b, "pb");
            j++;
        }
        while (b->top != -1)
            push_to(b, a, "pa");
        i++;
    }
}

void	radix_sort(t_stack *a, t_stack *b, int size)
{
	int	max_num;
	int	max_bits;

	size = a->top + 1;
	max_num = get_max_num(a);
	max_bits = get_max_bits(max_num);
	sort_stack(a, b, size, max_bits);
}
