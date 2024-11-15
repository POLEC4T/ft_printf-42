/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:22:20 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/15 18:43:12 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_unsigned_nbr_fd(unsigned int nbr, int fd)
{
	int	counter;

	counter = 0;
	if (nbr > 9)
		counter += ft_put_unsigned_nbr_fd(nbr / 10, fd);
	return (counter + ft_putchar_fd((nbr % 10) + '0', fd));
}

int	ft_putaddr_fd(unsigned long long addr, int fd)
{
	int	counter;

	if (!addr)
		return (ft_putstr_fd("(nil)", fd));
	counter = 0;
	counter += ft_putstr_fd("0x", fd);
	counter += ft_put_ul_base(addr, "0123456789abcdef", fd);
	return (counter);
}
