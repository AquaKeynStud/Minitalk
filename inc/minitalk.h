/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca42student@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:57:19 by arocca            #+#    #+#             */
/*   Updated: 2025/02/13 17:37:09 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* -- librairies -- */
# include <signal.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

/* -- Structures -- */
typedef struct s_handler
{
	unsigned int	bit_counter;
	unsigned char	character;
	unsigned int	fill_index;
	unsigned int	message_len;
	char			*message;
}				t_handler;

/* -- Client-sided functions -- */
void	send_data(int pid, int c, int type_size);

/* -- Server-sided functions -- */
void	init_values_storage(t_handler *handler, bool is_init);

/* -- Sigactions setters functions -- */
void	set_sigaction_server(void (*handler)(int, siginfo_t *, void *));
void	set_sigaction_client(void (*handler)(int signal));
void	set_sigaction_exit(void (*handler)(int signal));

/* -- Signal handlers -- */
void	char_handler(int signal, siginfo_t *info, void *context);
void	len_handler(int signal, siginfo_t *info, void *context);
void	cleanup_and_exit(int signal);
void	debounce(int signal);

#endif