/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:19 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/02 00:26:38 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_sharp(long long value, const char *fmt)
{
	int	len;

	len = 0;
	if (*fmt == 'o')
	{
		len = write(1, "0", 1);
		len += ft_putnbr_base(value, "01234567");
	}
	else if (*fmt == 'x')
	{
		if (value != 0 && value != LONG_MIN)
				len = write(1, "0x", 2);
		len += ft_putnbr_base(value, "0123456789abcdef");
	}
	else if (*fmt == 'X')
	{
		if (value != 0 && value != LONG_MIN)
			len = write(1, "0X", 2);
		len += ft_putnbr_base(value, "0123456789ABCDEF");
	}
	return (len);
}

int	ft_handle_space(int value, const char **fmt)
{
	int	len;

	len = 0;
	if (**fmt == 'd' || **fmt == 'i')
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

int	ft_handle_plus(int value, const char **fmt)
{
	int	len;

	len = 0;
	if (**fmt == 'd' || **fmt == 'i')
	{
		if (value >= 0)
		{
			len = ft_putchar('+');
			len += ft_putnbr(value);
		}
		else
			len = ft_putnbr(value);
	}
	return (len);
}
