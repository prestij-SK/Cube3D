/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_libft3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:55:46 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/08/30 14:13:36 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

static int	is_in_set(char const ch, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (dstsize != 0)
	{
		while (src[i] && (i < (dstsize - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ch;
	int		i;
	int		len;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	len = ft_strlen((char *)s1) - 1;
	while (len > 0 && is_in_set(s1[len], set))
		len--;
	if (len < i)
	{
		ch = (char *)malloc(1);
		ch[0] = '\0';
		return (ch);
	}
	ch = (char *)malloc(sizeof(char) * (len - i + 2));
	if (ch == NULL)
		return (NULL);
	ft_strlcpy(ch, &s1[i], len - i + 2);
	return (ch);
}

char	*ft_strtrim_end(char const *s1, char const *set)
{
	char	*ch;
	int		i;
	int		len;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s1) - 1;
	while (len > 0 && is_in_set(s1[len], set) == 1)
		len--;
	if (len < i)
		return (ft_strdup(""));
	ch = (char *)malloc(sizeof(char) * (len + 3));
	if (ch == NULL)
		return (NULL);
	while (i <= len)
	{
		ch[i] = s1[i];
		i++;
	}
	ch[len + 1] = '\n';
	ch[len + 2] = '\0';
	return (ch);
}
