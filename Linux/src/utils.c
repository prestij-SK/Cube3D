#include "../header/utils.h"

void	error_exit(t_StatusCode status, char *str)
{
	if (status == SUCCESS_EXIT)
	{
		printf("Called 'error_exit' when status is Success!\n");
		exit(EXIT_FAILURE);
	}
	printf("Error !\n");
	if (status == UNDEFINED_ERROR)
		printf("Undefined");
	else if (status == NULL_POINTER_ERROR)
		printf("Null Pointer");
	else if (status == MEMORY_ALLOCATION_ERROR)
		printf("Memory Allocation");
	else if (status == MLX_ERROR)
		printf("MLX Init");
	else if (status == MLX_WINDOW_ERROR)
		printf("MLX Window");
	else if (status == IMAGE_ERROR)
		printf("MLX Image");
	else if (status == PLAYER_LOCATION_ERROR)
		printf("Player Location");
	if (str)
		printf("\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	success_exit(t_StatusCode status, char *str)
{
	if (status != SUCCESS_EXIT)
	{
		printf("Called 'success_exit' when status is Error!\n");
		exit(EXIT_FAILURE);
	}
	printf("Success !\n");
	if (str)
		printf("%s\n", str);
	exit(EXIT_SUCCESS);
}

size_t	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
}

void	swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}