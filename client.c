/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:45:20 by keyn              #+#    #+#             */
/*   Updated: 2025/02/10 13:55:16 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

void	send_char(int pid, char c, bool isSize)
{
	int	i;

	if (isSize)
		i = 64;
	else
		i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	len;

	if (argc != 3)
	{
		ft_printf("format : ./%s <pid> <message>\n", argv[0]);
		return (1);
	}
	ft_printf("Message à envoyer : %s\n", argv[2]); // Optionnel
	ft_printf("Envoi au pid : %s", argv[1]); // Optionnel
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	send_char(len, true);
	while (*argv[2]++)
		send_char(*argv[2], false);
	send_char('\0', false);
	return (0);
}
