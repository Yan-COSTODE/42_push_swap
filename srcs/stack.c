/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:36:41 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/22 18:08:16 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top(const t_stack stack)
{
	if (stack.len > 0)
		return (stack.value[stack.len - 1]);
	return (0);
}

void	swap(t_stack *stack, char *msg)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->value[stack->len - 1];
	stack->value[stack->len - 1] = stack->value[stack->len - 2];
	stack->value[stack->len - 2] = tmp;
	write(1, msg, ft_strlen(msg));
}

void	reverse_rotate(t_stack *stack, char *msg)
{
	int	tmp;
	int	i;

	if (stack->len < 2)
		return ;
	i = 0;
	tmp = stack->value[0];
	while (i < stack->len - 1)
	{
		stack->value[i] = stack->value[i + 1];
		++i;
	}
	stack->value[stack->len - 1] = tmp;
	write(1, msg, ft_strlen(msg));
}

void	rotate(t_stack *stack, char *msg)
{
	int	tmp;
	int	i;

	if (stack->len < 2)
		return ;
	i = stack->len - 1;
	tmp = stack->value[stack->len - 1];
	while (i > 0)
	{
		stack->value[i] = stack->value[i - 1];
		--i;
	}
	stack->value[0] = tmp;
	write(1, msg, ft_strlen(msg));
}

void	push(t_stack *from, t_stack *to, char *msg)
{
	if (from->len == 0)
		return ;
	to->value = intadd(to->value, to->len, top(*from));
	to->len++;
	from->value = intremove(from->value, from->len);
	from->len--;
	write(1, msg, ft_strlen(msg));
}
