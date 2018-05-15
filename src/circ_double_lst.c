/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_double_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:18:08 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/14 19:25:11 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <stdio.h>

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

void		print_dc_list(t_circ_node *start)
{
	t_circ_node *tmp;

	if (!start)
		return ;
	tmp = start;
	while (tmp->next != start)
	{
		if (tmp->to_do == 1 || tmp->to_do == 3)
			ft_putstr("\033[4m");
		if (tmp->to_do == 3 || tmp->to_do == 2)
			ft_putstr("\033[7m");
		ft_putstr(tmp->data);
		ft_putchar('\n');
		ft_putstr("\033[0m");
		tmp = tmp->next;
	}
	if (tmp->to_do == 1 || tmp->to_do == 3)
		ft_putstr("\033[4m");
	if (tmp->to_do == 3 || tmp->to_do == 2)
		ft_putstr("\033[7m");
	ft_putstr(tmp->data);
	ft_putchar('\n');
	ft_putstr("\033[0m");
}

void		print_final_lst(t_circ_node *start)
{
	t_circ_node *tmp;

	if (!start)
		return ;
	tmp = start;
	while (tmp->next != start)
	{
		if (tmp->to_do == 3 || tmp->to_do == 2)
		{
			ft_putstr(tmp->data);
			ft_putchar('\n');
			ft_putstr("\033[0m");
		}
		tmp = tmp->next;
	}
	if (tmp->to_do == 3 || tmp->to_do == 2)
	{
		ft_putstr(tmp->data);
		ft_putchar('\n');
		ft_putstr("\033[0m");
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
