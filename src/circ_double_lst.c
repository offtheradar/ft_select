/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_double_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:18:08 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/16 17:10:25 by ysibous          ###   ########.fr       */
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

t_print_format		get_print_format(t_circ_node *start)
{
	t_circ_node		*tmp;
	t_print_format	p_f;
	int				l_str;

	tmp = start;
	l_str = 0;
	p_f.longest_str = 0;
	p_f.col = 0;
	p_f.size = 0;;
	while (tmp)
	{
		p_f.size += 1;
		if ((l_str = ft_strlen(tmp->data)) > p_f.longest_str)
			p_f.longest_str = l_str;
		tmp = tmp->next;
		if (tmp == start)
			break ;
	}
	p_f.col = 1 + p_f.size / tgetnum("li");
	return (p_f);
}

void		print_dc_list(t_circ_node *start)
{
	t_circ_node 	*tmp;
	int				i;
	int				num;
	t_print_format	p_f;

	if (!start)
		return ;
	tmp = start;
	i = 0;
	p_f = get_print_format(start);
//	printf("the col size is %d\n", p_f.col);
//	printf("the  size is %d\n", p_f.size);
// 	printf("the  longest str size is %d\n", p_f.longest_str);
	num = p_f.col;
	while (i < p_f.size)
	{
		num = p_f.col;
		while (tmp && num)
		{
			if (tmp->to_do == 1 || tmp->to_do == 3)
				ft_putstr("\033[4m");
			if (tmp->to_do == 3 || tmp->to_do == 2)
				ft_putstr("\033[7m");
			//printf("%-*s", p_f.longest_str + 2, tmp->data);
			ft_putstr(tmp->data);
			ft_putstr("\033[0m");
			tmp = tmp->next;
			num--;
			i++;
			if (tmp == start)
				break ;
		}
		if (tmp == start)
				break ;
		ft_putchar('\n');
	}	
}

void		print_final_lst(t_circ_node *start)
{
	t_circ_node		*tmp;

	if (!start)
		return ;
	tmp = start;
	while (tmp)
	{
		if (tmp->to_do == 3 || tmp->to_do == 2)
		{
			ft_putstr(tmp->data);
			ft_putchar(' ');
			ft_putstr("\033[0m");
		}
		if (tmp == start)
			break ;
	}
	ft_putchar('\n');
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
