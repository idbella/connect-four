/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:50:11 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/23 15:52:10 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_game	*ft_gamecopy(t_game *game)
{
	int		x;
	int		y;
	t_game	*test;

	y = 0;
	test = (t_game *)malloc(sizeof(t_game));
	test->height = game->height;
	test->width = game->width;
	test->player = game->player;
	test->board = (char **)malloc(sizeof(char *) * test->height);
	while (y < test->height)
	{
		test->board[y] = (char *)malloc(test->width);
		x = 0;
		while (x < test->width)
		{
			test->board[y][x] = game->board[y][x];
			x++;
		}
		y++;
	}
	return (test);
}
