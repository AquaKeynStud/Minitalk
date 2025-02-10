/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:27:17 by arocca            #+#    #+#             */
/*   Updated: 2025/01/15 14:27:17 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdint.h>

int	authorized_c(char c)
{
	char	*conv;
	int		i;

	i = 0;
	conv = "-0.+ #123456789";
	while (conv[i])
	{
		if (conv[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	check_conv(char c)
{
	char	*types;

	types = "cspdiuxX%";
	while (*types)
	{
		if (*types == c)
			return (*types);
		types++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr++ - '0');
		if (res > LLONG_MAX && sign < 0)
			return (0);
		if (res > LLONG_MAX)
			return (-1);
	}
	return (((int)res) * sign);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	return (c > '0' && c <= '9');
}
