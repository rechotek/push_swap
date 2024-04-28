/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:20:57 by mrechuli          #+#    #+#             */
/*   Updated: 2024/04/28 16:27:15 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_atoi(const char *str) // dlaczego static i const?
{
	int	num;
	int		sign;
	int		x;

	num = 0;
	sign = 1;
	x = 0;

	while (str[x] && (str[x] == ' ' || str[x] == '\r' || str[x] == '\t' || str[x] == '\v' || str[x] == '\f' || str[x] == '\n'))
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		num = (num * 10) + (str[x] - '0');
		x++;
	}
	return (num * sign);
}

// sprawdzam czy dany znak jest liczba

int	ft_isdigit(int x)
{
	if (x >= '0' && x <= '9')
		return (true);
	return (false);
}

// sprawdzam czy podana liczba jest w zakresie inta

bool	is_int(char *arg)
{
	long long	num;
	int			sign;

	sign = 1;
	
	if (*arg == '\0')
		return (false);
	while (*arg == ' ' || *arg == '\r' || *arg == '\t' || *arg == '\v' || *arg == '\f' || *arg == '\n')
		arg++;
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
		if (*arg == '\0')
			return (false);
	}
	num = 0;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		num = num * 10 + (*arg - '0'); // tutaj tworze po prostu liczbe wkladajac w wolne miejsce dziesietnych dana cyfre
		if (((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN)))
			return (false);
		arg++;
	}
	return (true);
}

// Tworzac stack tworzymy go z dwoch opcji wprowadzonych danych:
// - "2 5 42 -1337" (ta opcja jest przeksztalcana za pomoc splita w tabele stringow, gdzie na pierwszym miejscu jest '\0')
// - 2 5 42 -1337 (ta opcja na pierwszym miejscu ma nazwe programu wiec to co nas nie interesuje)
// W obu tych przypadkach mamy tabele stringow, gdzie na pierwszej pozycji mamy cos czego nie chcemy
// dlatego przy inicjalizacji w main jest argv + 1.
// I wykonujac stack_init przechodzimy przez kazdy argument argv,
// sprawdzamy go pod katem bledow i na koncu umieszczamy go w stosie,
// za pomoca append_node.

void stack_init(t_stack **a, char *argv[], bool flag_argc_2)
{
	long	nbr;

	while (*argv)
	{
		if (error_syntax(*argv)) // jezeli warunek bledu jest true (czyli jest prawdziwy) to zwraca blad; sprawdza czy nie ma bledow jak, np. inne znaki niz cyfry, '+' i '-' lub znak '+' i '-' po ktorych nie ma nic
			error_free(a, argv, flag_argc_2); // jesli warunek jest spelniony to wypuszcza blad
		if (!is_int(*argv)) // sprawdzam czy liczba miesci sie w zakresie INT, jesli nie to wywali blad
			error_free(a, argv, flag_argc_2);
		nbr = ft_atoi(*argv);
		if (error_repetition(*a, nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, nbr); // (int)nbr, poniewaz przekastowuje wartosc long na int
		argv++;
	}
	if (flag_argc_2)
		matrix_free(argv);
}

// int main (void)
// {
// 	t_stack *a;
// 	a = NULL;

// 	char *v[5] = {v[0] = "\0", v[1] = "42", v[2] = "-2147483649", v[3] = "-21", v[4] = NULL};
// 	stack_init(&a, v+1, false);
// 	while (a)
// 	{
// 		printf("\n%d, \t node with address %p\n", a->value, a);
// 		a = a->next;
// 	}
// }
