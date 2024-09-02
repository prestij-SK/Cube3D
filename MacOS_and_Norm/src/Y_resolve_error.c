/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_resolve_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:39:54 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/08/31 17:45:07 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"
#include "../header/parsing.h"

static void	write_type(t_type type)
{
	if (type == NO)
		write(2, "NO", 2);
	else if (type == WE)
		write(2, "WE", 2);
	else if (type == SO)
		write(2, "SO", 2);
	else if (type == EA)
		write(2, "EA", 2);
	else if (type == F)
		write(2, "F", 1);
	else if (type == C)
		write(2, "C", 1);
}

static void	write_key(char *line)
{
	int	i;
	int	end;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	end = i;
	while (line[end] && line[end] != ' ')
		end++;
	if (end <= i)
		return ;
	write(2, line + i, end - i + 1);
}

void	resolve_error(char *line, t_type type, t_pstatus status)
{
  	write(2, "Error\n", 6);
	if (status == MALLOC)
		write(2, "Malloc error\n", 13);
	else if (status == DOUBLICATE)
	{
		write_type(type);
		write(2, " already set\n", 13);
	}
	else if (status == INVALID_KEY)
	{
		write(2, "invalid key: ", 13);
		write_key(line);
		write(2, "\n", 1);
	}
	else if (status == TOO_MANY_VALUES)
	{
		write(2, "too many arguments for: ", 24);
		write_type(type);
		write(2, "\n", 1);
	}
	else if (status == DOUBLE_COMMAS)
		write(2, "invlid color separator: ',,'\n", 29);	
	else if (status == INVALID_RANGE)
		write(2, "clors should be in range of 0-255\n", 34);
	else if (status == COMMA_EDGE)
		write(2, "clors value should not start or end with ','\n", 45);
    else if (status == INVALID_COLOR_VALUES)
      	write(2, "colors value should only be numbers\n", 36);
}
