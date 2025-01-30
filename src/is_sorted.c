/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:32:50 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/30 00:32:50 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_sorted(t_list *stack)
{
    // Traverse the list and compare each node with the next one
    while (stack && stack->next)
    {
        // If the current node's value is greater than the next node's value, the list is not sorted
        if (*(int *)(stack->content) > *(int *)(stack->next->content))
            return (0); // Return 0 (false) if the list is not sorted
        stack = stack->next; // Move to the next node
    }
    return (1); // Return 1 (true) if the list is sorted
}