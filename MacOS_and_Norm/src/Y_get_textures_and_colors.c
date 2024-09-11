/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_get_textures_and_colors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:09:30 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 14:16:26 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

t_type	check_type(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (EMPTY);
	if (ft_strstr(str + i, "NO"))
		return (NO);
	if (ft_strstr(str + i, "SO"))
		return (SO);
	if (ft_strstr(str + i, "WE"))
		return (WE);
	if (ft_strstr(str + i, "EA"))
		return (EA);
	if (ft_strstr(str + i, "F"))
		return (F);
	if (ft_strstr(str + i, "C"))
		return (C);
	return (NOT_VALID);
}

int	save_data(t_parse *p_data, char *str, t_type type)
{
	int	status;

	status = 1;
	if (type == NO)
		status = save_north(p_data, str);
	else if (type == WE)
		status = save_west(p_data, str);
	else if (type == EA)
		status = save_east(p_data, str);
	else if (type == SO)
		status = save_south(p_data, str);
	else if (type == F)
		status = save_floor_color(p_data, str);
	else if (type == C)
		status = save_ceill_color(p_data, str);
	return (status);
}

static int	not_valid_line(char *line)
{
	print_err_message("not valid line:\n");
	ft_putendl_fd(line, STD_ERR);
	return (-5);
}

int	get_textures_and_colors(t_parse *p_data)
{
	int		i;
	int		status;
	int		not_empty_lines;
	t_type	type;

	i = -1;
	not_empty_lines = 0;
	while (p_data->file[++i] && not_empty_lines < 6)
	{
		type = check_type(p_data->file[i]);
		if (type == NOT_VALID)
			return (not_valid_line(p_data->file[i]));
		else if (type == EMPTY)
			continue ;
		status = save_data(p_data, p_data->file[i], type);
		if (status < 0)
		{
			resolve_error(p_data->file[i], type, status);
			return (status);
		}
		if (!is_empty(p_data->file[i]))
			not_empty_lines++;
	}
	return (1);
}
