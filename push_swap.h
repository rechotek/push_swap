/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:24:52 by mrechuli          #+#    #+#             */
/*   Updated: 2024/04/21 17:13:53 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>

// w tym miejscu definiuje cala strukture listy; umiescilem ja w bibliotece,
// aby miec do niej dostep przy uzywaniu dowolnej funkcji
typedef struct s_stack
{
	int		value;
	int		current_position;
	int		final_index;
	int		push_price;
	bool	above_median; // bool to zmienna, ktora obluguje tylko warunek true/false
	bool 	cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack; // dzieki typedef na poczatku, zamiast pisac "struct s_stack" wystarczy ze napisze t_stack

// Ogarnia kiedy do programu wprowadzimy argc == 2
char **ft_split(char *str, char separator);

// Bledy
int error_repetition(t_stack *a, int nbr);
int error_syntax(char *str);
void error_free(t_stack **a, char *argv[], bool flag_argc_2);
void matrix_free (char *argv[]);


// Tworzenie stosu
void stack_init(t_stack **a, char *argv[], bool flag_argc_2);

// Linked list
void append_node(t_stack **stack, int nbr);



#endif