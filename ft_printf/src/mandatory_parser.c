/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:26:50 by arocca            #+#    #+#             */
/*   Updated: 2025/02/02 11:02:31 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	parse_args(char *s, va_list *args, size_t *total_len)
{
	if (check_conv(s[0]))
		return (mandatory_parser(s[0], args, total_len, 0));
	if (check_conv(s[1]))
	{
		if (mandatory_parser(s[1], args, total_len, 1))
			return (mandatory_parser(s[1], args, total_len, 1) + 2);
		else
		{
			*total_len = -1;
			return (-1);
		}
	}
	else
		return (*total_len += write(1, "%", 1));
	return (0);
}
