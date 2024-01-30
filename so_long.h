/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 07:48:00 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 17:50:45 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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
	void	*mlx_win;
	int		x;
	int		x_max;
	int		y_max;
	int		y;
	int		end_x;
	int		end_y;
	int		pos_x;
	int		pos_y;
	void	*krokmou[3];
	void	*furie[3];
	void	*fond;
	void	*collect;
	void	*crystal;
	char	*rel_krokmou;
	char	*rel_krokmou1;
	char	*rel_fond;
	char	*rel_collect;
	char	*rel_crystal;
	char	*rel_eclairfurie;
	char	*rel_haut;
	char	*rel_bas;
	char	*rel_haut1;
	char	*rel_bas1;
	char	*rel_up;
	char	*rel_down;
	char	**map1;
	int		max;
	int		nb_collec;
	int		mov;
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
void	perso(t_game *s, t_map *map);
void	perso2(t_game *s, t_map *map);
void	move_left(t_game *start);
void	fond(t_game *s, t_map *map);
void	mur(t_game *s, t_map *map);
void	display_map(t_game *s, t_map *map);
void	move_right(t_game *s);
void	move_up(t_game *s);
void	move_down(t_game *s);
void	*xpm_to_img(t_game game, char *str);
void	collect(t_game *s, t_map *map);
char	*ft_itoa(int n);
void	print_count(t_game *s);
int		ft_animate(t_game s);
int		ft_animate2(t_game s);
int		render_next_frame(t_game *s);
void	init_sprites(t_game *s);
void	print_img(t_game s, void *img, int x, int y);
int		ft_close(int keycode, t_game *start);
void	dir_left(t_game	*s);
void	dir_right(t_game *s);
void	if_collect(t_game *s, int i, int j, int index);
void	left_right(t_game *s, int i, int j, int bol);
int		ft_close2(t_game *start);
void	print_final(void);
char	*ft_strjoin(char const *s1, char const *s2);
t_map	*map1(void);
void	fk_norme(char *line, t_map *map, int fd);

#endif