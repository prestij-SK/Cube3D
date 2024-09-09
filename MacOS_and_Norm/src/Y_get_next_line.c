/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:57:55 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 14:05:57 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

static char	*get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

static char	*get_left_str(int fd, char *left_str)
{
	char	*buffer;
	int		readed_char;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	readed_char = 1;
	while (!ft_strchr(left_str, 10) && readed_char != 0)
	{
		readed_char = read(fd, buffer, BUFFER_SIZE);
		if (readed_char < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed_char] = '\0';
		left_str = ft_strjoin_and_free(left_str, buffer);
	}
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_str);
		left_str = NULL;
		return (0);
	}
	left_str = get_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = get_line(left_str);
	left_str = get_new_left_str(left_str);
	return (line);
}
