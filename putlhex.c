/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:42:58 by habdella          #+#    #+#             */
/*   Updated: 2024/11/09 15:31:44 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putlhex(unsigned int nb, char key)
{
	char	*hex;
	int		len;

	len = 0;
	if (key == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
		len += putlhex(nb / 16, key);
	putlchar(hex[nb % 16]);
	len++;
	return (len);
}
