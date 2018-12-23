/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:50:11 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/23 17:22:53 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_gethstat(t_game *game, int x, int y, int *state)
{
	char *board;

	board = game->board[y];
	if (x + 4 <= game->width && board[x] == game->player)
	{
		if (board[x + 1] == game->player && board[x + 2] == game->player)
		{
			if (board[x + 3] == game->player)
				return (1);
			*state = 3;
		}
	}
	return (0);
}

int		ft_getvstat(t_game *game, int x, int y, int *state)
{
	if (y + 4 <= game->height && game->board[y][x] == game->player)
	{
		if (game->board[y + 1][x] == game->player &&
		game->board[y + 2][x] == game->player)
		{
			if (game->board[y + 3][x] == game->player)
				return (1);
			*state = 3;
		}
	}
	return (0);
}

int		ft_getd1stat(t_game *game, int x, int y, int *state)
{
	if (y + 4 <= game->height && x + 4 <= game->width
	&& game->board[y][x] == game->player)
	{
		if (game->board[y + 1][x + 1] == game->player
		&& game->board[y + 2][x + 2] == game->player)
		{
			if (game->board[y + 3][x + 3] == game->player)
				return (1);
			*state = 3;
		}
	}
	return (0);
}

int		ft_getd2stat(t_game *game, int x, int y, int *state)
{
	if (y + 4 <= game->height && x - 3 >= 0
	&& game->board[y][x] == game->player)
	{
		if (game->board[y + 1][x - 1] == game->player
		&& game->board[y + 2][x - 2] == game->player)
		{
			if (game->board[y + 3][x - 3] == game->player)
				return (1);
			*state = 3;
		}
	}
	return (0);
}

int		ft_winner(t_game *game)
{
	int x;
	int y;
	int stat;

	x = 0;
	y = 0;
	stat = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (ft_gethstat(game, x, y, &stat))
				return (1);
			if (ft_getvstat(game, x, y, &stat))
				return (1);
			if (ft_getd1stat(game, x, y, &stat))
				return (1);
			if (ft_getd2stat(game, x, y, &stat))
				return (1);
			x++;
		}
		y++;
	}
	return (stat);
}
