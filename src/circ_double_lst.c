/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_double_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:18:08 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/11 15:15:07 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <stdio.h>

void		insert_dc_lst(t_circ_node **start, char *str)
{
	t_circ_node *new_node;

	new_node = ft_memalloc(sizeof(new_node));
	new_node->data = str;
	if ((*start) == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*start = new_node;
	}
	else
	{
		new_node->next = *start;
		new_node->prev = (*start)->prev;
		(*start)->prev->next = new_node;
		(*start)->prev = new_node;
	}
}

void		delete_dc_lst(t_circ_node **start, char *str)
{
	t_circ_node	*curr;
	t_circ_node	*tmp;
	t_circ_node	*prev_1;

	if (!(*start))
		return ;
	curr = *start;
	prev_1 = NULL;
	while (ft_strcmp(curr->data, str))
	{
		if (curr->next == *start)
			return ;
		prev_1 = curr;
		curr = curr->next;
	}
	if (curr->next == *start && !prev_1)
	{
		*start = NULL;
		free(curr);
		return ;
	}
	if (curr == *start)
	{
		prev_1 = (*start)->prev;
		*start = (*start)->next;
		prev_1->next = *start;
		(*start)->prev = prev_1;
		free(curr);
	}
	else if (curr->next == *start)
	{
		prev_1->next = *start;
		(*start)->prev = prev_1;
		free(curr);
	}
	else
	{
		tmp = curr->next;
		prev_1->next = tmp;
		tmp->prev = prev_1;
		free(curr);
	}
}

void		print_dc_list(t_circ_node *start, t_circ_node *under)
{
	t_circ_node *tmp;
	t_circ_node *last;

	if (!start)
		return ;
	tmp = start;
	last = start->prev;
	while (tmp)
	{
		if (tmp == under)
		{
			printf("%s%s%s\n", tgetstr("us", NULL), tmp->data, tgetstr("ue", NULL));
		}
		else
		{
			ft_putstr(tmp->data);
			ft_putchar('\n');
		}
		if (tmp == last)
			break ;
		tmp = tmp->next;
	}
}
