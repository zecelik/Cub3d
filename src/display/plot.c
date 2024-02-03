/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasanca <sasanca@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:18:36 by sasanca           #+#    #+#             */
/*   Updated: 2024/02/03 15:18:37 by sasanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || y < 0 || x < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;
	int		color;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int	get_fromrgb(int rgb[3])
{
	if (!rgb)
		return (0);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	draw_sky_or_floor(double x, double start_y, double end_y, t_cub params)
{
	int	color;

	if (start_y == 0)
		color = get_fromrgb(params.c_color);
	else
		color = get_fromrgb(params.f_color);
	while (start_y != end_y)
	{
		my_mlx_pixel_put(&(params.img), x, start_y, color);
		if (start_y < end_y)
			start_y ++;
		else
			start_y--;
	}
}
