/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:21:39 by elee              #+#    #+#             */
/*   Updated: 2016/11/18 19:24:02 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stack_push(t_stack *stack, int item)
{
	if (stack_isfull(stack))
		return ;
	stack->array[++stack->top] = item;
}

int		stack_pop(t_stack *stack)
{
	if (stack_isempty(stack))
		return (-2147483648);
	return (stack->array[stack->top--]);
}

int		stack_peek(t_stack *stack)
{
	if (stack_isempty(stack))
		return (-2147483648);
	return (stack->array[stack->top]);
}
