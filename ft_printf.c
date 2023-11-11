#include <stdarg.h>
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static int ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

static int	ft_putnbr(long long nbr)
{
	int			len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		len += ft_putchar(nbr + '0');
	}
	else
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	return (len);
}
static int	ft_putnbr_base_p(uintptr_t nb, char *base)
{
	long long		i;
	char			result [100];
	int				len;

	if (nb == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	i = 0;
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
	len = i;
	while (i > 0)
		ft_putchar(result[i-- - 1]);
	return (len);
}

static int	ft_putnbr_base(unsigned int nb, char *base)
{
	long long		i;
	char			result [100];
	int				len;

	if (nb == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	i = 0;
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
	len = i;
	while (i > 0)
		ft_putchar(result[i-- - 1]);
	return (len);
}

static int ft_handle_sharp(long long value, const char *fmt)
{
	int len;

	len = 0;
	if (*fmt == '#')
	fmt++;
	if (*fmt == 'o')
	{
		len += write(1, "0", 1);
		len += ft_putnbr_base(value, "01234567");
	}
	else if (*fmt == 'x')
	{
        if (value != 0 && value != LONG_MIN)
			len += write(1, "0x", 2);
		len += ft_putnbr_base(value, "0123456789abcdef");
	}
	else if (*fmt == 'X')
	{
        if (value != 0 && value != LONG_MIN)
			len += write(1, "0X", 2);
		len += ft_putnbr_base(value, "0123456789ABCDEF");
	}
	return (len);
}

static int	ft_handle_space(int value, const char *fmt)
{
	int len;

	len = 0;
	if (*fmt == ' ')
	fmt++;
	if (*fmt == 'd' || *fmt == 'i')
	{
		if (value >= 0)
		{
			len = ft_putchar(' ');
			len += ft_putnbr(value);
		}
		else
			len = ft_putnbr(value);
	}
	return (len);
}

static int	ft_handle_plus(int value, const char *fmt)
{
	int len;

	len = 0;
	while (*fmt == '+' || *fmt == ' ')
	fmt++;
	if (*fmt == 'd' || *fmt == 'i')
	{
		if (value >= 0)
		{
			len += ft_putchar('+');
			len += ft_putnbr(value);
		}
		else
			len += ft_putnbr(value);
	}
	return (len);
}

static int	ft_handle_s(const char *str)
{
	int	len;

	if (str != NULL)
		ft_putstr(str);
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	return (len);
}

static int ft_handle_u(unsigned int value)
{
	int len;

	len = ft_putnbr(value);
	return (len);
}

static int	ft_handle_d_i(int value)
{
	int len;

	len = ft_putnbr(value);
	return (len);
}

static int	ft_handle_x_X(const char c, long long value)
{
	int len;

	len = 0;
	if (c == 'x')
	{
		len = ft_putnbr_base(value, "0123456789abcdef");
	}
	else if (c == 'X')
	{
		len = ft_putnbr_base(value, "0123456789ABCDEF");
	}
	return (len);
}

static int ft_handle_p(void* ptr)
{
	int	len;

	len = 0;
	if (ptr != NULL)
	{
		write(1, "0x", 2);
        len = ft_putnbr_base_p((uintptr_t)ptr, "0123456789abcdef") + 2;
	}
	else
	{
		write(1, "0x0", 3);
        len = 3;
	}
	return (len);
}


static int	ft_handle_c(int fmt)
{
	int len;

	len = ft_putchar(fmt);
	return (len);
}

static int	ft_handle_flags(const char **fmt, va_list *ap)
{
	int len;

	len = 0;
	if (((**fmt == ' ') && *(*fmt + 1) == '+')
		|| (**fmt == '+' && *(*fmt + 1) == ' '))
	{
		len = ft_handle_plus(va_arg(*ap, int), *fmt);
	(*fmt)++;
	(*fmt)++;
	}
	else if (**fmt == '+')
	{
		len = ft_handle_plus(va_arg(*ap, int), *fmt);
		(*fmt)++;
	}
	else if (**fmt == ' ')
	{
		len = ft_handle_space(va_arg(*ap, int), *fmt);
		(*fmt)++;
	}
	else if (**fmt == '#')
	{
		len = ft_handle_sharp(va_arg(*ap, long long), *fmt);
		(*fmt)++;
	}
	return (len);
}

static int	ft_handle_mandatory(const char *fmt, va_list *ap)
{
	int len;

	len = 0;
	if (*fmt == 's')
		len += ft_handle_s(va_arg(*ap, char*));
	else if (*fmt == 'c')
		len += ft_handle_c(va_arg(*ap, int));
	else if (*fmt == 'd' || *fmt == 'i')
		len += ft_handle_d_i(va_arg(*ap, int));
	else if (*fmt == 'u')
		len += ft_handle_u(va_arg(*ap, unsigned int));
	else if (*fmt == 'x' || *fmt == 'X')
		len += ft_handle_x_X(*fmt, va_arg(*ap, long long));
	else if (*fmt == 'p')
		len += ft_handle_p(va_arg(*ap, void*));
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			len += ft_putchar(*fmt);
		else
		{
			fmt++;
			if (*fmt == '%')
				len += ft_putchar('%');
			len += ft_handle_mandatory(fmt, &ap);
			len += ft_handle_flags(&fmt, &ap);
		}
		fmt++;
	}
	va_end(ap);
	return (len);
}

/*#include <stdio.h>


int main() {
    int num = 42;
    char *str = "Hello, World!";
    char c = 'A';
    int *ptr = &num;

	int	my_print;
	int	orig_print;

    my_print = ft_printf("Testing integers: %d %i %x %X %+d %u\n", num, num, num, num, num, num);
	ft_printf("NUMBER OF CHAR %d\n", my_print);
    orig_print = printf("Testing integers: %d %i %x %X %+d %u\n", num, num, num, num, num, num);
	printf("NUMBER OF CHAR %d\n", orig_print);

   my_print = ft_printf("Testing strings and characters: %s %c\n", str, c);
   	ft_printf("NUMBER OF CHAR %d\n", my_print);
    orig_print = printf("Testing strings and characters: %s %c\n", str, c);
	printf("NUMBER OF CHAR %d\n", orig_print);

    my_print = ft_printf("Testing pointers: %p\n", ptr);
	ft_printf("NUMBER OF CHAR %d\n", my_print);
    orig_print = printf("Testing pointers: %p\n", ptr);
	printf("NUMBER OF CHAR %d\n", orig_print);

    my_print = ft_printf("Testing mixed formats: %d %s %x %c %p\n", num, str, num, c, ptr);
	ft_printf("NUMBER OF CHAR %d\n", my_print);
    orig_print = printf("Testing mixed formats: %d %s %x %c %p\n", num, str, num, c, ptr);
	printf("NUMBER OF CHAR %d\n", orig_print);

    my_print = ft_printf("Testing %% character: 100%%\n");
	ft_printf("NUMBER OF CHAR %d\n", my_print);
    orig_print = printf("Testing %% character: 100%%\n");
	printf("NUMBER OF CHAR %d\n", orig_print);

	return 0;
}*/

