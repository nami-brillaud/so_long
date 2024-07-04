/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:29:12 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/04 19:21:31 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
#include <mlx.h>

/* Structures */

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* KEYS */
# define W 13
# define UP 126
# define A 0
# define LEFT 123
# define S 1
# define DOWN 125
# define D 2
# define RIGHT 124

# define ESC 53

# define TRUE 1
# define FALSE 0
 

#endif