/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:30:37 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/23 13:22:59 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*parse_multiple_arguments(char **av, size_t array_count)
{
	int		*nbrs;
	size_t	i;

	nbrs = malloc(sizeof(int) * array_count);
	if (!nbrs)
		return (NULL);
	i = 0;
	while (i < array_count)
	{
		if (!is_valid_number(av[i + 1]) || \
		!ft_safe_atoi(av[i + 1], &nbrs[i]))
		{
			free(nbrs);
			return (NULL);
		}
		i++;
	}
	return (nbrs);
}

int	*parse_one_argument(char **av, size_t *array_count)
{
	char	**input;
	int		*nbrs;
	size_t	i;

	*array_count = input_count(av[1], ' ');
	input = ft_split(av[1], ' ');
	if (!input)
		return (NULL);
	nbrs = malloc(sizeof(int) * (*array_count));
	if (!nbrs)
		return (free_array(*array_count, input));
	i = 0;
	while (i < *array_count)
	{
		if (!is_valid_number(input[i]) || \
		!ft_safe_atoi(input[i], &nbrs[i]))
		{
			free(nbrs);
			free_array(*array_count, input);
			return (NULL);
		}
		i++;
	}
	free_array(*array_count, input);
	return (nbrs);
}

size_t	input_count(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

int	is_valid_number(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_safe_atoi(const char *str, int *out)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		n = n * 10 + (*str - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && (-n < INT_MIN)))
			return (0);
		str++;
	}
	*out = (int)(n * sign);
	return (1);
}
