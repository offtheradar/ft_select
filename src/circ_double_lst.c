/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_double_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:18:08 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/17 01:00:23 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		insert_dc_lst(t_circ_node **start, char *str)
{
	t_circ_node *new_node;
	t_circ_node *last;

	new_node = ft_memalloc(sizeof(t_circ_node));
	new_node->data = str;
	new_node->to_do = 0;
	if ((*start) == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*start = new_node;
	}
	else
	{
		last = (*start)->prev;
		new_node->next = *start;
		(*start)->prev = new_node;
		new_node->prev = last;
		last->next = new_node;
	}
}

void		delete_dc_lst(t_circ_node **curr)
{
	t_circ_node *tmp;
	t_circ_node *tmp_next;

	if (!(*curr))
		return ;
	tmp = *curr;
	tmp_next = tmp->next;
	(*curr)->prev->next = (*curr)->next;
	(*curr)->next->prev = (*curr)->prev;
	free(tmp);
	*curr = tmp_next;
	(*curr)->to_do = 1;
}
