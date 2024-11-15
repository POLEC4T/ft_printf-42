/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:22:13 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/15 18:49:49 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdint.h>

int	print_arg(char flag, va_list ptr)
{
	int	counter;

	counter = 0;
	if (flag == 's')
		counter += ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (flag == 'd' || flag == 'i')
		counter += ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (flag == 'c')
		counter += ft_putchar_fd(va_arg(ptr, int), 1);
	else if (flag == 'u')
		counter += ft_put_unsigned_nbr_fd(va_arg(ptr, unsigned int), 1);
	else if (flag == 'x')
		counter += ft_putnbr_base(va_arg(ptr, int), "0123456789abcdef", 1);
	else if (flag == 'X')
		counter += ft_putnbr_base(va_arg(ptr, int), "0123456789ABCDEF", 1);
	else if (flag == '%')
		counter += ft_putchar_fd('%', 1);
	else if (flag == 'p')
		counter += ft_putaddr_fd(va_arg(ptr, unsigned long long), 1);
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		counter;

	counter = 0;
	if (!str || write(1, 0, 0) == -1)
		return (-1);
	va_start(ptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			counter += print_arg(str[i + 1], ptr);
			i++;
		}
		else
		{
			counter += ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end(ptr);
	return (counter);
}

// #include <limits.h>
// #include <stdio.h>

// #define CONTENT "u", "toi"

// int	main(void)
// {
// 	// printf(CONTENT);
// 	// d c u x X % p i
// 	// printf("\nsize:%d\n", printf(CONTENT));
// 	char *str;

// 	str = NULL;
// 	printf("\nsize:%d\n", ft_printf(CONTENT));
// 	printf("\n");
// 	// printf("\nsize:%d\n", printf(CONTENT));

// 	// printf("hello %l");
// }

int main()
{
	void *ptr;
	
	ft_printf("%p\n", (void *)__LONG_MAX__);
	printf("%p\n", (void *)__LONG_MAX__);
}