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

void	ft_putstr(char *str)
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
	int	value;

	value = va_arg(ap, int);
	if (*fmt == ' ')
	*fmt++;
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

void	ft_handle_plus(const char *fmt, va_list ap)
{
	int	value;

	value = va_arg(ap, int);
	if (*fmt == '+')
	*fmt++;
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

void	ft_handle_flags(const char *fmt, va_list ap)
{
	if (*fmt == '#')
		ft_handle_sharp(fmt, ap);
	else if (*fmt == ' ')
		ft_handle_space(fmt, ap);
	else if (*fmt == '+')
		ft_handle_plus(fmt, ap);
}

void	ft_handle_c_s(const char *fmt, va_list ap)
{
	char	c;
	char	*str;

	if (*fmt == 'c')
	{
		c = va_arg(ap, char);
		if (ft_isprint(c))
			ft_putchar(c);
	}
	else if (*fmt == 's')
	{
		str = va_arg(ap, char*);
		if (str != NULL)
			ft_putstr(str);
	}
}

void	ft_handle_u(const char *fmt, va_list ap)
{
	unsigned int	u_value;

	if (*fmt == 'u')
	{
		u_value = va_arg(ap, unsigned int);
		ft_putnbr(u_value);
	}
}

void	ft_handle_d_i(const char *fmt, va_list ap)
{
	int				value;

	if (*fmt == 'd' || *fmt == 'i')
	{
		value = va_arg(ap, int);
		ft_putnbr(value);
	}
}

void	ft_handle_x_X(const char *fmt, va_list ap)
{
	int	value;

	value = va_arg(ap, int);
	if (*fmt == 'x')
	{
		ft_putnbr_base(value, "0123456789abcdef");
	}
	else if (*fmt == 'X')
	{
		ft_putnbr_base(value, "0123456789ABCDEF");
	}
}

void	ft_handle_p(const char *fmt, va_list ap)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	if (ptr != NULL)
	{
		write(1, "0x", 3);
		ft_putnbr_base((unsigned long long)ptr, "0123456789abcdef");
	}
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
			else if (*fmt == 'c' || *fmt == 's')
				ft_handle_c_s(fmt, ap);
			else if (*fmt == 'd' || *fmt == 'i')
				ft_handle_d_i(fmt, ap);
			else if (*fmt == 'u')
				ft_handle_u(fmt,*fmt);
			else if (*fmt == 'x' || *fmt == 'X')
				ft_handle_x_X(fmt, ap);
			else if (*fmt == 'p')
				ft_handle_p(fmt, ap);
		}
		*fmt++;
	}
	va_end(ap);
	return (0);
}

#include <stdio.h>

int main() {
	int	num = 42;
	int	num2 = 24;
	int	num3 = 0;
	ft_printf("num -> %d -> num2 %d -> num3 %d\n", num, num2, num3);
	printf("num -> %d -> num2 %d -> num3 %d\n", num, num2, num3);
}

