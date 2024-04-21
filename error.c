/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:34:26 by mrechuli          #+#    #+#             */
/*   Updated: 2024/04/21 17:55:10 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// matrix zwalnia pamiec dla tablicy, ktora stworzylem podczas pracy
// funkcji ft_split. Dlatego w mainie jest stack_init(&a, argv + 1, argc == 2)
// Ostatni warunek argc == 2, sprawdza wlasnie czy mam
// do czynienia z przypadkiem, w ktorym wprowadzilismy tylko jeden argument
// do programu. A jak jest argc == 2, to uzywam ft_split, czyli
// zawsze jak jest argc == 2, to tworze nowa tabele w ft_split.

// nie do konca rozumiem w jaki sposob dziala ta funkcja, a juz zupelnie nie wiem dlaczego x = -1

void matrix_free (char *argv[])
{
	int x;

	x = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[x])
		free(argv[x++]);
	free(argv - 1);
}

// Uwalniam pamiec w stosie a. Jezeli stack jest NULL to zwracam 0.
// W innym przypadku do zmiennej current przypisuje wskaznik na stos a.
// Dopoki nie dojde do konca stosu to w kazdej petli do zmiennej
// tymczasowej tmp przypisuje wartosc kolejnego miejsca w stacku.
// Uwalniam pamiec w aktualnym miejscu w stacku. Przypisuje cuurent
// wartosc z tmp. I tak do konca stosu.

void stack_free(t_stack **stack)
{
	t_stack *tmp;
	t_stack *current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next; // przypisuje current nastepne miejsce w stacku
		free(current); // uwalniam pamiec z aktualnego miejsca
		current = tmp; // przypisuje current wartosc z tmp
	}
	*stack = NULL;
}

void error_free(t_stack **a, char *argv[], bool flag_argc_2)
{
	stack_free(a); // skoro jest blad to musze uwolnic pamiec dla stosu a
	if (flag_argc_2) // jezeli argc == 2 (bo taki warunek "zaszylem" w tej fladze) to zwalniam pamiec dla tablicy, ktora stworzylem za pomoca ft_split
		matrix_free(argv);
	write (2, "Error\n", 6);
	exit(1);
}

int error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1); // sprawdza czy jakis znak jest inny od '-' '+' lub cyfry
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1); // sprawdza czy po '+' lub '-' jest cyfra
	str++;
	while (*str) // petla dziala dopoki wartosc na ktora wskazuje str po inkrementacji nie jest 0
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int error_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}