#include "../header/the_game.h"
#include "../header/parsing.h"

static	int	get_end(t_parse *p_data)
{
    int	i;

    i = 0;
    while (p_data->file[i])
        i++;
    i--;
    while (p_data->file[i] && ft_strcmp(p_data->file[i], " ") == 0)
        i--;
    return (i);
}

static int	fill_map(t_parse *p_data, t_Point2D block, t_index idx)
{
    p_data->map = (char **)malloc(sizeof(char *) * (block.y));
    if (!p_data->map)
        return (-1);
    idx.j = 0;
    idx.end = get_end(p_data);
    while (p_data->file[idx.i] && idx.i <= idx.end)//check overflow
    {
        p_data->map[idx.j] = ft_strdup(p_data->file[idx.i]);
        if (!p_data->map[idx.j])
            return (-1);
        idx.i++;
        idx.j++;
    }
    p_data->map[idx.j] = NULL;
    return (1);
}

int	init_map(t_parse *p_data)
{
    t_Point2D	block;
    t_index		idx;
    int			not_empty_lines;

    idx.i = 0;
    not_empty_lines = 0;
    while (p_data->file[idx.i] && not_empty_lines < 6)
    {
        if (!is_empty(p_data->file[idx.i]))
            not_empty_lines++;
        idx.i++;
    }
    while (p_data->file[idx.i] && is_empty(p_data->file[idx.i]))
        idx.i++;
    if (p_data->file[idx.i] == NULL)
        return (0);
    block.y = 0;
    while (p_data->file[idx.i + block.y])
        block.y++;
    return (fill_map(p_data, block, idx));
}
