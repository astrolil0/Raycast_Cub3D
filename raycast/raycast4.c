/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zumgenc <zumgenc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:04:25 by zumgenc           #+#    #+#             */
/*   Updated: 2024/05/15 12:10:47 by zumgenc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../maps/map.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

static void	ft_mlx2(t_game *g, int c)
{
	g->no->addr = (int *)mlx_get_data_addr(g->no->image, &c, &c, &c);
	g->so->addr = (int *)mlx_get_data_addr(g->so->image, &c, &c, &c);
	g->we->addr = (int *)mlx_get_data_addr(g->we->image, &c, &c, &c);
	g->ea->addr = (int *)mlx_get_data_addr(g->ea->image, &c, &c, &c);
	if (!g->no->addr || !g->so->addr || !g->we->addr || !g->ea->addr)
		return ((void)(ft_err("file cannot read", g)));
}

void	ft_mlx(t_game *g, int a, int b)
{
	g->image = malloc(sizeof(t_image));
	g->no = malloc(sizeof(t_image));
	g->so = malloc(sizeof(t_image));
	g->we = malloc(sizeof(t_image));
	g->ea = malloc(sizeof(t_image));
	if (!g->image || !g->no || !g->so || !g->we || !g->ea)
		return ((void)(ft_err("Direction malloc error", g)));
	g->image->image = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	if (!g->image->image)
		return ((void)(ft_err("image malloc error", g)));
	g->image->addr = (int *)mlx_get_data_addr(g->image->image, &a, &a, &a);
	if (!g->image->addr)
		return ((void)(ft_err("image addr malloc error", g)));
	g->no->image = mlx_xpm_file_to_image(g->mlx, g->map->notexturepath, &b, &b);
	g->so->image = mlx_xpm_file_to_image(g->mlx, g->map->sotexturepath, &b, &b);
	g->we->image = mlx_xpm_file_to_image(g->mlx, g->map->wetexturepath, &b, &b);
	g->ea->image = mlx_xpm_file_to_image(g->mlx, g->map->eatexturepath, &b, &b);
	if (!g->no->image || !g->so->image || !g->we->image || !g->ea->image)
		return ((void)(ft_err("file not opened", g)));
	ft_mlx2(g, b);
}

int	move_release(int keyCode, t_game *game)
{
	if (keyCode == 13)
		game->w = false;
	if (keyCode == 1)
		game->s = false;
	if (keyCode == 0)
		game->a = false;
	if (keyCode == 2)
		game->d = false;
	if (keyCode == 124)
		game->right = false;
	if (keyCode == 123)
		game->left = false;
	return (0);
}

void	calculate_wall_height(t_game *game)
{
	if (game->side == 0)
		calculate_wall_height_x(game);
	else if (game->side == 1)
		calculate_wall_height_y(game);
}
