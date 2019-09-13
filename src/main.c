/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:09:15 by midounhocin       #+#    #+#             */
/*   Updated: 2019/09/13 14:34:20 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	initialize_mlx(t_fractol_info *fractol)
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

void	initialize_fractol(t_fractol_info *fractol)
{
	ft_bzero(fractol, sizeof(t_fractol_info));
	reset_param(fractol);
}

void	check_ag(int argc, char **argv, t_fractol_info *fractol)
{
	if (argc != 2)
		ft_error(ARGS_ERROR);
	if (ft_strcmp(argv[1], "julia") == 0)
		fractol->fun_ptr = j;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractol->fun_ptr = m;
	else
		ft_error(OPTION_ERROR);
}

int mouse_press(int button, int x, int y, t_fractol_info *fractol)
{
	if (button == SCROLL_UP)
		zoom(fractol,x, y, 0);
	else if (button == SCROLL_DOWN)
		zoom(fractol,x, y, 1);
	fractol->fun_ptr(fractol);
	return (0);
}

void	reset_param(t_fractol_info *fractol)
{
	//fractol->zoom = 1;
	fractol->amp = 4;
	fractol->x_offset = fractol->amp/2;
	fractol->y_offset = fractol->amp/2;
}
int			main(int argc, char **argv)
{
	t_fractol_info	fractol;

	initialize_fractol(&fractol);
	check_ag(argc, argv, &fractol);
	initialize_mlx(&fractol);
	fractol.fun_ptr(&fractol);
	if (fractol.fun_ptr == j)
		mlx_hook(fractol.win_ptr, 6, 0, mouse_move, &fractol);
	mlx_hook(fractol.win_ptr, 4, 0, mouse_press, &fractol);
	mlx_hook(fractol.win_ptr, 2, 0, key_press, &fractol);
	mlx_hook(fractol.win_ptr, 17, 0, ft_exit, &fractol);
	mlx_loop(fractol.mlx_ptr);
	exit(0);
}
