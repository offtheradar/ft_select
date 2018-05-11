/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:43:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/11 15:00:25 by ysibous          ###   ########.fr       */
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

int		main(int ac, char **av)
{
	int i;
	long long buffer;
	t_circ_node	*start;
	t_circ_node *tmp;

	i = 1;
	buffer = 0;
	init_terminal();
	start = NULL;
	while (i < ac)
	{
		insert_dc_lst(&start, av[i]);
		i++;
	}
	tmp = start;
	print_dc_list(start, tmp);
	while (1)
	{
		read(0, &buffer, 8);
		if (buffer == UP_KEY)
		{
			tmp = tmp->prev;
			fputs(tgetstr("cl", NULL), stdout);
			print_dc_list(start, tmp);
		}
		if (buffer == DOWN_KEY)
		{
			tmp = tmp->next;
			fputs(tgetstr("cl", NULL), stdout);
			print_dc_list(start, tmp);
		}
	}
}
