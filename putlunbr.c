/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlunbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:44:00 by habdella          #+#    #+#             */
/*   Updated: 2024/11/06 11:43:33 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putlunbr(unsigned int nb)
{
	int		len;

	len = 0;
	if (nb > 9)
		len += putlunbr(nb / 10);
	putlchar(nb % 10 + 48);
	len++;
	return (len);
}
