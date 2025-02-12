/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:45:20 by keyn              #+#    #+#             */
/*   Updated: 2025/02/12 18:13:28 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

void	send_char(int pid, int c, bool isSize)
{
	int	i;

	if (isSize)
		i = 32;
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
	if (!isSize)
		ft_printf("Lettre envoyée : %c\n", (char)c);
	return ;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	len;

	if (argc != 3)
		return (ft_printf("format : %s <pid> <message>\n", argv[0]));
	ft_printf("Message à envoyer : %s\n", argv[2]); // Optionnel
	ft_printf("Envoi au pid : %s\n", argv[1]); // Optionnel
	pid = ft_atoi(argv[1]);
	len = (int)ft_strlen(argv[2]);
	ft_printf("Taille : %i\n", len);
	send_char(pid, len, true);
	while (*argv[2])
		send_char(pid, *argv[2]++, false);
	send_char(pid, '\0', false);
	return (0);
}
