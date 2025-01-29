/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:17:44 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/29 16:02:39 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	initialize_stack(t_stack *stack, int size)
{
	stack->data = (int *)malloc(sizeof(int) * size);
	if (!stack->data)
		print_error_and_exit();
	stack->top = -1;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	if (argc < 2)
		return (0);
	initialize_stack(&a, argc - 1);
	initialize_stack(&b, argc - 1);
	i = 1;
	while (i < argc)
	{
		push(&a, ft_atoi(argv[i]));
		i++;
	}
	radix_sort(&a, &b, argc - 1);
	free(a.data);
	free(b.data);
	return (0);
}
