/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_libft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:12:19 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 15:24:38 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"
#include "../header/parsing.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	while (s1[i])
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(*s1));
	i = 0;
	if (ptr == NULL)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	if (!str)
		return (0);
	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == 0)
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi_check(const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 15))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > 255)
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}
