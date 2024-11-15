/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:22:03 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/15 18:43:19 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_put_unsigned_nbr_fd(unsigned int nbr, int fd);
int	ft_put_ul_base(unsigned long long nbr, char *base, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int nbr, int fd);
int	ft_putnbr_base(int nbr, char *base, int fd);
int	ft_putaddr_fd(unsigned long long addr, int fd);
int	ft_putstr_fd(char *s, int fd);
int ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);

#endif