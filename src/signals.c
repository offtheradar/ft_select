/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:58:48 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/26 02:15:13 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		init_signal(void)
{
	signal(SIGCONT, continue_signal);
	signal(SIGKILL, handle_signal);
	signal(SIGQUIT, handle_signal);
	signal(SIGABRT, handle_signal);
	signal(SIGINT, handle_signal);
	signal(SIGSTOP, handle_signal);
	signal(SIGTSTP, suspend_signal);
}

void		suspend_signal(int sig)
{
	sig = 0;
	get_terminal(prev_term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		continue_signal(int sig)
{
	sig = 0;
	if (tcsetattr(0, TCSADRAIN, &(bg_term)) == -1)
		return ;
	ft_putstr_fd(tgetstr("vi", 0), 1);
	ft_putstr_fd(tgetstr("cl", 0), 1);
	init_signal();
	clear_and_print(start);
}

void		handle_signal(int sig)
{
	sig = 0;
	get_terminal(prev_term);
	exit(0);
}
