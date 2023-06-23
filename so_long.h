/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:38 by gabriela          #+#    #+#             */
/*   Updated: 2023/06/19 14:51:37 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "./include/minilibx/mlx.h"
# include "./include/libft/libft.h"

# define BUFFER_SIZE 1
# define GAME "GTA"
# define INSTRUCTIONS_1 "Welcome to GabTan Auto! (GTA for short)"
# define INSTRUCTIONS_2 "Toni wants you to get all the cash along the way, no questions asked."
# define INSTRUCTIONS_3 "The cops are coming! Get the cash and go hide in the garage!"
# define FAIL "Busted!"
# define SUCCESS "You made it!"

// xpm sprites
# define IMG_EXIT "./xpm/exit_32.xpm"
# define IMG_TILE "./xpm/tile_32.xpm"
# define IMG_WALL "./xpm/wall_32.xpm"
# define IMG_COLLECTIBLE "./xpm/cash_32.xpm"
# define IMG_W_EAST "./xpm/IMG_W_EAST.xpm"
# define IMG_W_WEST "./xpm/IMG_W_WEST.xpm"
# define IMG_ENEMY "./xpm/IMG_E_W_EAST.xpm"

/* Struct 'xpm' for MiniLibX window and image handling */
typedef struct s_set
{
	void	*mlx;
	void	*mlx_win;
	int		window_width;
	int		window_height;
	int		img_size;
}				t_set;

/* Struct 'img' for handling the game's tiles and sprites sizes */
typedef struct s_img
{
	void	*sprite;
	int		width;
	int		height;
}				t_img;

/* Struct 'game' to read map characters and create gamefield grid */
typedef struct map_coordinates
{
	char	**map;
	int		map_width;
	int		map_height;
	int		cash;
	int		player;
	int		exit;
	int		enemy;
	int		*enemy_on_col;
	int		*enemy_on_row;
	int		*enemy_last_col;
	int		*enemy_last_row;
	int		*enemy_flag;
	int		enemy_move;
}				t_map;

/* Struct 'player' to handle the player's position and continue playing */
typedef struct s_player
{
	int		player_on_col;
	int		player_on_row;
	int		player_last_col;
	int		player_last_row;
	int		moves;
	int		player_alive;
	int		enemy_check;
}				t_player;

/* Struct 'so_long' to pass on all structs in the game */
typedef struct s_master
{
	t_set		set;
	t_img		*sprite[7];
	t_img		xpm;
	t_map		gta;
	t_player	player;
	int			key;
	int			last_key;
	int			win;
}				t_master;

/* Define all necessar keycodes to distinguish moves during game */
# define A 0
# define S 1
# define D 2
# define W 13
# define Q 12
# define ESC 0x35

/* get next line */
// put into libft
char	*ft_extract(char *s);
char	*ft_remainder(char *s);
char	*ft_reading(int fd, char *s);
char	*get_next_line(int fd);

/* input handling */
int			ft_input_handling(int argc, char *argv[]);
int			main(int argc, char *argv[]);
// add ft_handle_sprites from window_image_handling

/* map_error_handlong */
int	ft_check_border_elements(t_map *gta);
int	ft_check_valid_characters(t_map *gta);
int	ft_check_invalid_elements(t_map *gta);
int	ft_check_map(t_master *game);

/* map_creation */
void	ft_map_init(t_master *game);
void	ft_map_read_content(char *file, t_master *game);
void	ft_failed_allocation(t_master *game);
int		ft_map_allocation(t_master *game);
void	ft_map_set_size(char *file, t_master *game);

/* player_moves */
void	ft_move_player(t_master *game, int row, int col);
// add ft_player_placement from
int	ft_check_enemy(t_master *game, int row, int col);
int	ft_check_path(t_master *game, int row, int col);
int	ft_check_exit(t_master *game, int row, int col);
int	ft_move(t_master *game, int keycode);

/* map_build */
//remove whole file
// add ft_character_sprite to window_image_handling
// add ft_occupy_map together with ft_move from player_moves to window_image_handling
void	*ft_character_sprite(t_master *game, int col, int row);
void	ft_occupy_map(t_master *game);

/* keyhook */
//rename file to handle_messages
//add ft_start_message from window_image_handling
void	ft_info_message(t_master *game);
void	ft_end_message(t_master *game);
int		ft_quit(int keycode, t_master *game);

/* init_game */
void	ft_enemy_placement(t_master *game);
void	ft_enemy_allocation(t_map *gta);
void	ft_player_placement(t_master *game);
void	ft_game_init(t_master *game);

/* end_game */
void	ft_free_sprites(t_master *game);
void	ft_free_map(t_master *game);
void	ft_free_enemy(t_map *gta);
int		ft_clean_up(t_master *game);

/* enemy_move */
int	ft_enemy_down_up(t_map *gta, int enemy_no, int row, int col);
int	ft_enemy_left_right(t_map *gta, int enemy_no, int row, int col);
int	ft_move_enemy(t_map *gta);

/* window_image_handling */
void	ft_load_player_images(t_master *game);
void	ft_load_images(t_master *game);
void	ft_start_message(t_master *game);
// add ft_start_message to keyhook
void	ft_handle_sprites(t_master *game);
// add ft_handle_sprites to window_image_handling

#endif
