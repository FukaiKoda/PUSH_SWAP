/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlhex_ul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:31:59 by habdella          #+#    #+#             */
/*   Updated: 2024/11/09 15:32:00 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putlhex_ul(unsigned long nb, char key)
{
	char	*hex;
	int		len;

	len = 0;
	if (key == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
		len += putlhex_ul(nb / 16, key);
	putlchar(hex[nb % 16]);
	len++;
	return (len);
}
