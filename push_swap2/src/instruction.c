/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:00:03 by skydogzz          #+#    #+#             */
/*   Updated: 2024/12/28 05:17:52 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "../include/push_swap.h"

void	add_instruction(t_inst *inst, const char *ins)
{
	t_inode	*new_node;
	t_inode	*temp;

	new_node = malloc(sizeof(t_inode));
	if (!new_node)
		exit_with_error("Memory allocation failed\n");
	new_node->value = ft_strdup(ins);
	new_node->next = NULL;
	if (!inst->top)
		inst->top = new_node;
	else
	{
		temp = inst->top;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	inst->size++;
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

// void replace_instruction(t_inode *node, const char *new_value) {
//     free(node->value);
//     node->value = ft_strdup(new_value);
// }
//
// void remove_next_node(t_inode *current) {
//     if (current->next) {
//         t_inode *temp = current->next;
//         current->next = temp->next;
//         free(temp->value);
//         free(temp);
//     }
// }
//
// void optimize_instructions(t_inst *inst)
// {
//     if (!inst || !inst->top)
//         return;
//
//     int optimized = 1;
//     while (optimized)
//     {
//         optimized = 0;
//         t_inode *prev = NULL;
//         t_inode *current = inst->top;
//
//         while (current && current->next)
//         {
//             char *cur = current->value;
//             char *nxt = current->next->value;
//
//             // Combine ra and rb into rr
//             if (((strcmp(cur, "ra") == 0 && strcmp(nxt, "rb") == 0) ||
//                  (strcmp(cur, "rb") == 0 && strcmp(nxt, "ra") == 0)) &&
//                 !(strcmp(cur, "rr") == 0))
//             {
//                 replace_instruction(current, "rr");
//                 remove_next_node(current);
//                 inst->size--;
//                 optimized = 1;
//                 continue;
//             }
//             // Combine rra and rrb into rrr
//             else if (((strcmp(cur, "rra") == 0 && strcmp(nxt, "rrb") == 0) ||
//                       (strcmp(cur, "rrb") == 0 && strcmp(nxt, "rra") == 0)) 
//                       &&
//                      !(strcmp(cur, "rrr") == 0))
//             {
//                 replace_instruction(current, "rrr");
//                 remove_next_node(current);
//                 inst->size--;
//                 optimized = 1;
//                 continue;
//             }
//             // Cancel out ra and rra
//             else if ((strcmp(cur, "ra") == 0 && strcmp(nxt, "rra") == 0) ||
//                      (strcmp(cur, "rra") == 0 && strcmp(nxt, "ra") == 0))
//             {
//                 if (prev)
//                     prev->next = current->next->next;
//                 else
//                     inst->top = current->next->next;
//                 free(current->value);
//                 free(current->next->value);
//                 free(current->next);
//                 free(current);
//                 inst->size -= 2;
//                 optimized = 1;
//                 current = prev ? prev->next : inst->top;
//                 continue;
//             }
//             // Cancel out rb and rrb
//             else if ((strcmp(cur, "rb") == 0 && strcmp(nxt, "rrb") == 0) ||
//                      (strcmp(cur, "rrb") == 0 && strcmp(nxt, "rb") == 0))
//             {
//                 if (prev)
//                     prev->next = current->next->next;
//                 else
//                     inst->top = current->next->next;
//                 free(current->value);
//                 free(current->next->value);
//                 free(current->next);
//                 free(current);
//                 inst->size -= 2;
//                 optimized = 1;
//                 current = prev ? prev->next : inst->top;
//                 continue;
//             }
//             // Remove double swaps (sa+sa, sb+sb, ss+ss)
//             else if ((strcmp(cur, "sa") == 0 && strcmp(nxt, "sa") == 0) ||
//                      (strcmp(cur, "sb") == 0 && strcmp(nxt, "sb") == 0) ||
//                      (strcmp(cur, "ss") == 0 && strcmp(nxt, "ss") == 0))
//             {
//                 if (prev)
//                     prev->next = current->next->next;
//                 else
//                     inst->top = current->next->next;
//                 free(current->value);
//                 free(current->next->value);
//                 free(current->next);
//                 free(current);
//                 inst->size -= 2;
//                 optimized = 1;
//                 current = prev ? prev->next : inst->top;
//                 continue;
//             }
//             // Cancel out pa followed by pb (and pb followed by pa)
//             else if ((strcmp(cur, "pa") == 0 && strcmp(nxt, "pb") == 0) ||
//                      (strcmp(cur, "pb") == 0 && strcmp(nxt, "pa") == 0))
//             {
//                 if (prev)
//                     prev->next = current->next->next;
//                 else
//                     inst->top = current->next->next;
//                 free(current->value);
//                 free(current->next->value);
//                 free(current->next);
//                 free(current);
//                 inst->size -= 2;
//                 optimized = 1;
//                 current = prev ? prev->next : inst->top;
//                 continue;
//             }
//             // Nouvelles optimisations :
//             // rr + rra => rb (on tourne les deux piles en avant, 
//             puis on inverse A)
//             else if (strcmp(cur, "rr") == 0 && strcmp(nxt, "rra") == 0)
//             {
//                 replace_instruction(current, "rb");
//                 remove_next_node(current);
//                 inst->size--;
//                 optimized = 1;
//                 continue;
//             }
//             // rr + rrb => ra
//             else if (strcmp(cur, "rr") == 0 && strcmp(nxt, "rrb") == 0)
//             {
//                 replace_instruction(current, "ra");
//                 remove_next_node(current);
//                 inst->size--;
//                 optimized = 1;
//                 continue;
//             }
//             // rrr + ra => rrb
//             else if (strcmp(cur, "rrr") == 0 && strcmp(nxt, "ra") == 0)
//             {
//                 replace_instruction(current, "rrb");
//                 remove_next_node(current);
//                 inst->size--;
//                 optimized = 1;
//                 continue;
//             }
//             // rrr + rb => rra
//             else if (strcmp(cur, "rrr") == 0 && strcmp(nxt, "rb") == 0)
//             {
//                 replace_instruction(current, "rra");
//                 remove_next_node(current);
//                 inst->size--;
//                 optimized = 1;
//                 continue;
//             }
//             // rr + rrr => annule tout
//             else if ((strcmp(cur, "rr") == 0 && strcmp(nxt, "rrr") == 0) ||
//                      (strcmp(cur, "rrr") == 0 && strcmp(nxt, "rr") == 0))
//             {
//                 if (prev)
//                     prev->next = current->next->next;
//                 else
//                     inst->top = current->next->next;
//                 free(current->value);
//                 free(current->next->value);
//                 free(current->next);
//                 free(current);
//                 inst->size -= 2;
//                 optimized = 1;
//                 current = prev ? prev->next : inst->top;
//                 continue;
//             }
//
//             // If no optimization pattern matched, move forward
//             prev = current;
//             current = current->next;
//         }
//     }
// }
