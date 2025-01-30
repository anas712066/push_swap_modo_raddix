/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:16:01 by mumajeed          #+#    #+#             */
/*   Updated: 2025/01/30 03:22:49 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int get_max_num(t_list *stack)
{
    int max = INT_MIN;

    while (stack)
    {
        if (*(int *)(stack->content) > max)
            max = *(int *)(stack->content);
        stack = stack->next;
    }
    return max;
}

// Función auxiliar para obtener el número de bits necesarios para representar el número máximo
static int get_max_bits(int max_num)
{
    int bits = 0;

    while ((max_num >> bits) != 0)
        bits++;
    return bits;
}

// Función para rotar el stack a
static void rotate_a(t_list **stack_a)
{
    if (*stack_a && (*stack_a)->next)
    {
        t_list *tmp = *stack_a;
        *stack_a = (*stack_a)->next;
        tmp->next = NULL;
        ft_lstadd_back(stack_a, tmp);
        printf("ra\n");
    }
}

// Función para empujar del stack a al stack b
static void push_b(t_list **stack_a, t_list **stack_b)
{
    if (*stack_a)
    {
        t_list *tmp = *stack_a;
        *stack_a = (*stack_a)->next;
        tmp->next = *stack_b;
        *stack_b = tmp;
        printf("pb\n");
    }
}

// Función para empujar del stack b al stack a
static void push_a(t_list **stack_a, t_list **stack_b)
{
    if (*stack_b)
    {
        t_list *tmp = *stack_b;
        *stack_b = (*stack_b)->next;
        tmp->next = *stack_a;
        *stack_a = tmp;
        printf("pa\n");
    }
}

// Función para ordenar listas de tamaño 2
static void sort_two(t_list **stack_a)
{
    if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
    {
        // Intercambiar los dos elementos
        t_list *tmp = *stack_a;
        *stack_a = (*stack_a)->next;
        tmp->next = (*stack_a)->next;
        (*stack_a)->next = tmp;
        printf("sa\n");
    }
}

// Función para ordenar listas de tamaño 3
static void sort_three(t_list **stack_a)
{
    int a = *(int *)(*stack_a)->content;
    int b = *(int *)(*stack_a)->next->content;
    int c = *(int *)(*stack_a)->next->next->content;

    if (a > b && b > c) // 3 2 1 -> Necesita "sa" + "rra"
    {
        printf("sa\n");
        printf("rra\n");
    }
    else if (a > c && c > b) // 3 1 2 -> "ra"
    {
        printf("ra\n");
    }
    else if (b > a && a > c) // 2 3 1 -> "rra"
    {
        printf("rra\n");
    }
    else if (b > c && c > a) // 2 1 3 -> "sa"
    {
        printf("sa\n");
    }
    else if (c > a && a > b) // 1 3 2 -> "sa" + "ra"
    {
        printf("sa\n");
        printf("ra\n");
    }
}

// Función para implementar el algoritmo Radix Sort
static void radix_sort(t_list **stack_a)
{
    t_list *stack_b = NULL;
    int max_num = get_max_num(*stack_a); // Obtener el número máximo en el stack
    int max_bits = get_max_bits(max_num); // Obtener el número de bits necesarios para representar el número máximo
    int size = ft_lstsize(*stack_a); // Obtener el tamaño del stack
    int i = 0;

    // Bucle para cada bit desde el menos significativo hasta el más significativo
    while (i < max_bits)
    {
        int j = 0;
        // Bucle para cada número en el stack
        while (j < size)
        {
            // Comprobar el valor del bit actual (i) del número en el nodo actual
            if (((*(int *)(*stack_a)->content >> i) & 1) == 1)
            {
                rotate_a(stack_a); // Rotar el stack a si el bit es 1
            }
            else
            {
                push_b(stack_a, &stack_b); // Mover al stack b si el bit es 0
            }
            j++;
        }
        // Mover todos los elementos de nuevo al stack a
        while (stack_b)
        {
            push_a(stack_a, &stack_b);
        }
        i++;
    }
}

// Función principal para ordenar el stack
void sort_stack(t_list **stack_a)
{
    if (is_sorted(*stack_a)) // Si ya está ordenado, no hacer nada
        return;

    int size = ft_lstsize(*stack_a);

    if (size == 2)
    {
        sort_two(stack_a);
        return;
    }
    else if (size == 3)
    {
        sort_three(stack_a);
        return;
    }

    radix_sort(stack_a); // Para listas más grandes
}