/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:49:52 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 17:58:35 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map
{
	int		e;
	int		p;
	int		c;
	int		len;
	int		nb_line;
	char	**m;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	int		nb_line1;
	void	*mlx_win;
	int		x;
	int		x_max;
	int		y_max;
	int		y;
	int		bat_x;
	int		bat_y;
	int		end_x;
	int		end_y;
	int		pos_x;
	int		pos_y;
	void	*krokmou[3];
	void	*furie[3];
	void	*bat[3];
	void	*collect[3];
	void	*fireball;
	void	*fond;
	void	*crystal;
	char	*rel_krokmou;
	char	*rel_krokmou1;
	char	*rel_fond;
	char	*rel_collect;
	char	*rel_collect1;
	char	*rel_collect2;
	char	*rel_crystal;
	char	*rel_eclairfurie;
	char	*rel_bat;
	char	*rel_bat_up;
	char	*rel_bat_down;
	char	*rel_haut;
	char	*rel_bas;
	char	*rel_haut1;
	char	*rel_bas1;
	char	*rel_up;
	char	*rel_down;
	char	*rel_batleft;
	char	*rel_batupleft;
	char	*rel_batdownleft;
	char	*rel_fireball;
	char	*rel_leftfireball;
	char	**map1;
	int		max;
	int		nb_collec;
	int		mov;
	int		nb_e;
	int		nb_bat;
	int		nb_c;
	int		dir;
	int		len;
	int		fire_x;
	int		fire_y;
	int		i;
	int		j;
	int		tp;
}	t_game;

int		ft_printf(int fd, const char *str, ...);
int		ft_strlen(const char *str);
void	error(char *str);
int		check_format(char *str);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	parce_error(char *str);
void	parce_first(char *str, t_map *map, int bol);
void	parce_line(char *str, t_map *map);
void	start(t_map map, char *str);
char	**fill_map(char *str);
void	ft_freedouble(char **ptr);
int		get_nb_line(char *str);
int		get_nb_e(t_map *map);
void	move_left(t_game *start);
void	fond(t_game *s, t_map *map);
void	mur(t_game *s, t_map *map);
void	display_map(t_game *s, t_map *map);
void	move_right(t_game *s);
void	move_up(t_game *s);
void	move_down(t_game *s);
void	*xpm_to_img(t_game game, char *str);
int		get_collect(t_map *map, t_game *s);
char	*ft_itoa(int n);
void	print_count(t_game *s);
int		ft_animate(t_game s);
int		ft_animate2(t_game s);
int		ft_animate3(t_game s);
int		ft_animate4(t_game s);
void	init_sprites(t_game *s);
void	print_img(t_game s, void *img, int x, int y);
int		ft_close(int keycode, t_game *start);
void	dir_left(t_game	*s, int bol);
void	dir_right(t_game *s, int bol);
void	if_collect(t_game *s, int i, int j, int index);
void	left_right(t_game *s, int i, int j, int bol);
int		ft_close2(t_game *start);
void	init_img(t_game *start);
int		patrol(t_game *s);
void	moving(t_game *s);
void	movebat_up(t_game *s);
void	movebat_down(t_game *s);
void	movebat_left(t_game *s);
void	movebat_right(t_game *s);
void	init_value(t_game *s, t_map *map);
int		get_nb_bat(t_map *map);
void	pushfire(t_game *s);
void	move_fireright(t_game *s);
void	move_fireleft(t_game *s);
void	move_fire(t_game *s);
void	fk_norm2(t_game *s, int bol, int i, int j);
void	is_bat(t_game *s, int i, int j, int bol);
void	is_letter(t_game *s, int i, int j, int index);
void	up_down(t_game *s, int i, int j, int bol);
void	is_letter2(t_game *s, int i, int j, int bol);
void	is_collect2(t_game *s, int i, int j, int bol);
void	print_final(void);

#endif