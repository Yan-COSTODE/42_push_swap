/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:28:56 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/26 18:04:48 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize(t_stack *a)
{
	int	i;
	int	j;
	int	count;
	int	*tmp;

	tmp = ft_calloc(a->len, sizeof(int));
	if (!tmp)
		return ;
	i = 0;
	while (i < a->len)
	{
		j = 0;
		count = 0;
		while (j < a->len)
		{
			if (a->value[i] >= a->value[j])
				++count;
			++j;
		}
		tmp[i] = count;
		++i;
	}
	free(a->value);
	a->value = tmp;
}

void	sort(t_stack *a)
{
	t_stack	b;

	b.len = 0;
	b.value = NULL;
	if (!is_sorted(*a))
	{
		normalize(a);
		if (a->len >= 5)
		{
			first_sort(a, &b);
			second_sort(a, &b);
			put_min_up(a);
		}
		else
			small_sort(a, &b);
	}
	free(b.value);
}

void	add(t_stack *stack, const int value)
{
	if (stack->len == 0)
	{
		stack->value = ft_calloc(sizeof(int), 1);
		if (!stack->value)
			return ;
		stack->value[0] = value;
	}
	else
		stack->value = intrevadd(stack->value, stack->len, value);
	stack->len++;
}

static int	convert_args(char ***args, t_stack *a)
{
	int		count;
	bool	error;
	int		i;
	int		j;
	int		n;

	i = 0;
	error = false;
	while (args[i])
	{
		count = 0;
		j = 0;
		while (args[i][j])
		{
			if (convert(args[i][j++], &n) && !is_in_stack(*a, n))
				add(a, n);
			else
				error = true;
			count++;
		}
		if (count == 0)
			error = true;
		ft_freesplit(args[i++]);
	}
	return (!error);
}

int	main(const int argc, char **argv)
{
	t_stack	a;
	bool	parsed;
	char	***args;

	if (argc < 2)
		return (EXIT_FAILURE);
	a.len = 0;
	a.value = NULL;
	args = parse_args(argc, argv);
	parsed = convert_args(args, &a);
	free(args);
	if (parsed)
		sort(&a);
	if (a.value)
		free(a.value);
	if (!parsed)
		return (error_msg());
	return (EXIT_SUCCESS);
}
