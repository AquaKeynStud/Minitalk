/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:36:42 by keyn              #+#    #+#             */
/*   Updated: 2025/02/10 14:01:09 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	get_mess_len(size_t	len, int signal)
{
	return (0);
}

int	main(void)
{
	size_t	len;

	len = 0;
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
