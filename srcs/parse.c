/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:42:01 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/23 12:57:46 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	convert(const char *s, int *n)
{
	int		i;
	long	tmp;

	i = 0;
	*n = 1;
	tmp = 0;
	if (s[i] == '-')
		*n = -1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	while (s[i] == '0')
		++i;
	if (ft_strlen(&s[i]) > 10 || (ft_strlen(&s[i]) == 0 && s[i - 1] != '0'))
		return (false);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (false);
		tmp = tmp * 10 + (s[i] - '0');
		++i;
	}
	if ((tmp * *n) > INT_MAX || (tmp * *n) < INT_MIN)
		return (false);
	*n = tmp * *n;
	return (true);
}

bool	is_in_stack(const t_stack stack, const int n)
{
	int	i;

	i = 0;
	while (i < stack.len)
	{
		if (stack.value[i] == n)
			return (true);
		++i;
	}
	return (false);
}

char	***parse_args(const int argc, char **argv)
{
	char	***parsed;
	int		i;

	i = 1;
	parsed = ft_calloc(argc, sizeof(char **));
	parsed[argc - 1] = NULL;
	while (argc > i)
	{
		parsed[i - 1] = ft_split(argv[i], ' ');
		i++;
	}
	return (parsed);
}
