/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:48:38 by ishenriq          #+#    #+#             */
/*   Updated: 2024/04/04 20:15:01 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

static int stack_sorted(t_stack *stack, int flag, int size) {
  t_list *node;

  node = stack->head;
  while (node && --size) {
    if (flag == STACK_A && node->next &&
        *(int *)node->content > *(int *)node->next->content)
      return (0);
    else if (node->next && *(int *)node->content < *(int *)node->next->content)
      return (0);
    node = node->next;
  }
  return (1);
}

static void sort_stack_a(t_stack *stack, t_stack *stack_b, int size) {
  int mid;
  int pushs;
  int rotates;

  pushs = (size / 2);
  rotates = 0;
  mid = middler(stack, pushs + (size % 2), size);
  while (pushs) {
    if (*(int *)stack->head->content < mid && pushs--)
      operations(PB, stack, stack_b);
    else {
      operations(RA, stack, stack_b);
      rotates++;
    }
  }
  if (stack->size > rotates)
    loop(RA, rotates, stack, NULL);
}

static void sort_stack_b(t_stack *stack, t_stack *stack_b, int size) {
  int mid;
  int pushs;
  int rotates;

  pushs = (size / 2) + (size % 2);
  rotates = 0;
  mid = middler(stack_b, pushs, size);
  while (pushs) {
    if (*(int *)stack_b->head->content >= mid && pushs--)
      operations(PA, stack, stack_b);
    else {
      operations(RB, stack, stack_b);
      rotates++;
    }
  }
  if (stack_b->size > rotates)
    loop(RB, rotates, NULL, stack_b);
}

static int check_handler(t_stack *stack, t_stack *stack_b, int flag, int size) {
  if (size > 3)
    return (0);
  else if (size == 3 && flag == STACK_A) {
    three_handler_a(stack, stack_b);
  } else if (size == 3) {
    three_handler_b(stack, stack_b);
  } else if (size == 2 && flag == STACK_B) {
    if (*(int *)stack_b->head->content < *(int *)stack_b->head->next->content)
      operations(SB, stack, stack_b);
    operations(PA, stack, stack_b);
    operations(PA, stack, stack_b);
  } else if (size == 2) {
    if (*(int *)stack->head->content > *(int *)stack->head->next->content)
      operations(SA, stack, stack_b);
  } else if (size == 1 && flag == STACK_B)
    operations(PA, stack, stack_b);
  return (1);
}

void sort_handler(t_stack *stack, t_stack *stack_b, int flag, int size) {
  if (check_handler(stack, stack_b, flag, size))
    return;
  if (flag == STACK_A) {
    if (!stack_sorted(stack, flag, size))
      sort_stack_a(stack, stack_b, size);
    else
      return;
  } else {
    if (!stack_sorted(stack_b, flag, size))
      sort_stack_b(stack, stack_b, size);
    else {
      loop(PA, size, stack, stack_b);
      return;
    }
  }
  sort_handler(stack, stack_b, STACK_A, (size / 2) + (size % 2));
  sort_handler(stack, stack_b, STACK_B, (size / 2));
}
