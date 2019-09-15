/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:00:41 by midounhocin       #+#    #+#             */
/*   Updated: 2019/09/15 20:27:52 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include "libft.h"

# define SUCCESS			1
# define FAIL				0
# define X_SCREEN			(2 * 300)
# define Y_SCREEN			(2 * 300)
# define Y_IMG				Y_SCREEN
# define X_IMG				(X_SCREEN)
# define SIZE_IMG			4 * ((Y_IMG) * X_IMG)
# define KEY_PRESS			2
# define KEY_RELEASE		3
# define BLACK 				0x000000
# define WHITE 				0xFFFFFF
# define SCROLL_UP			4
# define SCROLL_DOWN		5
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define NUMBER_PAD_PLUS	69
# define NUMBER_PAD_MINUS	78
# define MAIN_PAD_I			34
# define MAIN_PAD_P			35
# define MAIN_PAD_W			13
# define MAIN_PAD_S			1
# define MAIN_PAD_A			0
# define MAIN_PAD_D			2
# define MAIN_PAD_Q			12
# define MAIN_PAD_E			14
# define MAIN_PAD_SPACE		49
# define MAIN_PAD_ESC		53
# define PAD_9				92
# define PAD_8				91
# define PAD_6				88
# define PAD_1				83
# define PAD_2				84
# define PAD_3				85
# define ARGS_ERROR			1
# define INVALID_MAP		2
# define FILE_ERROR			3
# define MLX_ERROR			4
# define MALLOC_ERROR		5
# define CLOSE_FILE_ERROR	6
# define OPTION_ERROR		7

typedef struct	s_info
{
	int		x;
	int		y;
	int			n_itr;
}				t_info;

typedef struct	s_fractol_info
{
	double	x_offset;
	double	y_offset;
	double	ac;
	double	bc;
	double	amp;
	int		max_itr;
	int		color_type;
	int		on_j_mouse;
	int		(*fun_ptr)(int, int, struct s_fractol_info *);

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_string;
}				t_fractol_info;

int		ft_exit(t_fractol_info *fractol);
int		ft_error(int type);

void	instruction(t_fractol_info *fractol);

void	draw_line_x(t_info p1, t_info p2, t_fractol_info *fractol);
void	draw_line_y(t_info p1, t_info p2, t_fractol_info *fractol);
void	draw_line(t_info p1, t_info p2, t_fractol_info *fractol);

void	pixel_in_img(char *image_string, int x, int y, int color);
void	reset_img(char *image_string);

int		mand(int i, int j, t_fractol_info *fractol);
int		julia(int i, int j, t_fractol_info *fractol);
int		mand3(int i, int j, t_fractol_info *fractol);
void	draw(t_fractol_info *fractol);

int		mouse_move(int x, int y, t_fractol_info *fractol);
int		mouse_press(int button, int x, int y, t_fractol_info *fractol);
void	zoom(t_fractol_info *fractol, int x, int y, int in_out);
int		key_press(int keycode, t_fractol_info *fractol);
void	reset_param(t_fractol_info *fractol);
void	change_fract(t_fractol_info *fractol, int opt);
void	change_max_itr(t_fractol_info *fractol, int plus_m);

int		get_light(int start, int end, double percentage);
int		b_w_color(double percentage);
int		rainbow(double percentage);
int		color(double percentage, t_fractol_info *fractol);

#endif
