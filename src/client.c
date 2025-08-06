/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca42student@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:45:20 by keyn              #+#    #+#             */
/*   Updated: 2025/02/13 17:39:14 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static bool	g_signal_received;

void	debounce(int signal)
{
	if (signal == SIGUSR1)
		g_signal_received = true;
	else
	{
		ft_printf("\033[32m");
		ft_printf("🎍 - The server did print the message ! - 🎍\n\033[0m");
	}
}

void	send_data(int pid, int c, int type_size)
{
	while (type_size--)
	{
		g_signal_received = false;
		if ((c >> type_size) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_signal_received)
			pause();
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	len;

	pid = ft_atoi(argv[1]);
	len = (unsigned int)ft_strlen(argv[2]);
	if (argc != 3 || pid <= 0 || kill(pid, 0) == -1)
	{
		ft_printf("\033[31m⛔️ format : %s <pid> <message> ⛔️", argv[0]);
		return (ft_printf("\033[0m\n"));
	}
	set_sigaction_client(debounce);
	ft_printf("📝 - %s - 📝\n", argv[2]);
	ft_printf("\033[34m🌐 - %s - 🌐\033[0m\n", argv[1]);
	ft_printf("\033[33m📏 - %i - 📏\033[0m\n", len);
	send_data(pid, len, 32);
	while (*argv[2])
		send_data(pid, *argv[2]++, 8);
	return (0);
}
