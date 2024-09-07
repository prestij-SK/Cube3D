#include "../header/the_game.h"
#include "../header/parsing.h"

#include <unistd.h>  // For usleep
#include <sys/time.h>  // For gettimeofday

int	main(int argc, char **argv)
{
	if (argc != 2)
		err_message("Invalid number of arguments\n");
	the_game(argv[1]);
}
