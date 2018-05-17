/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:45:14 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/16 20:51:46 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include <termios.h>
# include <term.h>
# include <signal.h>
# define DEFAULT 0
# define CURR 1
# define SELECT 2
# define CURR_SELECT 3
# define RM 4
# define UP_KEY 4283163
# define DOWN_KEY 4348699
# define ESC 27
# define BACK_SPACE 8
# define DELETE 127
# define ENTER 10
# define SPACE 32

typedef struct			s_circ_node
{
	char				*data;
	int					to_do;
	struct s_circ_node	*next;
	struct s_circ_node	*prev;
}						t_circ_node;

/*
** This struct holds information regarding the number of cols that could fit the window, the size of the longest string in the list, and the size of the window.
*/

typedef struct			s_print_format
{
	int					longest_str;
	int					col;
	int					size;
}						t_print_format;



void					print_args(char **args, int j, int size);

t_print_format			get_print_format(t_circ_node *start);

/*
****************************** Terminal ****************************************
*/

int						init_terminal(void);

void					get_terminal(struct termios term);

/*
****************************** Doubly Circular List ****************************
*/

void					insert_dc_lst(t_circ_node **start, char *str);

void					delete_dc_lst(t_circ_node **curr);

void					print_dc_list(t_circ_node *start);

void					print_final_lst(t_circ_node *start);

void					clear_and_print(t_circ_node *start);

/*
****************************** Handle Keys ******** ****************************
*/

void					handle_up(t_circ_node *start, t_circ_node **curr);

void					handle_down(t_circ_node *start, t_circ_node **curr);

void					handle_space(t_circ_node *start, t_circ_node **curr);

void					handle_enter(t_circ_node *start);

void					handle_rm(t_circ_node **start, t_circ_node **curr);
#endif
