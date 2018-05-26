/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:50:38 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/26 06:10:31 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int			init_terminal(struct termios *term)
{
	char			*term_name;

	if (!(term_name = getenv("TERM")))
		return (-1);
	if (!tgetent(NULL, term_name))
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	ft_putstr(tgetstr("vi", 0));
	return (1);
}

void		get_terminal(struct termios term)
{
	if (!getenv("TERM") || tgetent(NULL, getenv("TERM")) == -1)
		return ;
	ft_putstr_fd(tgetstr("ve", 0), 1);
	tcsetattr(0, TCSADRAIN, &(term));
}
