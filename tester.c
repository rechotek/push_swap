#include "push_swap.h"

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

void error_free(t_stack **a, char *argv[], bool flag_argc_2)
{
	if (flag_argc_2)
		matrix_free(argv);
	write (2, "Error\n", 6);
	exit(1);
}

int main() {
    // Inicjalizacja zmiennych dla przykładu
    char *argv[] = {"\0", "argument1", "argument2", NULL}; // przykładowa tablica argumentów
    t_stack *a = NULL; // przykładowy stos
    bool flag_argc_2 = 1; // przykładowa flaga

    // Wywołanie funkcji error_free z przykładowymi argumentami
    error_free(&a, argv, flag_argc_2);

    return 0;
}