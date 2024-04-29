/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:11:54 by mrechuli          #+#    #+#             */
/*   Updated: 2024/04/21 17:29:43 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char separator)
{
	int	count;
	int	k;

	count = 0;
	while (*str)
	{
		k = 0;
		while (*str == separator && *str)
			str++;
		while (*str != separator && *str)
		{
			if (k == 0)
			{
				count++;
				k = 1;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	char		*next_str;
	int			len;
	int			x;
	static int	index = 0;

	len = 0;
	x = 0;
	while (str[index] == separator)
		index++;
	while ((str[index + len] != separator) && str[index + len])
		len++;
	next_str = malloc(sizeof(char) * (size_t)(len) + 1);
	if (next_str == NULL)
		return (NULL);
	while ((str[index] != separator) && str[index])
		next_str[x++] = str[index++];
	next_str[x] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		words_num;
	char	**strings;
	int		x;

	x = 0;
	words_num = count_words(str, separator);
	if (!words_num)
		exit (1);
	strings = malloc(sizeof(char *) * (size_t)(words_num + 2));
	if (strings == NULL)
		return (NULL);
	while (words_num-- >= 0)
	{
		if (x == 0)
		{
			strings[x] = malloc(sizeof(char));
			if (strings[x] == NULL)
				return (NULL);
			strings[x++][0] = '\0';
			continue ;
		}
		strings[x++] = get_next_word (str, separator);
	}
	strings[x] = NULL;
	return (strings);
}
