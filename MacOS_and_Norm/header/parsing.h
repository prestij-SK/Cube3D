/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <skedikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:54:21 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 13:43:41 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "fcntl.h"
# include "utils.h"

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define DEFAULT "\033[0m"
# define GREEN "\033[1;32m"

# define BUFFER_SIZE 1024
# define STD_ERR 2

typedef enum Type
{
	NOT_VALID,
	EMPTY,
	NO,
	SO,
	WE,
	EA,
	F,
	C
}				t_type;

typedef enum PStatus
{
	MALLOC = -1,
	DOUBLICATE = -2,
	INVALID_KEY = -3,
	TOO_MANY_VALUES = -4,
	DOUBLE_COMMAS = -5,
	INVALID_RANGE = -6,
	COMMA_EDGE = -7,
	INVALID_COLOR_VALUES = -8,
	TOO_FEW_VALUES = -9,
}				t_pstatus;

typedef struct ElemnetnsCounter
{
	int			north;
	int			west;
	int			south;
	int			east;
	int			door;

}				t_elements;

typedef struct ParsingData
{
	char		player_view;
	char		**file;
	char		**map;
	char		**map_cpy;
	t_point2d	block_count;
	t_elements	elements;
	char		*north;
	char		*west;
	char		*east;
	char		*south;
	int			ceiling_c;
	int			floor_c;
}				t_parse;

typedef struct index
{
	int			i;
	int			j;
	int			end;
}				t_index;

typedef struct RGB
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct FileData
{
	char		*temp;
	char		*trim_temp;
	char		*line;
	char		**map;

}				t_file;

// UTILS
char			*get_next_line(int fd);
int				ft_strlen(char *s);
int				ft_strchr(char *s, int c);
char			*ft_strjoin_and_free(char *left_str, char *buff);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strtrim_end(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*err_message(char *message);
char			*ft_strstr(char *str, char *to_find);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strstr(char *str, char *to_find);
int				ft_atoi_check(const char *str);
int				is_empty(char *str);
int				arr_len(char **arr);
int				ft_isdigit(int c);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			**ft_arrdup(char **env);
void			print_err_message(char *str);
void			free_ptr(void *ptr);

t_parse			parsing(char *path);
char			**read_file(int fd);
int				open_file(char *path);
void			tabs_to_spaces(char **map);
int				init_map(t_parse *p_data);
void			make_map_rectangle(t_parse *p_data);

// TEXTURES
int				get_textures_and_colors(t_parse *p_data);
int				save_north(t_parse *p_data, char *str);
int				save_west(t_parse *p_data, char *str);
int				save_east(t_parse *p_data, char *str);
int				save_south(t_parse *p_data, char *str);
void			resolve_error(char *line, t_type type, t_pstatus status);
int				save_floor_color(t_parse *p_data, char *str);
int				save_ceill_color(t_parse *p_data, char *str);
int				resolve_type(int len);

// VALIDATION
int				is_valid_map_name(char *name);
int				check_textures_and_colors(t_parse *p_data);
void			validate_map_chars(t_parse *p_data);
void			validate_data(t_parse *p_data);
void			validate_doors(t_parse *p_data);
void			validate_invalid_path(t_parse *p_data, t_point2d size,
					t_point2d cur, char to_fill);
void			validate_borders(t_parse *p_data);

// MEMORY
void			*free_arr(char **str);
t_parse			init_pdata(void);
void			*clean_pdata(t_parse *p_data);
void			*clean_pdata_except_map(t_parse *p_data);
void			*clean_exit(t_parse *p_data, int status);

// DEBUG
void			print_pdata(t_parse *p_data);
void			print_map(char **map, int x, int y);
void			print_line_by_char(char *str);

#endif