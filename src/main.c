/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:43:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/26 06:11:05 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		handle_buffer(long long buffer, t_circ_node *start, t_circ_node **curr)
{
	if (buffer == UP_KEY)
		handle_up(start, curr);
	else if (buffer == DOWN_KEY)
		handle_down(start, curr);
	else if (buffer == SPACE)
		handle_space(start, curr);
	else if (buffer == BACK_SPACE || buffer == DELETE_KEY)
	{
		handle_rm(&start, curr);
		if (!(start))
			return (1);
	}
	else if (buffer == ESC)
	{
		while (start)
			handle_rm(&start, curr);
		exit(1);
	}
	else if (buffer == ENTER)
	{
		handle_enter((start));
		return (1);
	}
	return (0);
}

void	handle_keys(t_circ_node *start)
{
	long long	buffer;
	t_circ_node *curr;

	buffer = 0;
	curr = start;
	curr->to_do = 1;
	clear_and_print(start);
	while (1)
	{
		if (!(start))
			break ;
		buffer = 0;
		read(0, &buffer, 8);
		if (handle_buffer(buffer, start, &curr))
			break ;
	}
}

int		main(int ac, char **av)
{
	int				i;
	struct termios	term;

	i = 0;
	start = NULL;
	init_terminal(&term);
	prev_term = term;
	bg_term = term;
	init_signal();
	while (++i < ac)
		insert_dc_lst(&start, av[i]);
	handle_keys(start);
	return (0);
}
