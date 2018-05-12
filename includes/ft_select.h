/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:45:14 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/11 17:44:18 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include <termios.h>
# include <term.h>
# define UP_KEY 4283163
# define DOWN_KEY 4348699
# define SPACE 32

typedef struct			s_circ_node
{
	char				*data;
	int					to_do;
	struct s_circ_node	*next;
	struct s_circ_node	*prev;
}						t_circ_node;

int						init_terminal(void);

void					print_args(char **args, int j, int size);

/*
****************************** Doubly Circular List ****************************
*/

void					insert_dc_lst(t_circ_node **start, char *str);

void					delete_dc_lst(t_circ_node **start, char *str);

void					print_dc_list(t_circ_node *start);
#endif
