/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:12:24 by abrun             #+#    #+#             */
/*   Updated: 2021/01/18 15:41:43 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"

typedef struct	s_player
{
	int			x;
	int			y;
	int			len;
	int			angle;
	int			speed;
}				player;

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
}					t_wall;

typedef struct		s_walls
{
	t_wall		wall1;
	t_wall		wall2;
	t_wall		wall3;
	t_wall		wall4;
}					t_walls;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	//display_map
	void		*win_map;
	t_img		img_map;
	int			height;
	int			width;
	t_walls		walls;
	t_wall		wall;
	player		hero;
	t_img		img;
	t_map		map;
}					t_param;

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_vect
{
	double x;
	double y;
}					t_vect;

double				convert(double degre);

void				get_pt_a_hori(player hero, t_vect *pt_a, t_map map, double angle);

void				get_pt_a_hori_90(player hero, t_vect *pt_a, t_map map, double angle);

void				get_vector_hori(double angle, int len_pix, t_vect *vector);

int					is_wall_hori(t_vect pt, double angle, t_param param);

t_vect				get_pt_h(t_param param, t_map map, double angle);

void				get_pt_a_vert(player hero, t_vect *pt_a, t_map map, double angle);

void				get_pt_a_vert_90(player hero, t_vect *pt_a, t_map map, double angle);

void				get_vector_vert(double angle, int len_pix, t_vect *vector);

int					get_x(t_vect pt, double angle, t_param param);

int					is_wall_vert(t_vect pt, double angle, t_param param);

t_vect				get_pt_v(t_param param, t_map map, double angle);

t_vect				get_dist_min(t_vect pt_h, t_vect pt_v, t_param *param, double angle);

void				get_wall_dim(t_wall *wall, double dist, t_param param);

void				draw_wall(t_wall wall, int pos_x, t_param *param, int color);

t_vect				get_pt_a_90(t_param *param, double angle);

void				display_multi_angle(t_param *param, int color);

int					move_hero(int key, t_param *param);

size_t				get_height(char *tab);

int					get_max_width(char *tab);

size_t				get_length(char *tab);

int					fill_tabulation(char **map, int i, int *j);

char				*get_tab();

size_t				get_width(char *tab);

char				**get_map(char *tab);

void				init_map(t_map *map);

int					get_dir(t_map map);

void				init_img(t_img *img, t_param param);

void				init_hero(player *hero, t_map map);

void				init_wall1_img(t_wall *wall, t_param param);

void				init_wall2_img(t_wall *wall, t_param param);

void				init_wall3_img(t_wall *wall, t_param param);

void				init_wall4_img(t_wall *wall, t_param param);

void				put_xpm_to_final(char *data_final, char *data, int size_line, t_img img);

t_point				get_pos_hero(t_map map);

int					get_angle(t_map map);

void				init_param(t_param *param);

int					is_surrounded(char **map, int height);

int					first_and_last(char **map, int height);

int					right_side_check(char **map, int y);

int					left_side_check(char **map, int y);

int					last_line(char **map, int y);

int					last_line_2(char **map, int y);

int					last_line(char **map, int y);

//------------------Display_map------------------

void		display_map_case(t_map map, t_point	img_pt, t_param param);

void		display_map_empty_case(t_map map, t_point img_pt, t_param param);

void		display_map(t_map map, t_param param);

void		change_hero_pos(t_param param, int color);

void		display_pt_a(t_param param, int color, t_vect pt_a);
