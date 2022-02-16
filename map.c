/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:07:54 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/12 23:39:08 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_(char *s1, char *s2)
{
	int		len_1;
	int		len_2;
	char	*s3;
	int		i;

	if (!s2)
		return (ft_strdup(""));
	i = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	s3 = (char *)malloc(len_1 + len_2 + 1);
	if (!s3)
		return (ft_strdup(""));
	while (i < len_1 || i < len_2)
	{
		if (i < len_1)
			s3[i] = s1[i];
		if (i < len_2)
			s3[i + len_1] = s2[i];
		i++;
	}
	s3[len_1 + len_2] = '\0';
	free(s1);
	return (s3);
}

int	print_error(char *txt)
{
	printf("Error\n%s\n", txt);
	exit(0);
	return (0);
}

void	read_map(int fd, t_game *info, char **str)
{
	char	*line;
	char	*last_line;

	line = ft_strdup("");
	last_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!info->width)
				print_error("Empty map!");
			else
				check_map(last_line, info);
			free(last_line);
			break ;
		}
		free(last_line);
		check_map(line, info);
		last_line = ft_substr(line, 0, ft_strlen(line));
		*str = ft_(*str, line);
		free(line);
		info->height++;
	}
}

void	check_map(char *line, t_game *info)
{
	if (!info->width)
		info->width = ft_strlen(line) - 1;
}
