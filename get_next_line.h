/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:10:03 by habdella          #+#    #+#             */
/*   Updated: 2024/12/24 11:11:58 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_container(char *contain, char *buff, int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*f_strchr(const char *s, char c);
char	*ft_strdupnl(char *contain);
char	*ft_strdup(const char *s);
char	*update(char *contain);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd, int flag);

#endif
