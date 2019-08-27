/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:41:54 by midounhocin       #+#    #+#             */
/*   Updated: 2019/08/26 20:11:51 by midounhocin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	instruction2(t_fractol_info *fractol, int y)
{
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 20, 50 * y++, WHITE,
		"PROJECTION :");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 120, 50 * y++, WHITE,
		"ISO       : [I]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 120, 50 * y++, WHITE,
		"PARALLELE : [P]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 20, 50 * y++, WHITE,
		"COLOR :");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 120, 50 * y++, WHITE,
		"TOP    : [9]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 120, 50 * y++, WHITE,
		"BOTTOM : [6]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 20, 50 * y++, WHITE,
		"RESET 		: [SPACE]");
}

static void	instruction_background(t_fractol_info *fractol)
{
	int x;
	int y;
	int e;

	y = -1;
	while (++y < Y_SCREEN)
	{
		x = X_INSTR;
		e = 0;
		while (--x >= 0)
		{
			mlx_pixel_put(fractol->mlx_ptr, fractol->win_ptr, x, y, 0x5C5C5C - e);
			if (x % 3 == 0)
				e += (1 + 16 * 16 + 16 * 16 * 16 * 16);
		}
	}
}

void		instruction(t_fractol_info *fractol)
{
	int	i;
	int	y;

	y = 2;
	i = -1;
	instruction_background(fractol);
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 70, 40, WHITE,
		"HOW TO USE : fractol");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 20, 50 * y++, WHITE,
		"ZOOM 		: [+] [-]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 20, 50 * y++, WHITE,
		"MOVE 		: [<] [>]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 20, 50 * y++, WHITE,
		"ROTATION 	:");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 120, 50 * y++, WHITE,
		"X 	: [A] [D]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 120, 50 * y++, WHITE,
		"Y 	: [W] [S]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 120, 50 * y++, WHITE,
		"Z 	: [Q] [E]");
	instruction2(fractol, y);
}
