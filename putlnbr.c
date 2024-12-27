/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:44:45 by habdella          #+#    #+#             */
/*   Updated: 2024/11/05 09:54:09 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putlnbr(int nb)
{
	long	nbl;
	int		len;

	nbl = nb;
	len = 0;
	if (nbl < 0)
	{
		nbl = -nbl;
		putlchar('-');
		len++;
	}
	if (nbl > 9)
		len += putlnbr(nbl / 10);
	putlchar(nbl % 10 + 48);
	len++;
	return (len);
}
