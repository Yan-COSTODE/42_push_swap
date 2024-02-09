/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <ycostode@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:35:11 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/23 12:58:10 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_one(t_op *op, const int idx, const int alen, const int blen)
{
	int	count;
	int	index;

	index = op->count;
	count = min(blen - 1 - idx, alen - 1 - index);
	op->op = ft_strjoinl(ft_itoa(count), ",rr,");
	if (blen - 1 - idx - count > 0)
		op->op = ft_strjoinb(op->op, ft_strjoinl(ft_itoa(blen - 1 - idx
						- count), ",rb,"));
	else if (alen - 1 - index - count > 0)
		op->op = ft_strjoinb(op->op, ft_strjoinl(ft_itoa(alen - 1 - index
						- count), ",ra,"));
	count += blen - 1 - idx + alen - 1 - index - 2 * count;
	op->count = count + 1;
}

void	case_two(t_op *op, const int idx, const int blen)
{
	int	count;
	int	index;

	index = op->count;
	count = blen - 1 - idx + index + 1;
	op->op = ft_strjoinl(ft_itoa(blen - 1 - idx), ",rb,");
	op->op = ft_strjoinb(op->op, ft_strjoinl(ft_itoa(index + 1), ",rra,"));
	op->count = count + 1;
}

void	case_three(t_op *op, const int idx, const int alen)
{
	int	count;
	int	index;

	index = op->count;
	count = idx + 1 + alen - 1 - index;
	op->op = ft_strjoinl(ft_itoa(alen - 1 - index), ",ra,");
	op->op = ft_strjoinb(op->op, ft_strjoinl(ft_itoa(idx + 1), ",rrb,"));
	op->count = count + 1;
}

void	case_four(t_op *op, const int idx)
{
	int	count;
	int	index;

	index = op->count;
	count = min(idx + 1, index + 1);
	op->op = ft_strjoinl(ft_itoa(count), ",rrr,");
	if (idx + 1 - count > 0)
		op->op = ft_strjoinb(op->op, ft_strjoinl(ft_itoa(idx + 1 - count),
					",rrb,"));
	else if (index + 1 - count > 0)
		op->op = ft_strjoinb(op->op, ft_strjoinl(ft_itoa(index + 1 - count),
					",rra,"));
	count += idx + 1 + index + 1 - 2 * count;
	op->count = count + 1;
}

t_op	count_op(const int index, const t_stack a, const t_stack b)
{
	t_op	op;
	int		value;
	int		idx;

	value = a.value[index];
	op.count = index;
	if (value < min_stack(b))
		idx = find_max(b);
	else
		idx = find_next_low(b, value);
	if (idx > b.len / 2)
	{
		if (index > a.len / 2)
			case_one(&op, idx, a.len, b.len);
		else
			case_two(&op, idx, b.len);
	}
	else
	{
		if (index > a.len / 2)
			case_three(&op, idx, a.len);
		else
			case_four(&op, idx);
	}
	return (op);
}
