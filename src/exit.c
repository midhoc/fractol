/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 04:13:42 by jaelee            #+#    #+#             */
/*   Updated: 2019/09/13 23:36:18 by hmidoun          ###   ########.fr       */
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
		ft_putendl("options: julia, mandelbrot, ");
	}
	else if (type == MLX_ERROR)
		ft_putendl("mlx error.");
	else if (type == OPTION_ERROR)
		ft_putendl("options: julia, mandelbrot, ");
	exit(0);
}
