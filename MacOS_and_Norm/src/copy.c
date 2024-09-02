#include "../header/the_game.h"

#include <mlx.h>
#include <stdbool.h>
#include <sys/time.h>

#define MAX_KEYS 256
#define EVENT_KEYDOWN 2
#define EVENT_KEYUP 3
#define MOVE_INTERVAL 16667  // in microseconds, for 60 fps

typedef struct s_data {
    void *mlx;
    void *mlx_window;
    bool key_states[MAX_KEYS];
    int x;
    int y;
    struct timeval last_move_time;
} t_data;

int input_key_press(int keycode, t_data *data)
{
    if (keycode < 0 || keycode >= MAX_KEYS)
        return (0);
    data->key_states[keycode] = true;
    return (0);
}

int input_key_release(int keycode, t_data *data)
{
    if (keycode < 0 || keycode >= MAX_KEYS)
        return (0);
    data->key_states[keycode] = false;
    return (0);
}

int loop_hook(t_data *data)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    long elapsed_time = (current_time.tv_sec - data->last_move_time.tv_sec) * 1000000
                        + (current_time.tv_usec - data->last_move_time.tv_usec);

    if (elapsed_time >= MOVE_INTERVAL)
    {
        for (int keycode = 0; keycode < MAX_KEYS; ++keycode)
        {
            if (data->key_states[keycode])
            {
                if (keycode == 'W')
                    data->y -= 1;
                else if (keycode == 'S')
                    data->y += 1;
                else if (keycode == 'A')
                    data->x -= 1;
                else if (keycode == 'D')
                    data->x += 1;
            }
        }
        gettimeofday(&data->last_move_time, NULL);  // Update the last move time
    }

    // Optionally, update your display here with the new coordinates
    // For example, you can clear and redraw your object at (data->x, data->y)

    return (0);
}

int main()
{
    t_data data;
    int width = 800;
    int height = 600;

    // Initialize your MLX window and other data structures
    data.mlx = mlx_init();
    data.mlx_window = mlx_new_window(data.mlx, width, height, "Title");

    // Initialize key states
    for (int i = 0; i < MAX_KEYS; ++i)
        data.key_states[i] = false;

    // Initialize coordinates and last move time
    data.x = width / 2;
    data.y = height / 2;
    gettimeofday(&data.last_move_time, NULL);

    // Set the key press and release event handlers
    mlx_hook(data.mlx_window, EVENT_KEYDOWN, 1L<<0, input_key_press, &data);
    mlx_hook(data.mlx_window, EVENT_KEYUP, 1L<<1, input_key_release, &data);

    // Set the loop hook
    mlx_loop_hook(data.mlx, loop_hook, &data);

    // Start the MLX loop
    mlx_loop(data.mlx);
    return (0);
}