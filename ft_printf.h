/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:10:18 by habdella          #+#    #+#             */
/*   Updated: 2024/11/09 15:30:51 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//libraries
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//functions
int		putlchar(char c);
int		putlstr(char *s);
int		putlhex(unsigned int nb, char key);
int		putlunbr(unsigned int nb);
int		putlnbr(int nb);
int		putlptr(unsigned long ptr);
int		check_format(va_list list, const char *format, int i);
int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		putlhex_ul(unsigned long nb, char key);

#endif
