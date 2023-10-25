#include <stdarg.h>
#include "libft.h"

static void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
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

void ft_handle_sharp(const char *fmt, va_list ap)
{
	int	value;

	value = va_arg(ap, int);
	if (*fmt == '#')
	*fmt++;
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

void	ft_handle_space(const char *fmt, va_list ap)
{
	
}

int	ft_handle_plus(const char *fmt, va_list ap)
{
	return (0);
}

int	ft_handle_flags(const char *fmt, va_list ap)
{
	if (*fmt == '#')
		ft_handle_sharp(fmt, ap);
	else if (*fmt == ' ')
		ft_handle_space(fmt, ap);
	else if (*fmt == '+')
		ft_handle_plus(fmt, ap);
	return (0);
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
			*fmt++;
			if (*fmt == '%')
				ft_putchar('%');
			else if (*fmt == '#' || *fmt == ' ' || *fmt == '+')
			{
				ft_handle_flags(fmt, ap);
				*fmt++;
			}
		}
		*fmt++;
	}
	va_end(ap);
	return (0);
}

#include <stdio.h>

int main() {
    int num = 42;

	ft_printf("%#o\n", num);
	printf("%#o\n", num);
	ft_printf("%#x\n", num);
	printf("%#x\n", num);
	ft_printf("%#X\n", num);
	printf("%#X\n", num);
    return 0;
}

