/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:50:11 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/23 18:47:34 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	ft_print(t_game *game, int x, int y)
{
	ft_putchar(' ');
	if (game->board[y][x])
		ft_putchar(game->board[y][x] == PLAYER1 ? 'X' : 'O');
	else
		ft_putchar(' ');
	ft_putchar(' ');
	ft_putchar('|');
}

void	ft_printnums(t_game *game)
{
	int index;

	index = 0;
	ft_putchar('|');
	while (index < game->width)
	{
		if (index < 9)
			ft_putchar(' ');
		ft_putnbr(index + 1);
		ft_putchar(' ');
		ft_putchar('|');
		index++;
	}
}

void	ft_display(t_game *game)
{
	int y;
	int x;

	x = 0;
	y = 0;
	ft_putchar('+');
	ft_putstr(ft_strrepeat("-", game->width * 4 - 1));
	ft_putstr("+\n");
	while (y < game->height)
	{
		x = 0;
		ft_putchar('|');
		while (x < game->width)
		{
			ft_print(game, x, y);
			x++;
		}
		y++;
		ft_putstr("\n+");
		ft_putstr(ft_strrepeat("-", game->width * 4 - 1));
		ft_putstr("+\n");
	}
	ft_printnums(game);
	ft_putstr("\n\n");
}
