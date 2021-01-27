/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:46:38 by abrun             #+#    #+#             */
/*   Updated: 2021/01/27 11:15:18 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/printf.h"

typedef struct		s_player
{
	int			x;
	int			y;
	int			len;
	int			angle;
	int			speed;
}					t_player;

typedef struct		s_img
{
	int			bpp;
	int			size_line;
	int			endian;
	char		*data;
	void		*image;
	int			width;
	int			height;
}					t_img;

typedef struct		s_map
{
	int		height;
	int		max_width;
	int		len_pix;
	int		dir;
	char	**map;
}					t_map;

typedef struct		s_wall
{
	int			height;
	int			width;
	int			n;
	t_img		img;
	int			coeff;
}					t_wall;

typedef struct		s_walls
{
	t_wall		wall1;
	t_wall		wall2;
	t_wall		wall3;
	t_wall		wall4;
	t_wall		sprite;
}					t_walls;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	void		*win_map;
	t_img		img_map;
	int			height;
	int			width;
	int			max_w;
	int			max_h;
	t_walls		walls;
	t_wall		wall;
	t_player	hero;
	t_img		img;
	t_map		map;
	char		*no;
	char		*ea;
	char		*we;
	char		*so;
	char		*sp;
	char		*tab;
	int			*floor;
	int			*roof;
	int			checks[8];
	char		*cub;
}					t_param;

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_vect
{
	double	x;
	double	y;
	int		wall;
}					t_vect;

double				convert(double degre);

void				get_pt_a_hori(t_player hero, t_vect *pt_a,
				t_map map, double angle);

void				get_pt_a_hori_90(t_player hero, t_vect *pt_a,
				t_map map, double angle);

void				get_vector_hori(double angle, int len_pix, t_vect *vector);

int					is_wall_hori(t_vect pt, double angle, t_param param);

t_vect				get_pt_h(t_param param, t_map map, double angle);

void				get_pt_a_vert(t_player hero, t_vect *pt_a,
				t_map map, double angle);

void				get_pt_a_vert_90(t_player hero, t_vect *pt_a,
				t_map map, double angle);

void				get_vector_vert(double angle, int len_pix, t_vect *vector);

int					get_x(t_vect pt, double angle, t_param param);

int					is_wall_vert(t_vect pt, double angle, t_param param);

t_vect				get_pt_v(t_param param, t_map map, double angle);

t_vect				get_dist_min(t_vect pt_h, t_vect pt_v,
				t_param *param, double angle);

void				get_wall_dim(t_wall *wall, double dist, t_param param);

double				get_d(t_player hero, t_vect pt_a, double counter);

double				get_angle_right(int angle_h, double counter);

void				dis_textures(t_wall wall, t_param *param, int pos_x);

void				draw_wall(t_wall wall, int pos_x,
				t_param *param, int color);

t_vect				get_pt_a_90(t_param *param, double angle);

double				get_distances(t_vect pt_h, t_vect pt_v, double *dist_h,
				t_param param);

void				display_multi_angle(t_param *param, int color);

int					move_hero(int key, t_param *param);

int					is_wall_around(t_player hero, t_img img);

int					is_wall_12(t_player hero, t_img img_map);

int					is_wall_6(t_player hero, t_img img_map);

void				move_key_12(t_player *hero, t_img img);

void				move_key_6(t_player *hero, t_img img);

size_t				get_height(char *tab);

size_t				get_max_width(char *tab);

size_t				get_length(char *tab);

int					fill_tabulation(char **map, int i, int *j);

char				*get_tab();

size_t				get_width(char *tab);

char				**get_map(char *tab, t_param *param);

int					loop_get_map(char *tab, char **map, int max_width, t_param *param);

int					init_map(t_map *map, char *tab, t_param *param);

int					get_dir(t_map map);

int					is_pos_hero(char **map);

void				init_img(t_img *img, t_param param);

void				init_hero(t_player *hero, t_map map);

void				init_wall1_img(t_wall *wall, t_param param);

void				init_wall2_img(t_wall *wall, t_param param);

void				init_wall3_img(t_wall *wall, t_param param);

void				init_wall4_img(t_wall *wall, t_param param);

void				init_sprite_img(t_wall *wall, t_param param);

void				put_xpm_to_final(char *data_final, char *data,
				int size_line, t_img img);

t_point				get_pos_hero(t_map map);

int					get_angle(t_map map);

int					init_param(t_param *param);

void				init_checks(t_param *param);

int					is_surrounded(char **map, int height);

int					first_and_last(char **map, int height);

int					right_side_check(char **map, int y);

int					left_side_check(char **map, int y);

int					first_last_line(char **map, int height);

int					last_line_2(char **map, int y);

int					last_line(char **map, int y);

int					xb_to_xf_last(int xb, int xf, char **map, int hei);

int					xb_to_xf_first(int xb, int xf, char **map, int hei);

void				ft_minus(int *plus, int *y);

void				ft_plus(int *minus, int *y);

int					get_xs_first(int *xb, int *xf, char **map);

int					get_xs_last(int *xb, int *xf, char **map, int hei);

void				display_map_case(t_map map, t_point	img_pt, t_param param);

void				display_map_empty_case(t_map map, t_point img_pt,
				t_param param);

void				display_map(t_map map, t_param param);

void				change_hero_pos(t_param param, int color);

void				display_pt_a(t_param param, int color, t_vect pt_a);

void				display_background(t_param param);

void				display_roof(t_param param, int height,
				int width, int size_line);

void				display_floor(t_param param, int height,
				int width, int size_line);

int					get_resolution(t_param *param, char *line);

int					check_resolution(int id, char *line);

int					fill_w_h(t_param *param, char *line, int id);

int					get_n(char *line);

int					get_param_cub(t_param *param, int fd);

int					get_no_path(t_param *param, char *line);

int					get_so_path(t_param *param, char *line);

int					get_we_path(t_param *param, char *line);

int					get_ea_path(t_param *param, char *line);

int					get_sp_path(t_param *param, char *line);

int					check_texture(char *id, char *line);

char				*get_element(int fd, t_param *param);

int					fill_param(t_param *param, char *line);

int					is_map(char *line);

int					fill_tab_map(char *line, int fd, char *tab, t_param *param);

int					get_color(char *line, t_param *param, int d);

int					fill_floor(t_param *param, int *tab);

int					fill_roof(t_param *param, int *tab);

int					*get_color_fill_tab(char *line);

int					check_color(int id, char *line);

int					check_all(int *checks, t_param *param);

void				free_param(t_param *param);

void				free_tab_checks(t_param *param);

void				free_map_param(t_param *param);

void				free_in_loop(t_param *param, int i, char **map);

#endif
