#ifndef THE_GAME_H
# define THE_GAME_H

# ifdef __linux__
#  define UNAME		"Linux"
# include "../mlx_linux/mlx.h"
# else
#  define UNAME		"Darwin"
# include "../mlx_mac/mlx.h"
# endif

# include "utils.h"
# include "image.h"
# include "minimap.h"
# include "player.h"
# include "first_person_view.h"
# include "draw_shape.h"
# include "for_math.h"
# include "input.h"
# include "door.h"
# include "parsing.h"

# include <unistd.h> // DELETE

// Game Options
# define GAME_NAME "THE GAME"
# define UPDATE_60FPS_INTERVAL 16 // 60 fps in miliseconds. 1000 / 60
# define COLLISION_GAP 20
# define DOOR_ACTIVATION_GAP 60
# define GUN_TEXTURES_COUNT 5
# define GUN_SWITCH_FRAME_TIME 80

// Ray casting options
# define RADIAN_STEP 0.0021816616 //  (1 radian / 8) will be used to increment sector degree which starts from -30
# define SECTOR_ANGLE -30 // the sector will start at -30 degree and increase to 30, which will make 60 degree sector
# define RAY_COUNT 480 // 240 rays in 60 degree sector

typedef struct maingamedata
{
	void		*mlx;
	void		*mlx_window;
	t_minimap	minimap;
	t_player	player;
	t_fpv		view;
	t_image		north_wall;
	t_image		south_wall;
	t_image		west_wall;
	t_image		east_wall;
	t_image		door_tex;
	t_image		easter_tex;
	t_image		gun[GUN_TEXTURES_COUNT];
	int			anim_start;
	size_t		anim_start_time;
	t_image		*tex_p; // changable texture pointer
	t_input		input;
	size_t		last_update_time;
	int			easter_found;
}	t_gamedata;

// Main
void			the_game(char *path, t_statuscode status);
void			game_nullify_pointers(t_gamedata *data);
t_statuscode	game_mlx_init(t_gamedata *data);
t_statuscode	game_data_init(t_gamedata *data, char **map, t_point2d block_count);
void			game_data_delete(t_gamedata *data);
void			input_update_render(t_gamedata *data); // main logic
int				close_game(t_gamedata *data);

/*
	update functions
*/
void	update_A(t_player *player);
void	update_D(t_player *player);
void	update_W(t_player *player);
void	update_S(t_player *player);
void	update_M(t_minimap *minimap, short val);
void	update_Arrow_Left(t_player *player, double rotate_speed);
void	update_Arrow_Right(t_player *player, double rotate_speed);
void	update_mouse_move(t_gamedata *data, double rotate_speed);
void	update_check(t_gamedata *data);
int		is_in_minimap_range(t_minimap *minimap, int y, int x);
void	set_xy_offset(t_updateutil *util, double change_x, double change_y, int gap);

/*
	render functions
*/
void	render_image_pos(t_gamedata *data, t_image *image, int x, int y);
void	render_image(t_gamedata *data, t_image *image);
void	render(t_gamedata *data);

/*
	ray_cast functions
*/
void	ray_casting(t_gamedata *data);
void	horizontal_checking(t_gamedata *data, t_rcdata *ray_data, double angle);
void	vertical_checking(t_gamedata *data, t_rcdata *ray_data, double angle);
void	set_shortest_ray_dis(t_rcdata *ray_data);
void	draw_ray_line(t_gamedata *data, t_rcdata *ray_data);

/*
	data_from_parsed.c
*/
t_statuscode	set_all_parsed_data(t_gamedata *data, t_parse *parse);

#endif