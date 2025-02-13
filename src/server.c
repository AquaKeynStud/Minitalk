/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca42student@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:36:42 by keyn              #+#    #+#             */
/*   Updated: 2025/02/13 17:36:36 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_handler	*g_status;

void	init_values_storage(t_handler *handler, bool is_init)
{
	handler->bit_counter = 0;
	if (is_init)
	{
		set_sigaction_server(char_handler);
		return ;
	}
	handler->message_len = 0;
	handler->character = 0;
	handler->fill_index = 0;
	handler->message = NULL;
	set_sigaction_server(len_handler);
}

void	cleanup_and_exit(int signal)
{
	(void)signal;
	if (g_status->message)
	{
		free(g_status->message);
		g_status->message = NULL;
	}
	free(g_status);
	ft_printf("\n   \033[33m\033[47m🚧 - Server stopped - 🚧\033[0m\n");
	exit(0);
}

void	len_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR2)
		g_status->message_len |= (1U << (31 - g_status->bit_counter));
	g_status->bit_counter++;
	if (g_status->bit_counter == 32)
	{
		g_status->message = (char *)malloc(g_status->message_len + 1);
		if (!g_status->message)
			return ;
		g_status->message[g_status->message_len] = '\0';
		init_values_storage(g_status, true);
	}
	kill(info->si_pid, SIGUSR1);
}

void	char_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR2)
		g_status->character |= (1 << (7 - g_status->bit_counter));
	g_status->bit_counter++;
	if (g_status->bit_counter == 8)
	{
		if (g_status->fill_index < g_status->message_len)
		{
			g_status->message[g_status->fill_index++] = g_status->character;
			g_status->bit_counter = 0;
			g_status->character = 0;
		}
		if (g_status->fill_index == g_status->message_len)
		{
			ft_printf("%s\n", g_status->message);
			free(g_status->message);
			g_status->message = NULL;
			init_values_storage(g_status, false);
			kill(info->si_pid, SIGUSR2);
		}
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	set_sigaction_exit(cleanup_and_exit);
	g_status = malloc(sizeof(t_handler));
	if (!g_status)
		return (1);
	init_values_storage(g_status, false);
	ft_printf("\033[36m\033[47m\033[1m");
	ft_printf("⛲️ - Welcome to Minitalk ! - ⛲️\033[0m\n");
	ft_printf("   \033[34m\033[47m🌐 - Processus Id : %i\033[0m\n", getpid());
	while (1)
		pause();
	if (g_status->message)
	{
		free(g_status->message);
		g_status->message = NULL;
	}
	free(g_status);
	return (0);
}
