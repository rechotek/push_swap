/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:53:25 by mrechuli          #+#    #+#             */
/*   Updated: 2024/04/21 13:32:59 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// else if (argc == 2)
// oprocz nazwy mamy tylko jeden argument, ale ten argument moze miec taka
// forme "3 5 42 -1337" i wtedy potrzebuje uzyc splita, aby wyciagnac z niego
// poszczegolny liczby (za pomoca splita zapisuje je w takiej
// formie, aby odzwierciedlic argv, poniewaz w dalszym kroku bede tworzyl stos
// zarowno dla danych wprowadzonych tak: "3 5 42 -1337" jak i tak: 3 5 42 -1337;
// ten drugi przyklad ma z natury forme argv, wiec chcemy uzyskac taka sama forme
// dla liczb uzyskanych za pomoca ft_split)

int main (int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL; // przypisuje NULL do pointerow, any uniknac "segmentation fault" - taka dobra praktyka
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //argc == 1 mowi nam ze mamy tylko nazwe programu; drugi warunek mowi o tym, ze jest jest drugi argument, ale pusty (w obu tych przypadkach zwracamy 1, bo to jest blad)
		return (1);
	else if (argc == 2) // oprocz nazwy mamy tylko jeden argument, ale ten argument moze miec taka forme "3 5 42 -1337"
		argv = ft_split(argv[1], ' '); // tutaj nazywamy tabele liczb, ktora utworzymy za pomoca splita argv, poniewaz linie nizej inicjuje stos i uzywam argv + 1, poniewaz chce od razu dostac sie do liczby - bedzie to dzialo zarowno dla liczb utworzonych w tabeli splitem, jak i dla danych wprowadzonych do programu w wielu stringach
	stack_init(&a, argv + 1, argc == 2); // argv+1, aby zaczac od miejsca gdzie juz powinna znajdowac sie pierwsza liczba
}