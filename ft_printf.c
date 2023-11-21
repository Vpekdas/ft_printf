/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:38 by vopekdas          #+#    #+#             */
/*   Updated: 2023/11/21 16:23:01 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_handle_flags(const char **fmt, va_list *ap)
{
	int	len;

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

int	ft_handle_mandatory(const char *fmt, va_list *ap)
{
	int	len;

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

