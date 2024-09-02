/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:19:13 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/08/31 18:47:25 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"
#include "../header/parsing.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCan't open the file: %s\n", path);
		exit(1);
	}
	return (fd);
}

static char	*ft_smart_trim(char **temp)
{
	char		*trim_temp;

	if (!is_empty(*temp))
	{
		trim_temp = *temp;
		*temp = ft_strtrim_end(*temp, "\t\f\r\v\n ");
		free(trim_temp);
	}
	else
	{
		trim_temp = *temp;
		*temp = (char *)malloc(sizeof(char) * 3);
		if (!(*temp))
			return (NULL);
		(*temp)[0] = ' ';
		(*temp)[1] = '\n';
		(*temp)[2] = '\0';
		free(trim_temp);
	}
	return (*temp);
}


//it's not show malloc error
char	**read_file(int fd)
{
	t_file	file;

	file.temp = NULL;
	file.line = NULL;
	while (1)
	{
		file.temp = get_next_line(fd);
		if (!file.temp)
			break ;
		file.temp = ft_smart_trim(&file.temp);
		if (!file.temp)
			return (NULL);
		file.line = ft_strjoin_and_free(file.line, file.temp);
		free(file.temp);
		if (!file.line)
			return (NULL);
	}
	file.trim_temp = file.line;
	file.line = ft_strtrim(file.line, "\n");
	free(file.trim_temp);
	if (!file.line)
		return (NULL);
	file.map = ft_split(file.line, '\n');
	free(file.line);
	return (file.map);
}
