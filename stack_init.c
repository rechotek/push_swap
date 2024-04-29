/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:20:57 by mrechuli          #+#    #+#             */
/*   Updated: 2024/04/23 18:02:27 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		x;

	num = 0;
	sign = 1;
	x = 0;
	while (str[x] && (str[x] == ' ' || str[x] == '\r' || str[x] == '\t'
			|| str[x] == '\v' || str[x] == '\f' || str[x] == '\n'))
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

void	stack_init(t_stack **a, char *argv[], bool flag_argc_2)
{
	long	nbr;
	int		x;

	x = 0;
	while (argv[x])
	{
		if (error_syntax(argv[x]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[x]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		++x;
	}
	if (flag_argc_2)
		matrix_free(argv);
}
