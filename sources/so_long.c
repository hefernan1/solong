/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:34:57 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/14 16:08:35 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"

typedef struct  s_data {
    void *img;
    char *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int    main(void)
{  
	t_data img;
    void *mlx;
	void *mlx_win;
	int x;
	int y;

	x = 1000;
	y = 500;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x > 250 && y < 1000)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x--;
		y++;
		if (x % 2)
		{
			y++;
			x = x + 20;
			my_mlx_pixel_put(&img, x, y, 0x000000FF);
		}
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
