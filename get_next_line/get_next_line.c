/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:54:47 by ecunha            #+#    #+#             */
/*   Updated: 2023/06/21 15:57:57 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

/*
	-len of the first line
	-if eol == \0 free buffer return NULL
	-allocate line = len of file - len of firstline + 1
	-copy buffer into line
	-free buffer
*/
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

/*
	-allocate res if don't exist
	-allocate buffer
	-while read >= 1
		-read into buffer
		-if error return NULL + free buffer
		-put \0 at end of buffer
		-res =  res + buffer and free res
		-if \n in buffer break
	-free buffer
	-return res
*/

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

/*
	check if buffer is empty
		yes = return NULL
		no = find len of first line
			allocate len of first line + 2
			if line == \0 return NULL
			copy of buffer into line
			if buffer[i] == \n line[i] == \n
			return line
*/

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] || buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

/*
	-buffer = copy file into buffer until \n or eof
	-line = alloc buffer + copy buffer until \n or eof
	-buffer = copy buffer from \n to the next \n or eof
*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
