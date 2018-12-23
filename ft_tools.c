/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:50:11 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/23 17:33:07 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_gety(t_game *game, int x)
{
	int index;

	index = game->height;
	while (index-- > 0)
	{
		if (!game->board[index][x])
		{
			return (index);
		}
	}
	return (0);
}

int		ft_safeavrows(t_game *game)
{
	int x;
	int count;
	int y;

	count = 0;
	x = 0;
	while (x < game->width)
	{
		if (ft_isvalid(game, x))
		{
			y = ft_gety(game, x);
			game->board[y][x] = game->player;
			if (ft_threat(game) == -1)
			{
				count++;
			}
			game->board[y][x] = 0;
		}
		x++;
	}
	return (count);
}

int		ft_avrows(t_game *game)
{
	int x;
	int count;

	count = 0;
	x = 0;
	while (x < game->width)
	{
		if (ft_isvalid(game, x))
			count++;
		x++;
	}
	return (count);
}

int		ft_rand(t_game *game)
{
	int random;

	if (ft_safeavrows(game) < 1)
		random = 0;
	else
		random = rand() % (ft_safeavrows(game));
	return (random);
}

int		ft_isvalid(t_game *game, int move)
{
	if (move >= 0 && move < game->width)
	{
		if (!game->board[0][move])
			return (1);
	}
	return (0);
}
