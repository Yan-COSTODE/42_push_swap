/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:53:57 by ycostode          #+#    #+#             */
/*   Updated: 2024/01/23 11:38:20 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		len;
	int		*value;
}			t_stack;
typedef struct s_op
{
	int		count;
	char	*op;
}			t_op;

char		*ft_strjoinl(char *s1, char *s2);
char		*ft_strjoinb(char *s1, char *s2);
void		put_min_up(t_stack *a);
int			error_msg(void);
void		reverse_rotate(t_stack *stack, char *msg);
void		rotate(t_stack *stack, char *msg);
int			find_min(const t_stack stack);
int			find_max(const t_stack stack);
bool		is_sorted(const t_stack stack);
void		small_sort(t_stack *a, t_stack *b);
void		first_sort(t_stack *a, t_stack *b);
void		second_sort(t_stack *a, t_stack *b);
bool		is_in_stack(const t_stack stack, int n);
bool		convert(const char *s, int *n);
bool		is_empty(t_stack stack);
int			top(t_stack stack);
void		push(t_stack *from, t_stack *to, char *msg);
int			*intrevadd(int *value, const int len, const int nw);
int			*intadd(int *value, const int len, const int nw);
int			*intremove(int *value, int len);
void		swap(t_stack *stack, char *msg);
char		***parse_args(const int argc, char **argv);
t_op		count_op(const int index, const t_stack a, const t_stack b);
void		three_sort(t_stack *a);
int			find_next_high(const t_stack stack, const int n);
int			find_next_low(const t_stack stack, const int n);
int			max_stack(const t_stack stack);
int			min_stack(const t_stack stack);
int			min(const int a, const int b);

#endif
