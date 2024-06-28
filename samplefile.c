/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samplefile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:36:57 by nfujisak          #+#    #+#             */
/*   Updated: 2024/06/28 18:05:35 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mine_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, int xstart, int xend, int ystart, int yend, int color)
{
	
}

int main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 700, 680, "This is a window");
	img.img = mlx_new_image(mlx, 700, 680);
	img.addr= mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x = 0;
	int y = 0;
	while (x < 500)
	{	
		y = 0;
		while (y < 500)
		{
			mine_pixel_put(&img, x, y, 0x00006699);
			y++;
		}
		x++;
		
	}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

/* BLUE RECTANGLE */
// int main(void)
// {
// 	void	*mlx;
// 	void	*mlx_window;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_window = mlx_new_window(mlx, 700, 680, "This is a window");
// 	img.img = mlx_new_image(mlx, 700, 680);
// 	img.addr= mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	int x = 0;
// 	int y = 0;
// 	while (x < 500)
// 	{	
// 		y = 0;
// 		while (y < 500)
// 		{
// 			mine_pixel_put(&img, x, y, 0x00006699);
// 			y++;
// 		}
// 		x++;
		
// 	}
// 	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }