/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:50:11 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/23 17:38:47 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	ft_print(t_game *game)
{
	if (ft_winner(game) == 1)
	{
		if (game->player == PLAYER1)
			ft_putendl("You Win !");
		else
			ft_putendl("CPU wins !");
		return (1);
	}
	return (0);
}

void		ft_play(t_game *game, int x)
{
	while (game->player == PLAYER1)
	{
		ft_putstr("enter pos for player 1\n");
		x = ft_scanf() - 1;
		if (ft_isvalid(game, x))
		{
			game->board[ft_gety(game, x)][x] = game->player;
			break ;
		}
		ft_putendl("invalid row");
	}
	if (game->player == CPU)
		ft_bot(game);
	ft_display(game);
	if (ft_print(game))
		return ;
	if (game->player == PLAYER1)
		game->player = CPU;
	else
		game->player = PLAYER1;
	if (ft_avrows(game))
		ft_play(game, 0);
	else
		ft_putendl("Game Over ! No onw wins !");
}
