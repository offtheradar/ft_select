/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:43:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/14 11:16:15 by ysibous          ###   ########.fr       */
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

int		handle_keys(t_circ_node *start)
{
	long long buffer;
	t_circ_node *curr;

	buffer = 0;
	curr = start;
	curr->to_do = 1;
	ft_putstr_fd(tgetstr("cl", NULL), 1);
	print_dc_list(start);
	while (1)
	{
		buffer = 0;
		read(0, &buffer, 8);
		if (buffer == UP_KEY)
		{
			curr->to_do = (curr->to_do == 3 || curr->to_do == 2) ? 2 : 0;
			curr = curr->prev;
			curr->to_do = (curr->to_do == 2) ? 3 : 1;
			ft_putstr_fd(tgetstr("cl", NULL), 1);
			print_dc_list(start);
		}
		else if (buffer == DOWN_KEY)
		{
			curr->to_do = (curr->to_do == 3 || curr->to_do == 2) ? 2 : 0;
			curr = curr->next;
			curr->to_do = (curr->to_do == 2) ? 3 : 1;
			ft_putstr_fd(tgetstr("cl", NULL), 1);
			print_dc_list(start);
		}
		else if (buffer == SPACE)
		{
			curr->to_do = (curr->to_do == 3) ? 1 : 3;
			ft_putstr_fd(tgetstr("cl", NULL), 1);
			print_dc_list(start);
		}
}

int		main(int ac, char **av)
{
	int i;
	t_circ_node	*start;

	i = 1;
	init_terminal();
	start = NULL;
	while (i < ac)
	{
		insert_dc_lst(&start, av[i]);
		i++;
	}
	handle_keys(start);
}
