/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:27:50 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/15 19:01:06 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_lower_half(int value, int min, int max) {
    return (value <= (min + (max - min) / 2));
}

int find_max(t_stack *stack) {
    if (!stack->top)
        return 0;
    int max = stack->top->value;
    t_node *current = stack->top->next;
    while (current) {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}
int determine_chunk_size(int total_elements, int number_of_chunks) {
    if (number_of_chunks == 0)
        return total_elements;
    return total_elements / number_of_chunks;
}
void sort_stack_with_chunks(t_inst *inst, t_stack *stack, t_stack *temp, int number_of_chunks) {
    int chunk_size = determine_chunk_size(stack->size, number_of_chunks);
    int current_chunk = 1;
    int min_value_in_chunk = (current_chunk - 1) * chunk_size + 1;
    int max_value_in_chunk = current_chunk * chunk_size;

    while (current_chunk <= number_of_chunks) {
        size_t i = 0;
        size_t stack_size = stack->size;

       
while (i < stack_size) {
    int current_value = get_value(stack, 0);
    if (current_value >= min_value_in_chunk && current_value <= max_value_in_chunk) {
        execpb(inst, temp, pop(stack));
        if (is_lower_half(current_value, min_value_in_chunk, max_value_in_chunk)) {
            execrb(inst, temp);
        }
    } else {
        // On calcule l'index du current_value pour déterminer la rotation la plus courte
        int idx = index_of(stack, current_value);
        if (idx < (int)stack->size / 2)
            execra(inst, stack);   // L'élément est plus proche du haut, on rotate normal
        else
            execrra(inst, stack);  // L'élément est plus proche du bas, on reverse rotate
    }
    i++;
}

        current_chunk++;
        min_value_in_chunk = (current_chunk - 1) * chunk_size + 1;
        max_value_in_chunk = current_chunk * chunk_size;
    }

    // Pousser les éléments de B vers A dans l'ordre
    while (temp->top) {
        int max = find_max(temp);
        get_on_top(inst, temp, max);
        execpa(inst, stack, pop(temp));
    }
}
