/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:28:56 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/23 12:58:01 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_stack(char *nop, char *op, t_stack *a, t_stack *b)
{
	int	n;

	n = atoi(nop);
	while (n)
	{
		if (ft_strncmp(op, "ra", 3) == 0)
			rotate(a, "ra\n");
		else if (ft_strncmp(op, "rb", 3) == 0)
			rotate(b, "rb\n");
		else if (ft_strncmp(op, "rr", 3) == 0)
		{
			rotate(a, "");
			rotate(b, "rr\n");
		}
		else if (ft_strncmp(op, "rra", 3) == 0)
			reverse_rotate(a, "rra\n");
		else if (ft_strncmp(op, "rrb", 3) == 0)
			reverse_rotate(b, "rrb\n");
		else if (ft_strncmp(op, "rrr", 3) == 0)
		{
			reverse_rotate(a, "");
			reverse_rotate(b, "rrr\n");
		}
		--n;
	}
}

char	**search_operator(const t_stack a, const t_stack b)
{
	t_op	op;
	int		sort;
	char	**ops;
	int		i;

	sort = INT_MAX;
	i = a.len - 1;
	ops = NULL;
	while (i >= 0)
	{
		op = count_op(i, a, b);
		if (sort > op.count)
		{
			sort = op.count;
			ft_freesplit(ops);
			ops = ft_split(op.op, ',');
		}
		free(op.op);
		--i;
	}
	return (ops);
}

void	first_sort(t_stack *a, t_stack *b)
{
	int		i;
	char	**ops;

	push(a, b, "pb\n");
	push(a, b, "pb\n");
	while (a->len > 3)
	{
		i = 0;
		ops = search_operator(*a, *b);
		while (ops[i] && ops[i + 1])
		{
			do_stack(ops[i], ops[i + 1], a, b);
			i += 2;
		}
		push(a, b, "pb\n");
		ft_freesplit(ops);
	}
	three_sort(a);
}

void	put_min_up(t_stack *a)
{
	int	min;

	min = find_min(*a);
	while (min != a->len - 1)
	{
		if (min > a->len / 2)
			rotate(a, "ra\n");
		else
			reverse_rotate(a, "rra\n");
		min = find_min(*a);
	}
}

void	second_sort(t_stack *a, t_stack *b)
{
	int		index;
	bool	reverse;

	while (!is_empty(*b))
	{
		reverse = true;
		index = find_next_high(*a, top(*b)) + 1;
		if (top(*b) > max_stack(*a))
			index = find_next_low(*a, top(*b));
		if (index > a->len - 1)
			index = 0;
		if (index > a->len / 2)
		{
			index = a->len - 1 - index + 1;
			reverse = false;
		}
		while (index--)
		{
			if (reverse)
				reverse_rotate(a, "rra\n");
			else
				rotate(a, "ra\n");
		}
		push(b, a, "pa\n");
	}
}
