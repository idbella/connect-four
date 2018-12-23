/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:50:11 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/23 17:54:09 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_issafe(t_game *game, int x)
{
	t_game	*test;
	int		y;

	test = ft_gamecopy(game);
	y = ft_gety(test, x);
	test->board[y][x] = test->player;
	if (ft_threat(test))
		return (0);
	return (1);
}

void	ft_playrandom(t_game *game, int x, int y, int index)
{
	int random;

	random = ft_rand(game);
	while (x < game->width)
	{
		if (ft_isvalid(game, x))
		{
			if (index == random)
			{
				y = ft_gety(game, x);
				game->board[y][x] = game->player;
				if (ft_threat(game) >= 0 &&
				ft_avrows(game) > ft_safeavrows(game))
				{
					game->board[y][x] = 0;
					random = rand() % (ft_avrows(game));
					x = 0;
					continue ;
				}
				return ;
			}
			index++;
		}
		x++;
	}
}

int		ft_threat(t_game *game)
{
	int		x;
	int		y;
	t_game	*test;

	test = ft_gamecopy(game);
	x = 0;
	test->player = PLAYER1;
	while (x < game->width)
	{
		if (ft_isvalid(game, x))
		{
			y = ft_gety(test, x);
			if (!test->board[y][x])
			{
				test->board[y][x] = test->player;
				if (ft_winner(test) == 1)
				{
					return (x);
				}
				test->board[y][x] = 0;
			}
		}
		x++;
	}
	return (-1);
}

int		ft_move(t_game *game, int *best_move, int x)
{
	int		status;
	int		y;

	*best_move = -1;
	while (x < game->width)
	{
		if (ft_isvalid(game, x))
		{
			y = ft_gety(game, x);
			if (!game->board[y][x])
			{
				game->board[y][x] = game->player;
				if ((status = ft_winner(game)) == 1)
					return (1);
				else if (status == 3)
					*best_move = x;
				game->board[y][x] = 0;
			}
		}
		x++;
	}
	return (0);
}

void	ft_bot(t_game *game)
{
	int		x;
	int		y;
	int		best_move;

	if (ft_move(game, &best_move, 0))
		return ;
	if ((x = ft_threat(game)) >= 0)
	{
		y = ft_gety(game, x);
		game->board[y][x] = game->player;
		return ;
	}
	if (best_move > 0)
	{
		if (ft_issafe(game, best_move))
			game->board[ft_gety(game, best_move)][best_move] = game->player;
		else
			ft_playrandom(game, 0, 0, 0);
	}
	else
		ft_playrandom(game, 0, 0, 0);
}
