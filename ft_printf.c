#include "ft_printf.h"
#include "unistd.h"

int	is_flag_valid(char flag)
{
	char	*flags;
	int		i;

	flags = "cspdiuxX%";
	while (flags[i])
	{
		if (flags[i] == flag)
			return (1);
		i++;
	}
	return (0);
}

void	print_arg(char flag)
{
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			write(1, "xxx", 3);
			if (is_flag_valid(str[i + 1]))
			{
				print_arg(str[i + 1]);
                i++;
			}
			else
                write(1,str[i],1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	va_start(ptr, str);
	va_arg(ptr, typeof(*ptr));
	va_end(ptr);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("coucou%s");

	printf("cou%k");
}