/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:29:41 by habdella          #+#    #+#             */
/*   Updated: 2024/11/07 08:49:36 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX\%", format[i + 1]))
		{
			len += check_format(list, format, i + 1);
			i += 2;
		}
		else
		{
			len += putlchar(format[i]);
			i++;
		}
	}
	va_end(list);
	return (len);
}
