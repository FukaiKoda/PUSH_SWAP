/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:45:26 by habdella          #+#    #+#             */
/*   Updated: 2024/11/09 15:25:02 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list list, const char *format, int i)
{
	if (format[i] == 'c')
		return (putlchar(va_arg(list, int)));
	else if (format[i] == 's')
		return (putlstr(va_arg(list, char *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (putlnbr(va_arg(list, int)));
	else if (format[i] == 'u')
		return (putlunbr(va_arg(list, unsigned int)));
	else if (format[i] == 'x' || format[i] == 'X')
		return (putlhex(va_arg(list, unsigned int), format[i]));
	else if (format[i] == 'p')
		return (putlptr(va_arg(list, unsigned long)));
	else if (format[i] == '%')
		return (putlchar('%'));
	return (0);
}
