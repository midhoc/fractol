/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 22:09:15 by midounhocin       #+#    #+#             */
/*   Updated: 2019/08/27 15:04:59 by midounhocin      ###   ########.fr       */
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
	ft_bzero(fractol, sizeof(fractol));
	fractol->zoom = 1;
	fractol->amp = 2;
}

int			main(void)
{
	t_fractol_info	fractol;
    
	
	initialize_fractol(&fractol);
	initialize_mlx(&fractol);
	instruction(&fractol);
	m(&fractol);
	mlx_put_image_to_window(fractol.mlx_ptr, fractol.win_ptr,fractol.img_ptr, X_INSTR, 0);
	mlx_hook(fractol.win_ptr, 17, 0, ft_exit, &fractol);
	mlx_loop(fractol.mlx_ptr);
	exit(0);
}
