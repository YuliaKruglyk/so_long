/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:18:47 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/08/02 10:39:18 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define BOLDRED    "\033[31m"
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53
# define SIZE   48

# include <mlx.h>
// # include "../libft/libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h> 

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			check_collect;
	int			check_player;
	int			check_exit;
	size_t		xsize;
	int			ysize;
	int			posx;
	int			posy;
	int			collect;
	int			move;
}				t_game;

typedef struct s_image
{
	char				*path;
	struct s_game		wlx;
	void				*img;
	int					height;
	int					width;
}						t_image;

typedef struct s_texture
{
	char	*file;
	char	*path;
}	t_texture;

size_t		ft_strlen(const char *str);
t_texture	set_texture(char name);

int		key_check(int key_code, t_game *game);
int		destroy_window(t_game *game);
int		linelen(int fd);
int		linecount(int fd);

void	start(t_game *game);
void	error(char *msg, t_game *game);
void	check_wall(t_game *game);
void	check_map(t_game *game);
void	check_game(t_game *game);
int		check_move(t_game *game, int y, int x);
void	window_size(t_game *data, char **argv);
void	*myfree(void *str);
void	*img_put(t_image image, int x, int y);
void	map_build(t_game *game, int i);
void	background_build(t_game game, int b);
void	maplen(char *area, t_game *game, int i);
void	map_gnl(t_game *game, char **argv);
void	update(t_game *game, int x, int y);
void	right(t_game *game);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	map_destroy(t_game	*game);

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char format);
int		ft_charprint(int c);
int		ft_strprint(char *str);
int		ft_nbrprint(int n);
int		ft_percprint(void);
int		ft_ptrlen(uintptr_t ptr);
int		ft_ptrprint(unsigned long long ptr);
int		ft_nbrlen(unsigned int num);
int		ft_unsdprint(unsigned int num);
int		ft_hexlen(unsigned	int n);
int		ft_hexprint(unsigned int n, const char format);
char	*ft_unsd_itoa(unsigned int num);

void	ft_putptr(uintptr_t p);
void	ft_puthex(unsigned int n, const char format);
void	putstr(char *str);

int		ft_len(int n);
int		ft_pos_neg(int n);
char	*ft_null(int n, char *str);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);

#endif
