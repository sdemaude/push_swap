/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:19:02 by sdemaude          #+#    #+#             */
/*   Updated: 2023/11/26 17:01:16 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# ifndef FD_MAX
#  define FD_MAX 128

# endif

char	*get_next_line(int fd);
char	*to_line(char *str);
int		ft_is_nl(char *str);
size_t	mod_strlen(const char *str);
char	*mod_strjoin(char const *s1, char const *s2, long long ir);
void	to_save(char *str);

#endif
