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
                printf("Error\nInvalid Map, doors should be surounded by walls in line: ");
                printf("%d\n", i + 1);
                printf("%s\n", p_data->map[i]);
                clean_exit(p_data, 1);
            }
        }
    }
}
