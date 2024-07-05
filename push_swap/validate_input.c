/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:55:26 by jmakkone          #+#    #+#             */
/*   Updated: 2024/06/26 15:12:16 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i + 1] != '\0' && (arg[i] == '+' || arg[i] == '-'))
		i++;
	if (arg[i] == '0' && arg[i + 1] != '\0')
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	nbr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

static int	check_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (nbr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_zero(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i] && arg[i] == '0')
		i++;
	if (arg[i] != '\0')
		return (0);
	return (1);
}

int	is_valid(char **argv)
{
	int	i;
	int	zero_count;

	i = 0;
	zero_count = 0;
	if (!argv || !*argv)
		return (0);
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		zero_count += is_zero(argv[i]);
		i++;
	}
	if (zero_count > 1)
		return (0);
	if (check_duplicates(argv))
		return (0);
	return (1);
}
