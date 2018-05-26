/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:59:24 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/26 06:07:28 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <stdio.h>

t_print_format	get_print_format(t_circ_node *start)
{
	t_circ_node		*tmp;
	t_print_format	p_f;
	int				l_str;

	tmp = start;
	l_str = 0;
	p_f.longest_str = 0;
	p_f.col = 0;
	p_f.size = 0;
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

void			print_dc_list_helper(t_circ_node *tmp, t_print_format p_f)
{
	if (tmp->to_do == 1 || tmp->to_do == 3)
		ft_putstr("\033[4m");
	if (tmp->to_do == 3 || tmp->to_do == 2)
		ft_putstr("\033[7m");
	ft_putstrn(tmp->data, p_f.longest_str + 2);
	ft_putstr("\033[0m");
}

void			print_dc_list(t_circ_node *start)
{
	t_circ_node		*tmp;
	int				i;
	int				num;
	t_print_format	p_f;

	tmp = start;
	i = -1;
	p_f = get_print_format(start);
	num = p_f.col;
	while (++i < p_f.size)
	{
		num = p_f.col;
		while (tmp && num)
		{
			print_dc_list_helper(tmp, p_f);
			tmp = tmp->next;
			num--;
			if (tmp == start)
				break ;
		}
		if (tmp == start)
			break ;
		ft_putchar('\n');
	}
}

void			print_final_lst(t_circ_node *start)
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
		tmp = tmp->next;
		if (tmp == start)
		{
			ft_putchar('\n');
			break ;
		}
	}
}
