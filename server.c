/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:36:42 by keyn              #+#    #+#             */
/*   Updated: 2025/02/12 18:22:27 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include "minitalk.h"
#include "ft_printf.h"

static t_handler	*g_status;

void	init_values_storage(t_handler *handler, bool is_init)
{
	if (is_init)
	{
		set_sigaction_handler(char_handler);
		return ;
	}
	handler->message_len = 0;
	handler->bit_counter = 0;
	handler->character = 0;
	handler->fill_index = 0;
	handler->message = NULL;
	set_sigaction_handler(len_handler);
	return ;
}

void	len_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	enable_queue(true);
	if (signal == SIGUSR2)
		g_status->message_len |= (1U << (31 - g_status->bit_counter));
	g_status->bit_counter++;
	if (g_status->bit_counter == 32)
	{
		g_status->bit_counter = 0;
		g_status->message = (char *)malloc(g_status->message_len + 1);
		if (!g_status->message)
			return ;
		g_status->message[g_status->message_len] = '\0';
		init_values_storage(g_status, true);
	}
	enable_queue(false);
}

void	char_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	enable_queue(true);
	if (signal == SIGUSR2)
		g_status->character |= (1 << (7 - g_status->bit_counter));
	g_status->bit_counter++;
	if (g_status->bit_counter == 8)
	{
		g_status->fill_index++;
		g_status->message[g_status->fill_index] = g_status->character;
		g_status->character = 0;
		g_status->bit_counter = 0;
		if (g_status->fill_index == g_status->message_len)
			write(1, g_status->message, g_status->message_len);
	}
	enable_queue(false);
}

void	enable_queue(bool enabled)
{
	sigset_t	set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	if (enabled)
		sigprocmask(SIG_BLOCK, &set, NULL);
	else
		sigprocmask(SIG_UNBLOCK, &set, NULL);
	return;
}

void	set_sigaction_handler(void (*handler)(int, siginfo_t *, void *))
{
	struct	sigaction	act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	return ;
}

int	main(void)
{
	g_status = malloc(sizeof(t_handler));
	if (!g_status)
		return (1);
	init_values_storage(g_status, false);
	ft_printf("%i\n", getpid());
	while (1)
		pause();
	if (g_status->message)
		free(g_status->message);
	free(g_status);
	return (0);
}
