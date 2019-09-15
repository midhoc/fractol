/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 04:13:42 by jaelee            #+#    #+#             */
/*   Updated: 2019/09/15 19:28:37 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(t_fractol_info *fractol)
{
	(void)fractol;
	exit(0);
}

int	ft_error(int type)
{
	if (type == ARGS_ERROR)
	{
		ft_putendl("error in input arguments.");
		ft_putendl("usage: ./fractol [fractol type]");
		ft_putendl("options: julia, mandelbrot, mandelbrot_3");
	}
	else if (type == MLX_ERROR)
		ft_putendl("mlx error.");
	exit(0);
}
