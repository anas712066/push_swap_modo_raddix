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
# include <stdio.h>

//void    radix_sort(t_list **stack_a);
t_list  *parse_arguments(int argc, char **argv);
int     is_sorted(t_list *stack);
void    print_error_and_exit(void);
int     is_valid_number(char *str);
int     has_duplicates(t_list *head, int num);
void    sort_stack(t_list **stack_a);

#endif
