/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extreme.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <ycostode@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:37:37 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/23 11:36:01 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_stack(const t_stack stack)
{
	int	i;
	int	max;

	max = INT_MIN;
	i = 0;
	while (i < stack.len)
	{
		if (stack.value[i] > max)
			max = stack.value[i];
		++i;
	}
	return (max);
}

int	min_stack(const t_stack stack)
{
	int	i;
	int	min;

	min = INT_MAX;
	i = 0;
	while (i < stack.len)
	{
		if (stack.value[i] < min)
			min = stack.value[i];
		++i;
	}
	return (min);
}

int	max(const int a, const int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(const int a, const int b)
{
	if (a < b)
		return (a);
	return (b);
}
