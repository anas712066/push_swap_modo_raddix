/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:14:27 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/26 20:14:54 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!parse_arguments(a, argc, argv))
		error_exit("Invalid arguments.");
	if (!is_sorted(a))
		radix_sort(a, b);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
