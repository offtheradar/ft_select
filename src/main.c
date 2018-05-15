/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:43:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/14 19:22:30 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <stdio.h>

int		init_terminal(void)
{
	char			*term_name;
	struct termios	term;

	if (!(term_name = getenv("TERM")))
		return (-1);
	if (!tgetent(NULL, term_name))
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	ft_putstr(tgetstr("vi", 0));
	return (1);
}

void		handle_keys(t_circ_node *start)
{
	long long	buffer;
	t_circ_node *curr;

	buffer = 0;
	curr = start;
	curr->to_do = 1;
	clear_and_print(start);
	while (1)
	{
		buffer = 0;
		read(0, &buffer, 8);
		if (buffer == UP_KEY)
			handle_up(start, &curr);
		else if (buffer == DOWN_KEY)
			handle_down(start, &curr);
		else if (buffer == SPACE)
			handle_space(start, &curr);
		else if (buffer == 8 || buffer == 127)
		{
			if (curr == start && start->next == start && start->prev == start)
			{
				start = NULL;
				clear_and_print(start);
			}
			else if (curr == start)
				start = start->next;
			delete_dc_lst(&curr);
			if (!start)
				break ;
			if (start)
				clear_and_print(start);
		}
		else if (buffer == ENTER)
		{
			handle_enter(start);
			break ;
		}
	}
}

int		main(int ac, char **av)
{
	int			i;
	t_circ_node	*start;

	i = 0;
	start = NULL;
	init_terminal();
	while (++i < ac)
		insert_dc_lst(&start, av[i]);
	handle_keys(start);
	return (0);
}
