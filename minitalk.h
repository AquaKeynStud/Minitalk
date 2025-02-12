/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:57:19 by arocca            #+#    #+#             */
/*   Updated: 2025/02/12 15:27:39 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define  MINITALK_H

typedef struct	s_handler
{
	int		bit_counter;
	int		character;
	int		fill_index;
	size_t	message_len;
	char	*message;
}				t_handler;

void	init_values_storage(t_handler *handler, bool is_init);
void	len_handler(int signal, siginfo_t *info, void *context);
void	char_handler(int signal, siginfo_t *info, void *context);
void	set_sigaction_handler(void (*handler)(int, siginfo_t *, void *));
void	enable_queue(bool enabled);

#endif