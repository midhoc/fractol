/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:00:41 by midounhocin       #+#    #+#             */
/*   Updated: 2019/08/26 23:14:29 by midounhocin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "array.h"

# define SUCCESS			1
# define FAIL				0
# define X_SCREEN			(4 * 250)
# define Y_SCREEN			(3 * 250)
# define X_INSTR			250
# define Y_IMG				Y_SCREEN
# define X_IMG				(X_SCREEN - X_INSTR)
# define SIZE_IMG			4 * ((Y_IMG) * X_IMG)
# define KEY_PRESS			2
# define KEY_RELEASE		3
# define BLACK 				0x000000
# define WHITE 				0xFFFFFF
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
# define PAD_6				88
# define ARGS_ERROR			1
# define INVALID_MAP		2
# define FILE_ERROR			3
# define MLX_ERROR			4
# define MALLOC_ERROR		5
# define CLOSE_FILE_ERROR	6

typedef struct	s_info
{
	int		x;
	int		y;
	int			n_itr;
}				t_info;

typedef struct	s_fractol_info
{
	int		x_offset;
	int		y_offset;
	int		zoom;
	int	amp;
	int	step;
	
	t_info	fract[Y_IMG][X_IMG];

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_string;
}				t_fractol_info;

int	ft_exit(t_fractol_info *fractol);
int	ft_error(int type);

void	initialize_mlx(t_fractol_info *fractol);
void	initialize_fractol(t_fractol_info *fractol);

void	instruction(t_fractol_info *fractol);

void	draw_line_x(t_info p1, t_info p2, t_fractol_info *fractol);
void	draw_line_y(t_info p1, t_info p2, t_fractol_info *fractol);
void	draw_line(t_info p1, t_info p2, t_fractol_info *fractol);

void	pixel_in_img(char *image_string, int x, int y, int color);
void	reset_img(char *image_string);

void    m(t_fractol_info *fractol);
void    j(t_fractol_info *fractol);

int		get_light(int start, int end, double percentage);
int		get_color(int start, int end, double percentage);
int     rainbow(double percentage);

#endif