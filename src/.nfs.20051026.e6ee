/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:59:49 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/15 14:12:26 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	clear_and_print(t_circ_node *start)
{
	ft_putstr_fd(tgetstr("cl", NULL), 1);
	print_dc_list(start);
}

void	handle_up(t_circ_node *start, t_circ_node **curr)
{
	(*curr)->to_do = ((*curr)->to_do == CURR_SELECT || (*curr)->to_do == SELECT)
						? SELECT : DEFAULT;
	(*curr) = (*curr)->prev;
	(*curr)->to_do = ((*curr)->to_do == SELECT) ? CURR_SELECT : CURR;
	clear_and_print(start);
}

void	handle_down(t_circ_node *start, t_circ_node **curr)
{
	(*curr)->to_do = ((*curr)->to_do == CURR_SELECT ||
						(*curr)->to_do == SELECT) ? SELECT : DEFAULT;
	(*curr) = (*curr)->next;
	(*curr)->to_do = ((*curr)->to_do == SELECT) ? CURR_SELECT : CURR;
	clear_and_print(start);
}

void	handle_space(t_circ_node *start, t_circ_node **curr)
{
	(*curr)->to_do = ((*curr)->to_do == CURR_SELECT) ? CURR : CURR_SELECT;
	clear_and_print(start);
}

void	handle_enter(t_circ_node *start)
{
	ft_putstr_fd(tgetstr("cl", NULL), 1);
	print_final_lst(start);
}

void	handle_rm(t_circ_node **start, t_circ_node **curr)
{
	if (*curr == *start && (*start)->next == *start &&
		(*start)->prev == *start)
	{
		*start = NULL;
		clear_and_print(*start);
	}
	else if (*curr == *start)
		*start = (*start)->next;
	delete_dc_lst(curr);
	if ((*start))
		clear_and_print(*start);
}
