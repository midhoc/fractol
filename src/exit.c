/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 04:13:42 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/26 18:34:13 by midounhocin      ###   ########.fr       */
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
		ft_putendl("usage: ./fractol [file.fractol]");
	}
	if (type == INVALID_MAP)
		ft_putendl("parsing error.");
	if (type == FILE_ERROR)
		ft_putendl("cannot open the file.");
	if (type == MLX_ERROR)
		ft_putendl("mlx error.");
	if (type == MALLOC_ERROR)
		ft_putendl("MALLOC ERROR.");
	exit(0);
}
