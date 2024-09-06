#include "../header/the_game.h"
#include "../header/parsing.h"

void	validate_borders(t_parse *p_data)
{
    int	i;

    i = 0;
    while (p_data->map[i])
    {
        if (p_data->map[i][0] == '0' || p_data->map[i][0] == 'D')
        {
            print_err_message("Invalid Borders\n");
            clean_exit(p_data, 1);
        }
        i++;
    }
}

void	validate_invalid_path(t_parse *p_data, t_Point2D size, t_Point2D cur, char to_fill)
{
    if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
        return ;
    if (ft_strchr("ENSWD", p_data->map_cpy[cur.y][cur.x]))
        p_data->map_cpy[cur.y][cur.x] = '0';
    if (p_data->map_cpy[cur.y][cur.x] != to_fill)
    {
        if (p_data->map_cpy[cur.y][cur.x] == ' ')
        {
            print_err_message("Invalid path\n");
            clean_exit(p_data, 1);
        }
        return ;
    }
    p_data->map_cpy[cur.y][cur.x] = 'F';
    validate_invalid_path(p_data, size, (t_Point2D){cur.x - 1, cur.y}, to_fill);
    validate_invalid_path(p_data, size, (t_Point2D){cur.x + 1, cur.y}, to_fill);
    validate_invalid_path(p_data, size, (t_Point2D){cur.x, cur.y - 1}, to_fill);
    validate_invalid_path(p_data, size, (t_Point2D){cur.x, cur.y + 1}, to_fill);
}

void	validate_doors(t_parse *p_data)
{
    int	i;
    int	j;

    i = -1;
    while (p_data->map[++i])
    {
        j = -1;
        while (p_data->map[i][++j])
        {
            if (p_data->map[i][j] == 'D'
            && !(p_data->map[i - 1][j] && p_data->map[i - 1][j] == '1'
            && p_data->map[i + 1][j] && p_data->map[i + 1][j] == '1')
            && !(p_data->map[i][j - 1] && p_data->map[i][j - 1] == '1'
            && p_data->map[i][j + 1] && p_data->map[i][j + 1] == '1'))
            {
                ft_putstr_fd(RED, STD_ERR);
                ft_putstr_fd("Error\n", STD_ERR);
                ft_putstr_fd(YELLOW, STD_ERR);
                ft_putstr_fd("Invalid Map, doors should be surounded by walls in line: ", STD_ERR);
                ft_putnbr_fd(i + 1, STD_ERR);
                ft_putendl_fd(p_data->map[i], STD_ERR);
                ft_putstr_fd(DEFAULT, STD_ERR);
                clean_exit(p_data, 1);
            }
        }
    }
}
