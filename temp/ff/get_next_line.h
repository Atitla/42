/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:24:44 by dbaule            #+#    #+#             */
/*   Updated: 2024/01/18 14:20:29 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *string);
char	*ft_strchr(char *a);
void	*ft_calloc(size_t elementCount, size_t elementSize);

#endif
