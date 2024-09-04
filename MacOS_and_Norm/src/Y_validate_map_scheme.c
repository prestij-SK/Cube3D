#include "../header/the_game.h"
#include "../header/parsing.h"

static	int	invalid_chars_consecutive(char **map, int i, int j)
{
    if (map[i][j] == 'D' || map[i][j] == 'N' || \
         map[i][j] == 'S' || map[i][j] == 'E' || \
         map[i][j] == 'W' ||  map[i][j] == '0')
    {
        if (i > 0 && map[i - 1][j] == ' ')
            return (1);
        if (j > 0 && map[i][j - 1] == ' ')
            return (1);
        if (map[i + 1][j] == ' ')
            return (1);
        if (map[i][j + 1] == ' ')
            return (1);
    }
    return (0);
}

void	validate_map_emptyness(t_parse *p_data)
{
    int	i;
    int	j;

    i = 0;
    while (p_data->map[i])
    {
        j = 0;
        while (p_data->map[i][j])
        {
            if (invalid_chars_consecutive(p_data->map, i, j))
            {
                //          write(2, "Error\nInvalid Map in line:\n", 27);//need to add putnbr and write_fd
                //            write(2, p_data->map[i], ft_strlen(p_data->map[i]));
                printf("Error\nInvalid Map in line: ");
                printf("%d\n", i + 1);
                printf("%s\n", p_data->map[i]);
                clean_exit(p_data, 1);
            }
            j++;
        }
        i++;
    }

}

void	validate_borders(t_parse *p_data)
{
    int	i;

    i = 0;
    while (p_data->map[i])
    {
        if (p_data->map[i][0] == '0')
        {
            ft_putstr_fd("Invalid Borders\n", STD_ERR);
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
            ft_putstr_fd(RED, STD_ERR);
            ft_putstr_fd("Error\n", STD_ERR);
            ft_putstr_fd(YELLOW, STD_ERR);
            ft_putstr_fd("Invalid path\n", STD_ERR);
            ft_putstr_fd(DEFAULT, STD_ERR);
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
                ft_putstr_fd(p_data->map[i], STD_ERR);
                ft_putstr_fd(DEFAULT, STD_ERR);
                clean_exit(p_data, 1);
            }
        }
    }
}
