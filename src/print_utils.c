/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:44:45 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/15 18:57:57 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_fd(int nbr, int fd)
{
	unsigned int	u_nbr;
	int				counter;

	counter = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		counter++;
		u_nbr = -nbr;
	}
	else
		u_nbr = nbr;
	if (u_nbr < 10)
	{
		return (counter + ft_putchar_fd(nbr + '0', fd));
	}
	else
	{
		counter += ft_putnbr_fd(u_nbr / 10, fd);
		return (counter + ft_putnbr_fd(u_nbr % 10, fd));
	}
}

int	ft_putnbr_base(int nbr, char *base, int fd)
{
	unsigned int	u_nbr;
	int				counter;

	counter = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		counter++;
		u_nbr = -nbr;
	}
	else
		u_nbr = nbr;
	if (u_nbr < ft_strlen(base))
	{
		return (counter + ft_putchar_fd(base[u_nbr], fd));
	}
	else
	{
		counter += ft_putnbr_base(u_nbr / ft_strlen(base), base, fd);
		return (counter + ft_putnbr_base(u_nbr % ft_strlen(base), base, fd));
	}
}

int	ft_put_ul_base(unsigned long long nbr, char *base, int fd)
{
	int	counter;

	counter = 0;
	if (nbr < ft_strlen(base))
	{
		return (counter + ft_putchar_fd(base[nbr], fd));
	}
	else
	{
		counter += ft_putnbr_base(nbr / ft_strlen(base), base, fd);
		return (counter + ft_putnbr_base(nbr % ft_strlen(base), base, fd));
	}
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
