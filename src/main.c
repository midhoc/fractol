/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:09:15 by midounhocin       #+#    #+#             */
/*   Updated: 2019/09/15 20:19:48 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static	void	initialize_mlx(t_fractol_info *fractol)
{
	int			bpp;
	int			s_l;
	int			endian;

	if (!(fractol->mlx_ptr = mlx_init()))
		ft_error(MLX_ERROR);
	if (!(fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
		X_SCREEN, Y_SCREEN, "fractol")))
		ft_error(MLX_ERROR);
	if (!(fractol->img_ptr = mlx_new_image(fractol->mlx_ptr, X_IMG, Y_IMG)))
		ft_error(MLX_ERROR);
	if (!(fractol->img_string = mlx_get_data_addr(fractol->img_ptr,
		&bpp, &s_l, &endian)))
		ft_error(MLX_ERROR);
}

static	void	initialize_fractol(t_fractol_info *fractol)
{
	ft_bzero(fractol, sizeof(t_fractol_info));
	reset_param(fractol);
}

static	void	check_ag(int argc, char **argv, t_fractol_info *fractol)
{
	if (argc != 2)
		ft_error(ARGS_ERROR);
	if (ft_strcmp(argv[1], "julia") == 0)
		fractol->fun_ptr = julia;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractol->fun_ptr = mand;
	else if (ft_strcmp(argv[1], "mandelbrot_3") == 0)
		fractol->fun_ptr = mand3;
	else
		ft_error(ARGS_ERROR);
}

void			reset_param(t_fractol_info *fractol)
{
	fractol->amp = 4;
	fractol->x_offset = fractol->amp / 2;
	fractol->y_offset = fractol->amp / 2;
	fractol->on_j_mouse = 1;
	fractol->color_type = 1;
	fractol->max_itr = 100;
}

int				main(int argc, char **argv)
{
	t_fractol_info	fractol;

	initialize_fractol(&fractol);
	check_ag(argc, argv, &fractol);
	initialize_mlx(&fractol);
	draw(&fractol);
	mlx_hook(fractol.win_ptr, 6, 0, mouse_move, &fractol);
	mlx_hook(fractol.win_ptr, 4, 0, mouse_press, &fractol);
	mlx_hook(fractol.win_ptr, 2, 0, key_press, &fractol);
	mlx_hook(fractol.win_ptr, 17, 0, ft_exit, &fractol);
	mlx_loop(fractol.mlx_ptr);
	exit(0);
}
