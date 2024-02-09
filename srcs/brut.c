/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <ycostode@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:35:11 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/22 18:36:50 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(const t_stack stack)
{
	int	current;
	int	i;

	current = top(stack);
	i = stack.len - 2;
	while (i >= 0)
	{
		if (stack.value[i] < current)
			return (false);
		current = stack.value[i];
		--i;
	}
	return (true);
}

void	two_sort(t_stack *a)
{
	swap(a, "sa\n");
}

void	three_sort(t_stack *a)
{
	int	max;

	max = find_max(*a);
	if (max == 2)
		rotate(a, "ra\n");
	else if (max == 1)
		reverse_rotate(a, "rra\n");
	if (find_min(*a) == 1)
		swap(a, "sa\n");
}

void	quad_sort(t_stack *a, t_stack *b)
{
	int	rota;

	rota = 2;
	push(a, b, "pb\n");
	three_sort(a);
	while (top(*b) > a->value[rota] && rota >= 0)
		--rota;
	if (rota == 1)
		rotate(a, "ra\n");
	if (rota == 0)
		reverse_rotate(a, "rra\n");
	push(b, a, "pa\n");
	if (rota == -1 || rota == 0)
		rotate(a, "ra\n");
	if (rota == 0)
		rotate(a, "ra\n");
	if (rota == 1)
		reverse_rotate(a, "rra\n");
}

void	small_sort(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		two_sort(a);
	else if (a->len == 3)
		three_sort(a);
	else if (a->len == 4)
		quad_sort(a, b);
}
