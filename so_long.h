/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:29:12 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/12 19:21:58 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h> //for read
# include <errno.h> //for file handling errors

/* Structures */

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		square_size;
	int		animation_step;
}	t_data;

typedef struct s_map
{
	int		rows;
	int		columns;
	int		rcdiff;
	
}	t_map;

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