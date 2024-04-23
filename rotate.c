/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:29:54 by mrechuli          #+#    #+#             */
/*   Updated: 2024/04/23 21:00:35 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// przenosze wartosc z gory stosu na dno
// PRZYKLAD
// 4 (P->null, N->8)
// 8 (P->4, N->9)
// 9 (P->8, N->null)
// wytlumaczenie w poszczegolnych wierszach
//
// wynik to ponizszej funkcji:
// 8 (P->null, N->9)
// 9 (P->8, N->4)
// 4 (P->9, N->null)

static void rotate (t_stack **stack) // zrozumiec pointery tutaj
{
	t_stack	*last_node;
	int		x;

	x = stack_len(*stack);
	if (stack == NULL || *stack == NULL || x == 1)
		return ;
	last_node = find_last_node(*stack); // 9
	last_node->next = *stack; // ustawiam wartosc next liczby 9 na poczatek stosu, czyli 4; 9 (P->8, N->4)
	*stack = (*stack)->next; // zmieniam poczatek stosu na liczbe nastepna po poczatku stosu, czyli 4 na 8
	(*stack)->prev = NULL; // ustawiam prev obecnej liczby poczatkowej (8) NULL; 8 (P->null, N->9) - next 9 pozostaje bez mian to samo
	last_node->next->prev = last_node; // ustawiam wartosc prev nastepnej liczbie po ostatniej (4) na ostatnia liczbe (9); 4 (P->9, N->8)
	last_node->next->next = NULL; // ustawiam wartosc next nastepnej liczbie po ostatniej (4) na NULL; 4 (P->9, N->null)
}
