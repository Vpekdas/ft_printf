#include <stdarg.h>
#include "libft.h"

static void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

int	ft_handle_sharp(const char c, va_list ap)
{
	return (0);
}

int	ft_handle_space(const char c, va_list ap)
{
	return (0);
}

int	ft_handle_plus(const char c, va_list ap)
{
	return (0);
}

int	ft_handle_flags(const char c, va_list ap)
{
	if (c == '#')
		ft_handle_sharp(c, ap);
	else if (c == ' ')
		ft_handle_space(c, ap);
	else if (c == '+')
		ft_handle_plus(c, ap);
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
				ft_handle_flags(*fmt, ap);
		}
		return (0);
	}
	va_end(ap);
}

#include <stdio.h>

int main() {
    int num = 42;
    double floatValue = 12.345;
    
    // Demonstrating the # flag.
    printf("%#o\n", num);       // Outputs "052" with the # flag for octal.
    printf("%#x\n", num);       // Outputs "0x2a" with the # flag for hexadecimal.
    printf("%#f\n", floatValue); // Outputs "12.345000" with the # flag for floating-point.

    // Demonstrating the + flag.
    printf("%+d\n", num);       // Outputs "+42" with the + flag for positive numbers.
    printf("%+d\n", -num);      // Outputs "-42" with the + flag for negative numbers.
    printf("%+f\n", floatValue); // Outputs "+12.345000" with the + flag for positive floating-point.
    printf("%+f\n", -floatValue); // Outputs "-12.345000" with the + flag for negative floating-point.

    // Demonstrating the space flag.
    printf("% d\n", num);       // Outputs " 42" with a space for positive numbers.
    printf("% d\n", -num);      // Outputs "-42" with a minus sign for negative numbers.
    printf("% d\n", 0);         // Outputs " 0" with a space for zero.
    printf("% f\n", floatValue); // Outputs " 12.345000" with a space for positive floating-point.
    printf("% f\n", -floatValue); // Outputs "-12.345000" with a minus sign for negative floating-point.

    return 0;
}

