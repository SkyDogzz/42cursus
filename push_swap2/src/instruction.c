/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:00:03 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/13 08:35:48 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void add_instruction(t_inst *inst, const char *ins)
{
    t_inode *new_node;
    t_inode *temp;

    new_node = malloc(sizeof(t_inode));
    if (!new_node)
        exit_with_error("Memory allocation failed\n");
    new_node->value = ft_strdup(ins);
    new_node->next = NULL;
    if (!inst->top)
    {
        inst->top = new_node;
    }
    else
    {
        temp = inst->top;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
    inst->size++;
}

#include <string.h>
void replace_instruction(t_inode *node, const char *new_value) {
    free(node->value);
    node->value = ft_strdup(new_value);
}void remove_next_node(t_inode *current) {
    if (current->next) {
        t_inode *temp = current->next;
        current->next = temp->next;
        free(temp->value);
        free(temp);
    }
}
void optimize_instructions(t_inst *inst)
{
    if (!inst || !inst->top)
        return;

    int optimized = 1;

    while (optimized)
    {
        optimized = 0;
        t_inode *prev = NULL;
        t_inode *current = inst->top;

        while (current && current->next)
        {
            // Combine ra and rb into rr
            if (((strcmp(current->value, "ra") == 0 && strcmp(current->next->value, "rb") == 0) ||
                 (strcmp(current->value, "rb") == 0 && strcmp(current->next->value, "ra") == 0)) &&
                !(strcmp(current->value, "rr") == 0)) { // Ensure not already "rr"
                replace_instruction(current, "rr");
                remove_next_node(current);
                inst->size--;
                optimized = 1;
                continue;
            }
            else if (((strcmp(current->value, "rra") == 0 && strcmp(current->next->value, "rrb") == 0) ||
                      (strcmp(current->value, "rrb") == 0 && strcmp(current->next->value, "rra") == 0)) &&
                     !(strcmp(current->value, "rrr") == 0)) { // Ensure not already "rrr"
                replace_instruction(current, "rrr");
                remove_next_node(current);
                inst->size--;
                optimized = 1;
                continue;
            }
            // Cancel out ra followed by rra
            else if ((strcmp(current->value, "ra") == 0 && strcmp(current->next->value, "rra") == 0) ||
                     (strcmp(current->value, "rra") == 0 && strcmp(current->next->value, "ra") == 0))
            {
                // Remove both instructions
                if (prev)
                    prev->next = current->next->next;
                else
                    inst->top = current->next->next;

                free(current->value);
                free(current->next->value);
                free(current->next);
                free(current);
                inst->size -= 2;
                optimized = 1;
                current = prev ? prev->next : inst->top;
                continue;
            }
            // Similarly, cancel out rb and rrb
            else if ((strcmp(current->value, "rb") == 0 && strcmp(current->next->value, "rrb") == 0) ||
                     (strcmp(current->value, "rrb") == 0 && strcmp(current->next->value, "rb") == 0))
            {
                // Remove both instructions
                if (prev)
                    prev->next = current->next->next;
                else
                    inst->top = current->next->next;

                free(current->value);
                free(current->next->value);
                free(current->next);
                free(current);
                inst->size -= 2;
                optimized = 1;
                current = prev ? prev->next : inst->top;
                continue;
            }
            // Add more optimization rules as needed

            prev = current;
            current = current->next;
        }
    }
}

void	print_instructions(t_inst *inst)
{
	t_inode	*inode;

	if (!inst->top)
		return ;
	inode = inst->top;
	while (inode)
	{
		ft_printf("%s\n", inode->value);
		inode = inode->next;
	}
}
