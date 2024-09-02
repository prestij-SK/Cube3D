#include "../header/the_game.h"
#include "../header/parsing.h"

#include <unistd.h>  // For usleep
#include <sys/time.h>  // For gettimeofday

// typedef struct s_data {
//     void *mlx;
//     void *win;
//     void *textures[5];
//     int width, height;
//     int animating;
//     struct timeval start_time;
// } t_data;

// // Function to get the current time in milliseconds
// long get_current_time_ms() {
//     struct timeval tv;
//     gettimeofday(&tv, NULL);
//     return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
// }

// // Function to handle key press
// int key_press(int keycode, t_data *data) {
//     if (keycode == 65307)  // Escape key to exit
//         mlx_destroy_window(data->mlx, data->win);
//     else if (keycode == KEY_W) {  // Space key to start animation
//         data->animating = 1;
//         gettimeofday(&data->start_time, NULL);  // Record the start time
//     }
//     return (0);
// }

// // Function to render the animation
// int render_animation(t_data *data) {
//     if (!data->animating)
//         return (0);

//     long current_time = get_current_time_ms();
//     long elapsed_time = current_time - (data->start_time.tv_sec * 1000 + data->start_time.tv_usec / 1000);

//     if (elapsed_time < 50) {  // Animation duration of 2 seconds
//         int frame = (elapsed_time / 80) % 5;  // Switch frame every 400 ms
//         mlx_put_image_to_window(data->mlx, data->win, data->textures[frame], 100, 100);
//     } else {
//         data->animating = 0;  // Stop animation after 2 seconds
//     }
//     return (1);
// }

// int main() {
//     t_data data;
//     data.animating = 0;

//     // Initialize the MLX library and create a window
//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, 800, 600, "Animation Example");

//     // Load 5 textures (replace "frameX.xpm" with your actual texture paths)
//     data.textures[0] = mlx_xpm_file_to_image(data.mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_00.xpm", &data.width, &data.height);
//     data.textures[1] = mlx_xpm_file_to_image(data.mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_01.xpm", &data.width, &data.height);
//     data.textures[2] = mlx_xpm_file_to_image(data.mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_02.xpm", &data.width, &data.height);
//     data.textures[3] = mlx_xpm_file_to_image(data.mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_03.xpm", &data.width, &data.height);
//     data.textures[4] = mlx_xpm_file_to_image(data.mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_04.xpm", &data.width, &data.height);

//     // Set up the key press event handler using mlx_hook
//     mlx_hook(data.win, 2, 1L << 0, key_press, &data);

//     // Main loop
//     mlx_loop_hook(data.mlx, render_animation, &data);
//     mlx_loop(data.mlx);

//     // Free the textures and close the MLX window (never reached in this example)
//     for (int i = 0; i < 5; i++) {
//         mlx_destroy_image(data.mlx, data.textures[i]);
//     }
//     mlx_destroy_window(data.mlx, data.win);

//     return 0;
// }

// int main() {
//     void *mlx;
//     void *win;
//     void *textures[5];
//     int width, height;
//     int frame = 0;

//     // Initialize the MLX library and create a window
//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 800, 600, "Animation Example");

//     // Load 5 textures (replace "frameX.xpm" with your actual texture paths)
//     textures[0] = mlx_xpm_file_to_image(mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_00.xpm", &width, &height);
//     textures[1] = mlx_xpm_file_to_image(mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_01.xpm", &width, &height);
//     textures[2] = mlx_xpm_file_to_image(mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_02.xpm", &width, &height);
//     textures[3] = mlx_xpm_file_to_image(mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_03.xpm", &width, &height);
//     textures[4] = mlx_xpm_file_to_image(mlx, "/home/steve/Desktop/the_game/Linux/texture/gun_04.xpm", &width, &height);

//     // Main loop to animate the textures
//     while (1) {
//         // Display the current frame
//         mlx_put_image_to_window(mlx, win, textures[frame], 100, 100);

//         // Advance to the next frame
//         frame = (frame + 1) % 5;

//         // Wait 16 milliseconds for ~60 FPS
//         usleep(16000);
//     }

//     // Free the textures and close the MLX window (never reached in this example)
//     for (int i = 0; i < 5; i++) {
//         mlx_destroy_image(mlx, textures[i]);
//     }
//     mlx_destroy_window(mlx, win);

//     return 0;
// }

int	main(int argc, char **argv)
{
	if (argc != 2)
		err_message("Invalid number of arguments\n");
	the_game(argv[1]);
}
