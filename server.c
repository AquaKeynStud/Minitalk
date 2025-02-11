/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:36:42 by keyn              #+#    #+#             */
/*   Updated: 2025/02/11 17:13:03 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"
#include "ft_printf.h"

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

struct t_handler	init_values_storage(t_handler *handler, bool is_init)
{
	if (!is_init)
	{
		handler->message_len = 0;
		handler->bit_counter = 0;
		handler->message = NULL;
		set_sigaction_handler(); // Fonction pour calculer la taille
		return (handler);
	}
}

int	main(void)
{
	static t_handler	*status;

	status = init_values_storage(status);
	ft_printf("%i\n", getpid());
	while (1)
		pause();
	return (0);
}
