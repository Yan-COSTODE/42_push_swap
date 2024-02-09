/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <ycostode@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:35:11 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/22 18:42:34 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(const t_stack stack)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < stack.len)
	{
		if (stack.value[i] > stack.value[index])
			index = i;
		++i;
	}
	return (index);
}

int	find_min(const t_stack stack)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < stack.len)
	{
		if (stack.value[i] < stack.value[index])
			index = i;
		++i;
	}
	return (index);
}

int	find_next_high(const t_stack stack, const int n)
{
	bool	init;
	int		index;
	int		i;

	index = 0;
	i = 0;
	init = false;
	while (i < stack.len)
	{
		if (!init && stack.value[i] > n)
		{
			index = i;
			init = true;
		}
		else if (init && stack.value[i] > n
			&& stack.value[i] < stack.value[index])
			index = i;
		++i;
	}
	return (index);
}

int	find_next_low(const t_stack stack, const int n)
{
	bool	init;
	int		index;
	int		i;

	index = 0;
	i = 0;
	init = false;
	while (i < stack.len)
	{
		if (!init && stack.value[i] < n)
		{
			index = i;
			init = true;
		}
		else if (init && stack.value[i] < n
			&& stack.value[i] > stack.value[index])
			index = i;
		++i;
	}
	return (index);
}
