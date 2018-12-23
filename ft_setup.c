/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:50:11 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/23 17:33:44 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	ft_setup(t_game *game)
{
	int index;

	index = 0;
	game->board = (char **)malloc(sizeof(char *) * game->height);
	while (index < game->height)
	{
		game->board[index] = malloc(game->height);
		ft_bzero(game->board[index++], game->width);
	}
}
