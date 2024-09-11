/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_resolve_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:39:54 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 14:10:26 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

void	print_err_message(char *str)
{
	ft_putstr_fd(RED, STD_ERR);
	ft_putstr_fd("Error\n", STD_ERR);
	ft_putstr_fd(YELLOW, STD_ERR);
	ft_putstr_fd(str, STD_ERR);
	ft_putstr_fd(DEFAULT, STD_ERR);
}

static void	write_type(t_type type)
{
	if (type == NO)
		ft_putstr_fd("NO", STD_ERR);
	else if (type == WE)
		ft_putstr_fd("WE", STD_ERR);
	else if (type == SO)
		ft_putstr_fd("SO", STD_ERR);
	else if (type == EA)
		ft_putstr_fd("EA", STD_ERR);
	else if (type == F)
		ft_putstr_fd("F", STD_ERR);
	else if (type == C)
		ft_putstr_fd("C", STD_ERR);
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
	write(STD_ERR, line + i, end - i + 1);
	ft_putstr_fd("\n", STD_ERR);
}

static void	resolve_error2(int status)
{
	if (status == DOUBLE_COMMAS)
		ft_putstr_fd("invlid color separator: ',,'\n", STD_ERR);
	else if (status == INVALID_RANGE)
		ft_putstr_fd("clors should be in range of 0-255\n", STD_ERR);
	else if (status == COMMA_EDGE)
		ft_putstr_fd("clors value should not start or end with ','\n", STD_ERR);
	else if (status == INVALID_COLOR_VALUES)
		ft_putstr_fd("colors value should only be numbers\n", STD_ERR);
	ft_putstr_fd(DEFAULT, STD_ERR);
}

void	resolve_error(char *line, t_type type, t_pstatus status)
{
	ft_putstr_fd(RED, STD_ERR);
	ft_putstr_fd("Error\n", STD_ERR);
	ft_putstr_fd(YELLOW, STD_ERR);
	if (status == MALLOC)
		ft_putstr_fd("Malloc error\n", STD_ERR);
	else if (status == DOUBLICATE)
	{
		write_type(type);
		ft_putstr_fd(" already set\n", STD_ERR);
	}
	else if (status == INVALID_KEY)
	{
		ft_putstr_fd("invalid key: ", STD_ERR);
		write_key(line);
	}
	else if (status == TOO_MANY_VALUES || status == TOO_FEW_VALUES)
	{
		if (status == TOO_MANY_VALUES)
			ft_putstr_fd("too many arguments for: ", STD_ERR);
		else
			ft_putstr_fd("too few arguments for: ", STD_ERR);
		write_type(type);
		ft_putstr_fd("\n", STD_ERR);
	}
	resolve_error2(status);
}
