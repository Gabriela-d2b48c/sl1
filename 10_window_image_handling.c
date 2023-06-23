/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_window_image_handling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:03:54 by gabriela          #+#    #+#             */
/*   Updated: 2023/06/19 14:51:25 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Allocate and load images of the player */
void	ft_load_player_images(t_master *game)
{
	game->sprite[4] = ft_calloc(1, sizeof(t_img));
	game->sprite[4]->sprite = mlx_xpm_file_to_image(game->set.mlx, IMG_W_EAST,
			&(game->sprite[4]->width), &(game->sprite[4]->height));
	game->sprite[6] = ft_calloc(1, sizeof(t_img));
	game->sprite[6]->sprite = mlx_xpm_file_to_image(game->set.mlx, IMG_W_WEST,
			&(game->sprite[6]->width), &(game->sprite[6]->height));
}

/* Allocate and load images of other characters */
void	ft_load_images(t_master *game)
{
	game->sprite[0] = ft_calloc(1, sizeof(t_img));
	game->sprite[0]->sprite = mlx_xpm_file_to_image(game->set.mlx,
			IMG_TILE, &(game->sprite[0]->width),
			&(game->sprite[0]->height));
	game->sprite[1] = ft_calloc(1, sizeof(t_img));
	game->sprite[1]->sprite = mlx_xpm_file_to_image(game->set.mlx, IMG_WALL,
			&(game->sprite[1]->width), &(game->sprite[1]->height));
	game->sprite[2] = ft_calloc(1, sizeof(t_img));
	game->sprite[2]->sprite = mlx_xpm_file_to_image(game->set.mlx,
			IMG_COLLECTIBLE, &(game->sprite[2]->width),
			&(game->sprite[2]->height));
	game->sprite[3] = ft_calloc(1, sizeof(t_img));
	game->sprite[3]->sprite = mlx_xpm_file_to_image(game->set.mlx, IMG_EXIT,
			&(game->sprite[3]->width), &(game->sprite[3]->height));
	game->sprite[4] = ft_calloc(1, sizeof(t_img));
	game->sprite[4]->sprite = mlx_xpm_file_to_image(game->set.mlx, IMG_ENEMY,
			&(game->sprite[4]->width), &(game->sprite[4]->height));
	ft_load_player_images(game);
}

/* Print the game starting message */
void	ft_start_message(t_master *game)
{
	mlx_string_put(game->set.mlx, game->set.mlx_win, 10, 20,
		0xFFFFFFFF, INSTRUCTIONS_1);
	mlx_string_put(game->set.mlx, game->set.mlx_win, 10, 35,
		0xFFFFFFFF, INSTRUCTIONS_2);
	mlx_string_put(game->set.mlx, game->set.mlx_win, 10, 50,
		0xFFFFFFFF, INSTRUCTIONS_3);
}

void	ft_handle_sprites(t_master *game)
{
	game->set.mlx_win = mlx_new_window(game->set.mlx,
			game->set.window_width, game->set.window_height,
			GAME);
	ft_load_images(game);
	ft_occupy_map(game);
	ft_start_message(game);
	ft_info_message(game);
}