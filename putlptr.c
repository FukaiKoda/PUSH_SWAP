/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:39:32 by habdella          #+#    #+#             */
/*   Updated: 2024/11/09 15:27:49 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putlptr(unsigned long ptr)
{
	if (ptr == 0)
		return (putlstr("(nil)"));
	return (putlstr("0x") + putlhex_ul(ptr, 'x'));
}
