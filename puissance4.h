/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:50:11 by sid-bell          #+#    #+#             */
/*   Updated: 2018/12/23 17:40:20 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H
# include "libft/includes/libft.h"
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# define PLAYER1 1
# define CPU 2

typedef struct	s_game
{
	int		player;
	int		width;
	int		height;
	char	**board;
}				t_game;
void			ft_play(t_game *game, int x);
void			ft_display(t_game *game);
void			ft_bot(t_game *game);
int				ft_winner(t_game *game);
int				ft_scanf(void);
int				ft_gety(t_game *game, int x);
int				ft_avrows(t_game *game);
int				ft_isvalid(t_game *game, int move);
t_game			*ft_gamecopy(t_game *game);
int				ft_safeavrows(t_game *game);
int				ft_threat(t_game *game);
void			ft_setup(t_game *game);
int				ft_rand(t_game *game);
#endif
