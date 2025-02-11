/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:57:19 by arocca            #+#    #+#             */
/*   Updated: 2025/02/11 16:58:34 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define  MINITALK_H

typedef struct	s_handler
{
	int		bit_counter;
	size_t	message_len;
	char	*message;
}				t_handler;

#endif