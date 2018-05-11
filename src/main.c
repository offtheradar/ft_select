/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:43:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/11 10:42:19 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int i;
	int j;
	long long buffer;
	//char	*clr;
	char	**args;
	char	*term_name;
	struct	termios	term;

	i = 1;
	j = 0;
	buffer = 0;
	if (!(term_name = getenv("TERM")))
		return (-1);
	if (!tgetent(NULL, term_name))
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	ft_putstr(tgetstr("vi", 0));
	args = ft_memalloc(sizeof(char *) * ac);
	args[ac - 1] = NULL;
	while (av[i])
	{
		args[j] = ft_strdup(av[i]);
		j++;
		i++;
	}
	j = 0;
	//print_args(args, 0, ac - 1);
	while (1)
	{
		read(0, &buffer, 11);
		if (buffer == UP_KEY)
		{
			j += 1;
			fputs(tgetstr("cl", NULL), stdout);
			print_args(args, j, ac - 1);
		}
		if (buffer == DOWN_KEY)
		{
			j -= 1;
			fputs(tgetstr("cl", NULL), stdout);
			print_args(args, j, ac - 1);
		}
	}
}

void		print_args(char **args, int j, int size)
{
	int i;

	i = 0;
	if (j < 0)
		j *= -1;
	while (args[i])
	{
		if (i == (j % size))
			printf("%s%s%s\n", tgetstr("us", NULL), args[i], tgetstr("ue", NULL));
		else
			printf("%s\n", args[i]);
		i++;
	}
}
