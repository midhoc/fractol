/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:09:15 by midounhocin       #+#    #+#             */
/*   Updated: 2019/09/12 17:31:19 by hmidoun          ###   ########.fr       */
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
	//fractol->fract = (t_info *)malloc(sizeof(t_info) * X_IMG *Y_IMG);
	fractol->zoom = 1;
	fractol->amp = 2;
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

int			main(int argc, char **argv)
{
	t_fractol_info	fractol;

	initialize_fractol(&fractol);
	check_ag(argc, argv, &fractol);
	initialize_mlx(&fractol);
//	instruction(&fractol);
	fractol.fun_ptr(&fractol);
	if (fractol.fun_ptr == j)
		mlx_hook(fractol.win_ptr, 6, 0, mouse_move, &fractol);
	mlx_hook(fractol.win_ptr, 17, 0, ft_exit, &fractol);
	mlx_loop(fractol.mlx_ptr);
	exit(0);
}
