#ifndef THE_GAME_H
# define THE_GAME_H

# include "../mlx_linux/mlx.h"

# include "utils.h"
# include "image.h"
# include "minimap.h"
# include "player.h"
# include "first_person_view.h"
# include "draw_shape.h"
# include "for_math.h"
# include "input.h"

# define GAME_NAME "THE GAME"
# define UPDATE_60FPS_INTERVAL 16 // 60 fps in miliseconds. 1000 / 60

// Ray casting options
# define RADIAN_STEP 0.004363323 //  (1 radian / 4)
# define SECTOR_ANGLE -30 // in case of 240 rays and 0.004363323 radian step, the sector will start at -30 and increase to 30, which will make 60 degree sector
# define RAY_COUNT 240 // 240 rays in 60 degree sector

typedef struct MainGameData
{
	void		*mlx;
	void		*mlx_window;
	t_Minimap	minimap;
	t_Player	player;
	t_FPV		view;
	t_Image		north_wall;
	t_Image		south_wall;
	t_Image		west_wall;
	t_Image		east_wall;
	t_Image		*tex_p; // changable texture pointer 
	t_Input		input;
	size_t		last_update_time;
}	t_GameData;

// Start
void			the_game(char *path);
void			game_nullify_pointers(t_GameData *data);
t_StatusCode	game_mlx_init(t_GameData *data);
t_StatusCode	game_data_init(t_GameData *data, char **map, t_Point2D block_count);
void			game_data_delete(t_GameData *data);

void	input_update_render(t_GameData *data);
int		close_window(t_GameData *data);

/*
	update functions
*/
void	update_A(t_Player *player);
void	update_D(t_Player *player);
void	update_W(t_Player *player);
void	update_S(t_Player *player);
void	update_Arrow_Left(t_Player *player);
void	update_Arrow_Right(t_Player *player);
void	update_check(t_GameData *data);

/*
	render functions
*/
void	render_image(t_GameData *data, t_Image *image);
void	render(t_GameData *data);

/*
	ray_cast functions
*/
void	ray_casting(t_GameData *data);
void	horizontal_checking(t_GameData *data, t_RCdata *ray_data, double angle);
void	vertical_checking(t_GameData *data, t_RCdata *ray_data, double angle);
void	adjust_ray_range(t_GameData *data, t_RCutil *util); // Wasn't needed

#endif