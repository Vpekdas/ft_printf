/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mandatory2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:20:50 by vopekdas          #+#    #+#             */
/*   Updated: 2024/06/02 00:26:38 by vopekdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_handle_c(int fmt)
{
	int	len;

	len = 0;
	len = ft_putchar(fmt);
	return (len);
}

int	ft_handle_percent(const char **fmt)
{
	int	len;

	len = 0;
	len = ft_putchar('%');
		(*fmt)++;
	return (len);
}
