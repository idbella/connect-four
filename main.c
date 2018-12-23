/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:50:11 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/23 18:59:22 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_scanf(void)
{
	char *str;

	get_next_line(0, &str);
	return (ft_atoi(str));
}

int		main(int argc, char **argv)
{
	t_game game;

	srand(time(NULL));
	if (argc >= 3)
	{
		game.width = ft_atoi(argv[1]);
		game.height = ft_atoi(argv[2]);
		game.player = rand() % 2 ? PLAYER1 : CPU;
		if (game.width >= 7 && game.height >= 6)
		{
			ft_setup(&game);
			if (game.player == PLAYER1)
				ft_display(&game);
			ft_play(&game, 0);
		}
		else
			ft_putendl("size must be greather than 6 lines and 7 comlumns");
	}
	else
		ft_putendl("usage : ./puissance4 width height");
	return (0);
}
