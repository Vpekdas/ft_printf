#include <stdarg.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

static void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_putnbr_base(uintptr_t nbr, char *base)
{
	long int		i;
	char			result [100];
	long int		nb;

	if (nbr == 0)
		ft_putchar(base[0]);
	i = 0;
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (nb > 0)
	{
		result[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i++;
	}
	while (i > 0)
		ft_putchar(result[i-- - 1]);
}

void ft_handle_sharp(int value, const char *fmt)
{
	if (*fmt == '#')
	fmt++;
	if (*fmt == 'o')
	{
		write(1, "0", 1);
		ft_putnbr_base(value, "01234567");
	}
	else if (*fmt == 'x')
	{
		write(1, "0", 1);
		write(1, &*fmt, 1);
		ft_putnbr_base(value, "0123456789abcdef");
	}
	else if (*fmt == 'X')
	{
		write(1, "0", 1);
		write(1, &*fmt, 1);
		ft_putnbr_base(value, "0123456789ABCDEF");
	}
}

void	ft_handle_space(int value, const char *fmt)
{
	if (*fmt == ' ')
	fmt++;
	if (*fmt == 'd' || *fmt == 'i')
	{
		if (value >= 0)
		{
			ft_putchar(' ');
			ft_putnbr(value);
		}
		else
			ft_putnbr(value);
	}
}

void	ft_handle_plus(int value, const char *fmt)
{
	while (*fmt == '+' || *fmt == ' ')
	fmt++;
	if (*fmt == 'd' || *fmt == 'i')
	{
		if (value >= 0)
		{
			ft_putchar('+');
			ft_putnbr(value);
		}
		else
			ft_putnbr(value);
	}
}

void	ft_handle_s(const char *str)
{
	if (str != NULL)
		ft_putstr(str);
	else
		ft_putstr("(null)");
}

void	ft_handle_u(unsigned int value)
{
	ft_putnbr(value);
}

void	ft_handle_d_i(int value)
{
	ft_putnbr(value);
}

void	ft_handle_x_X(const char c, int value)
{
	if (c == 'x')
	{
		ft_putnbr_base(value, "0123456789abcdef");
	}
	else if (c == 'X')
	{
		ft_putnbr_base(value, "0123456789ABCDEF");
	}
}

void	ft_handle_p(void* ptr)
{
	if (ptr != NULL)
	{
		write(1, "0x", 2);
		ft_putnbr_base((unsigned long long)ptr, "0123456789abcdef");
	}
	else
		write(1, "0x0", 3);
}

void	ft_handle_c(int fmt)
{
		ft_putchar(fmt);
}

void	ft_handle_flags(const char **fmt, va_list *ap)
{
	if (**fmt == ' ' && *(*fmt + 1) == '+'
		|| **fmt == '+' && *(*fmt + 1) == ' ')
	{
		ft_handle_plus(va_arg(*ap, int), *fmt);
	    (*fmt)++;
		(*fmt)++;
	}
	else if (**fmt == '+')
	{
		ft_handle_plus(va_arg(*ap, int), *fmt);
	    (*fmt)++;
	}
	else if (**fmt == ' ')
	{
		ft_handle_space(va_arg(*ap, int), *fmt);
		(*fmt)++;
	}
	else if (**fmt == '#')
	{
		ft_handle_sharp(va_arg(*ap, int), *fmt);
		(*fmt)++;
	}
}

void	ft_handle_mandatory(const char *fmt, va_list *ap)
{
	if (*fmt == 's')
		ft_handle_s(va_arg(*ap, char*));
	else if (*fmt == 'c')
		ft_handle_c(va_arg(*ap, int));
	else if (*fmt == 'd' || *fmt == 'i')
		ft_handle_d_i(va_arg(*ap, int));
	else if (*fmt == 'u')
		ft_handle_u(va_arg(*ap, unsigned int));
	else if (*fmt == 'x' || *fmt == 'X')
		ft_handle_x_X(*fmt, va_arg(*ap, int));
	else if (*fmt == 'p')
		ft_handle_p(va_arg(*ap, void*));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			ft_putchar(*fmt);
		else
		{
			fmt++;
			if (*fmt == '%')
				ft_putchar('%');
			ft_handle_mandatory(fmt, &ap);
			ft_handle_flags(&fmt, &ap);
		}
		fmt++;
	}
	va_end(ap);
	return (0);
}

#include <stdio.h>

int main() {
int number = 42;
ft_printf("Combined Flags: %+ d\n", number);
printf("Combined Flags: %+ d\n", number);

    return 0;
}
