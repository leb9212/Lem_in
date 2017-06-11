/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:19:44 by elee              #+#    #+#             */
/*   Updated: 2016/11/18 19:25:44 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(sizeof(int) * stack->capacity);
	return (stack);
}

int		stack_isfull(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

int		stack_isempty(t_stack *stack)
{
	return (stack->top == -1);
}
