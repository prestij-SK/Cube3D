/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:03:52 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/08/31 18:49:14 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"
#include "../header/parsing.h"

char	*err_message(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	system("leaks the_game");
	exit(1);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(" \t\r\v\f\n", str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !arr[0])
		return (i);
	while (arr[i])
		i++;
	return (i);
}

char	*ft_strjoin_and_free(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}
