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

/*typedef struct  s_data {
    void *img;
    char *addr;
	void *win;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
	void *mlx;
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


void	rectangle(int xstop, int ystop, int xstart, int ystart, t_data img)
{
	while (ystart < ystop)
	{
		xstart = 0;
		while (xstart < xstop)
		{
			my_mlx_pixel_put(&img, xstart, ystart, 0x00FF0000);
			xstart++;
		}
		ystart++;

	}
}
void	rectanglel(int xstop, int ystop, int xstart, int ystart, t_data img)
{
	while (xstart < xstop)
	{
		ystart = 0;
		while (ystart < ystop)
		{
			my_mlx_pixel_put(&img, xstart, ystart, 0x00FF0000);
			ystart++;
		}
		xstart++;

	}
}

void	triangle(int xstop, int ystop, int xstart, int ystart, t_data img)
{
	while (xstart < xstop)
	{
		ystart = 0;
		while (ystart < ystop)
		{
			my_mlx_pixel_put(&img, xstart, ystart, 0x00FF0000);
			ystart++;
		}
		ystop = ystop - 1;
		xstart++;

	}
}

int	ftclose(int	keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int    main(void)
{  
	t_data img;
	t_data data;
	int xstart;
	int ystart;
	int xstop;
	int ystop;


	xstart = 0;
	ystart = 0;
	xstop = 35;
	ystop = 500;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "hello");
    img.img = mlx_new_image(data.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	rectangle(xstop, ystop, xstart, ystart, img);
	xstart = xstop;
	xstop = xstart + 220;
	ystart = (ystop / 2) - 35;
	ystop = ystart + 35;
	rectangle(xstop, ystop, xstart, ystart, img);
	xstart = xstop;
	xstop = xstart + 35;
	ystart = 0;
	ystop = 500;
	rectanglel(xstop, ystop, xstart, ystart, img);
	triangle(500, 250, 500, 150, img);
	mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
	mlx_hook(data.win, 2, 1L<<0, ftclose, &data);
	mlx_loop(data.mlx);
}*/

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void 	*img;
}				t_vars;

int	ftclose(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int x;
	int y;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "Hello world!");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "caracter.xpm", &x, &y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 50, 50);
	mlx_hook(vars.win, 8, 1L<<5, ftclose, &vars);
	mlx_loop(vars.mlx);
}
