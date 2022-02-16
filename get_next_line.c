/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:09:43 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/08 17:47:23 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*read_buff(int fd)
{
	char	*tem;
	int		byte;

	tem = malloc(BUFFER_SIZE + 1);
	if (!tem)
		return (NULL);
	byte = read(fd, tem, BUFFER_SIZE);
	if (byte < 0)
	{
		free(tem);
		return (NULL);
	}
	tem[byte] = '\0';
	return (tem);
}

static char	*expand_buffer(char *buff, int fd)
{
	char	*new_buff;
	int		new_len;
	char	*tem;

	tem = read_buff(fd);
	if (!tem)
		return (NULL);
	if (!tem[0])
	{
		free(tem);
		return (buff);
	}
	if (!buff)
		return (tem);
	new_len = ft_strlen(buff) + ft_strlen(tem);
	new_buff = malloc(new_len + 1);
	if (!new_buff)
		return (NULL);
	ft_strlcpy(new_buff, buff, new_len + 1);
	ft_strlcat(new_buff, tem, new_len + 1);
	free(buff);
	free(tem);
	return (new_buff);
}

static char	*shrink_buffer(char *buff, char *line)
{
	char	*new_buff;
	int		line_len;
	int		buff_len;

	if (!buff || !line)
		return (buff);
	buff_len = ft_strlen(buff);
	line_len = ft_strlen(line);
	if (buff_len == line_len)
	{
		free(buff);
		return (NULL);
	}
	new_buff = ft_substr(buff, line_len, buff_len - line_len);
	free(buff);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[BUFFER_SIZE];
	char		*line;
	size_t		before_len;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = NULL;
	if (where_is_newline(buff[fd], '\n') == -1)
	{
		before_len = ft_strlen(buff[fd]);
		buff[fd] = expand_buffer(buff[fd], fd);
		if (before_len == ft_strlen(buff[fd]) && buff[fd])
			line = ft_substr(buff[fd], 0, ft_strlen(buff[fd]));
	}
	if (!buff[fd])
		return (NULL);
	if (!line && where_is_newline(buff[fd], '\n') != -1)
		line = ft_substr(buff[fd], 0, where_is_newline(buff[fd], '\n') + 1);
	if (line)
	{
		buff[fd] = shrink_buffer(buff[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}
