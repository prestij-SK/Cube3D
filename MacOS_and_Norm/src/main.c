/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:19:40 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:19:43 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"
#include "../header/parsing.h"

#include <unistd.h>  // For usleep
#include <sys/time.h>  // For gettimeofday

int	main(int argc, char **argv)
{
	t_statuscode	status;

	if (argc != 2)
		err_message("Invalid number of arguments\n");
	the_game(argv[1], status);
}
