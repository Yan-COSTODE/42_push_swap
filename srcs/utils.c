/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <ycostode@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:00:44 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/23 12:20:08 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_msg(void)
{
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}

bool	is_empty(const t_stack stack)
{
	return (stack.len == 0);
}

int	*intrevadd(int *value, const int len, const int nw)
{
	int	i;
	int	*dup;

	dup = ft_calloc(len + 1, sizeof(int));
	if (!dup)
		return (NULL);
	i = 0;
	dup[i++] = nw;
	if (value)
	{
		while (i <= len)
		{
			dup[i] = value[i - 1];
			++i;
		}
		free(value);
	}
	return (dup);
}

int	*intadd(int *value, const int len, const int nw)
{
	int	i;
	int	*dup;

	dup = ft_calloc(len + 1, sizeof(int));
	if (!dup)
		return (NULL);
	i = len;
	dup[i--] = nw;
	if (value)
	{
		while (i >= 0)
		{
			dup[i] = value[i];
			--i;
		}
		free(value);
	}
	return (dup);
}

int	*intremove(int *value, const int len)
{
	int	i;
	int	*dup;

	if (!value)
		return (NULL);
	dup = ft_calloc(len - 1, sizeof(int));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		dup[i] = value[i];
		++i;
	}
	free(value);
	return (dup);
}
