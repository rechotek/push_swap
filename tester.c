#include <stdio.h>

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

int main (void)
{
	char str[] = "+1337";
	printf ("%d\n", error_syntax(str));
	return (0);
}