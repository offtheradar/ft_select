/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:43:39 by ysibous           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/16 17:55:36 by ysibous          ###   ########.fr       */
=======
/*   Updated: 2018/05/16 20:50:52 by ysibous          ###   ########.fr       */
>>>>>>> press_enter
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		handle_keys(t_circ_node *start)
{
<<<<<<< HEAD
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

void	handle_keys(t_circ_node *start)
{
	long long buffer;
=======
	long long	buffer;
>>>>>>> press_enter
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
			handle_rm(&start, &curr);
			if (!start)
				break ;
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
