/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_printers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:27:07 by arocca            #+#    #+#             */
/*   Updated: 2025/01/27 18:29:05 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, size_t *total_len, int (*f)[8])
{
	long	nb;
	char	digit;

	if (f && !(*f)[6] && (*f)[2] && n == 0)
	{
		*total_len += write(fd, " ", 1);
		return ;
	}
	nb = (long)n;
	if ((!f && n < 0))
		*total_len += write(fd, "-", 1);
	if (nb < 0)
		nb = -nb;
	if (nb <= 9)
	{
		digit = '0' + nb;
		*total_len += write(fd, &digit, 1);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd, total_len, NULL);
		digit = '0' + (nb % 10);
		*total_len += write(fd, &digit, 1);
	}
	return ;
}

void	ft_putunbr_fd(unsigned int n, int fd, size_t *total_len, int (*f)[8])
{
	unsigned long	nb;
	char			digit;

	if (f && !(*f)[6] && (*f)[2] && n == 0)
	{
		*total_len += write(fd, " ", 1);
		return ;
	}
	nb = (unsigned long)n;
	if (nb <= 9)
	{
		digit = '0' + nb;
		*total_len += write(fd, &digit, 1);
	}
	else
	{
		ft_putunbr_fd(nb / 10, fd, total_len, NULL);
		digit = '0' + (nb % 10);
		*total_len += write(fd, &digit, 1);
	}
	return ;
}

void	convert_to(unsigned long nbr, char *base, size_t *total_len)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (nbr < base_len)
		*total_len += write(1, &base[nbr % base_len], 1);
	else
	{
		convert_to(nbr / base_len, base, total_len);
		*total_len += write(1, &base[nbr % base_len], 1);
	}
	return ;
}

void	ft_print_memory(void *addr, size_t *total_len)
{
	unsigned long	a;

	a = (unsigned long)addr;
	*total_len += write(1, "0x", 2);
	convert_to(a, "0123456789abcdef", total_len);
	return ;
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
