/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasanca <sasanca@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:18:09 by sasanca           #+#    #+#             */
/*   Updated: 2024/02/03 15:18:10 by sasanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_free_cub(t_cub *cub)
{
	ft_free_split(cub->map);
	free(cub->no_path);
	free(cub->so_path);
	free(cub->we_path);
	free(cub->ea_path);
	free(cub->params);
}

void	ft_free_all(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_destroy_image(cub->mlx, cub->tex[0].img.img);
	mlx_destroy_image(cub->mlx, cub->tex[1].img.img);
	mlx_destroy_image(cub->mlx, cub->tex[2].img.img);
	mlx_destroy_image(cub->mlx, cub->tex[3].img.img);
	mlx_destroy_window(cub->mlx, cub->win);
	ft_free_cub(cub);
}
