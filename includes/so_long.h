/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 13:54:36 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-14 13:54:36 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;
}				t_img;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			route;
	int			direction;
	int			enemy_n;
	int			hit;
}				t_enemy;

typedef struct s_path
{
	char		*wall;
	char		*floor;
	char		*collect;
	char		*player1;
	char		*player2;
	char		*player3;
	char		*enemy1;
	char		*enemy2;
	char		*enemy3;
	char		*door;
	char		*counter;
	char		*attack_hit;
	char		*attack_miss;

}				t_path;

typedef struct s_core
{
	void		*mlx;
	void		*win;

	uint64_t	frame;

	t_img		floor;
	t_img		wall;
	t_img		collect;
	t_img		door;
	t_img		player1;
	t_img		player2;
	t_img		player3;
	t_img		counter;
	t_img		enemy1;
	t_img		enemy2;
	t_img		enemy3;

	t_img		attack_hit;
	t_img		attack_miss;

	t_map		map_info;

	t_enemy		enemy;

	int			toggle;
	int			move_count;

	int			attack_state;
	int			attack_dir;
	int			attack_frame;
	int			attack_x;
	int			attack_y;

	int			player_x;
	int			player_y;

}				t_core;

// ERRORS
# define ERROR -1
# define INVALID_INPUT -1
# define INVALID_MAP -2
# define INVALID_FILE -3
# define FAIL_DISPLAY -4
# define MALLOC_FAIL -5

// MAP_COMPLETION_CHECK
# define COMPLETE 1
# define NOT_COMPLETE 0

// ENEMY_MOVEMENT
# define HORIZONTAL 1
# define VERTICAL 2
# define UP 1
# define DOWN -1
# define LEFT 2
# define RIGHT -2
# define POSSIBLE 0
# define NOT_POSSIBLE -1

// TEXTURE
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define ENEMY 'X'
# define COLLECT 'C'
# define DOOR 'E'

// KEY_CONFIG
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define ATTACK_U 65362
# define ATTACK_L 65361
# define ATTACK_D 65364
# define ATTACK_R 65363

void			print_error(int error_type);

// void			validate_map(t_map map_info, char *map_name);
// void			validate_componets(map_info);
// void			validate_shape(map_info);
// void			validate_playability(map_info);
// void			validate_size(map_info);
// void			validate_filename(char *map_name);

t_map			handle_map(char *map_name);
int				preview_map(char *map_name);
char			**convert_map(char *map_name, int height);
t_map			init_map(char **map, int width, int height);
void			find_player(t_map map_info, t_core *so_long);
void			find_enemy(t_map map_info, t_core *so_long);
void			init_core(t_map map_info, t_core *so_long);
void			reinit_core(t_map map_info, t_core *so_long, void *mlx,
					void *mlx_win);
// void		refresh_core(t_map map_info, t_core *so_long, void *mlx,
// 				void *mlx_win);
int				is_map_complete(char **map, t_core *so_long);
int				game_clear(t_core *so_long);

void			mlx(t_map map_info);

void			*display_window(void *mlx);
void			display_map(t_map map, void *mlx, void *mlx_win,
					t_core *so_long);
void			display_chunk_two(char c, void *mlx, void *mlx_win,
					t_core *so_long);
void			display_chunk_three(char c, void *mlx, void *mlx_win,
					t_core *so_long);
void			print_chunk(char c, int x, int y, void *mlx, void *mlx_w,
					t_core *so_lg);
void			print_chunk_two(char c, int x, int y, void *mlx, void *mlx_w,
					t_core *so_lg);
void			display_chunk(char c, void *mlx, void *mlx_win,
					t_core *so_long);
void			print_move_count(t_core *so_long);
void			get_images_one(void *mlx, t_core *so_long);
void			get_images_two(void *mlx, t_core *so_long);
void			get_images_three(void *mlx, t_core *so_long);
void			image_error_check(t_core *so_long);

int				handle_key_input(int key, void *so_long_void);
void			player_movement(t_map map_info, void *mlx, void *mlx_win,
					t_core *so_long);
void			movement_up(int key, t_core *so_long);
void			movement_left(int key, t_core *so_long);
void			movement_down(int key, t_core *so_long);
void			movement_right(int key, t_core *so_long);

int				render(void *so_long_void);
void			enemy_movement(t_core *so_long);
int				enemy_move_up(t_core *so_long);
int				enemy_move_left(t_core *so_long);
int				enemy_move_down(t_core *so_long);
int				enemy_move_right(t_core *so_long);
void			enemy_dies(char c, void *mlx, void *mlx_win, t_core *so_long);
int				check_rout(t_core *so_long);

void			note_attack(int key, t_core *so_long);
void			draw_attack_effect(t_core *so_long);
int				did_attack_hit(t_core *so_long);
void			check_attack_hit(t_core *so_long);
void			attack_up(t_core *so_long);
void			attack_left(t_core *so_long);
void			attack_down(t_core *so_long);
void			attack_right(t_core *so_long);

void			move_forward(t_core *so_long, int new_x, int new_y);
void			move_and_collect(t_core *so_long, int new_x, int new_y);
void			hit_wall(t_core *so_long);
void			move_to_door(t_core *so_long, int new_x, int new_y);
void			end_game(t_core *so_long);

void			free_map(char **map);
void			free_images(t_core *so_long);
void			free_all(t_core *so_long);

#endif
