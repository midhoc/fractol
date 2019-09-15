/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:26:39 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/15 19:20:22 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int button, int x, int y, t_fractol_info *fractol)
{
	if (button == SCROLL_UP)
		zoom(fractol, x, y, 0);
	else if (button == SCROLL_DOWN)
		zoom(fractol, x, y, 1);
	else if (button == 1)
		fractol->on_j_mouse = !(fractol->on_j_mouse);
	else if (button == 2)
		fractol->color_type = !(fractol->color_type);
	fractol->fun_ptr(fractol);
	return (0);
}

int		mouse_move(int x, int y, t_fractol_info *fractol)
{
	if (fractol->fun_ptr == julia)
	{
		if (fractol->on_j_mouse)
		{
			fractol->ac = ((double)x - 0) / (X_IMG) *
						(fractol->amp) - fractol->x_offset;
			fractol->bc = ((double)y - 0) / (Y_IMG) *
						(fractol->amp) - fractol->y_offset;
		}
		julia(fractol);
	}
	return (1);
}

int		key_press(int keycode, t_fractol_info *fractol)
{
	if (keycode == ARROW_UP)
		fractol->y_offset -= fractol->amp / 10;
	else if (keycode == ARROW_DOWN)
		fractol->y_offset += fractol->amp / 10;
	else if (keycode == ARROW_LEFT)
		fractol->x_offset -= fractol->amp / 10;
	else if (keycode == ARROW_RIGHT)
		fractol->x_offset += fractol->amp / 10;
	else if (keycode == MAIN_PAD_SPACE)
		reset_param(fractol);
	else if (keycode == NUMBER_PAD_PLUS)
		zoom(fractol, X_IMG / 2, Y_IMG / 2, 1);
	else if (keycode == NUMBER_PAD_MINUS)
		zoom(fractol, X_IMG / 2, Y_IMG / 2, 0);
	else if (keycode == PAD_1 || keycode == PAD_2 || keycode == PAD_3)
		change_fract(fractol, keycode);
	else if (keycode == MAIN_PAD_ESC)
		exit(0);
	fractol->fun_ptr(fractol);
	return (0);
}

void	zoom(t_fractol_info *fractol, int x, int y, int in_out)
{
	if (!in_out)
	{
		fractol->x_offset += x * fractol->amp / X_IMG;
		fractol->y_offset += y * fractol->amp / Y_IMG;
		fractol->amp *= 2;
	}
	else
	{
		fractol->x_offset -= 0.5 * x * fractol->amp / X_IMG;
		fractol->y_offset -= 0.5 * y * fractol->amp / Y_IMG;
		fractol->amp /= 2;
	}
}

void	change_fract(t_fractol_info *fractol, int opt)
{
	if (opt == PAD_1)
		fractol->fun_ptr = mand;
	else if (opt == PAD_2)
		fractol->fun_ptr = julia;
	else if (opt == PAD_3)
		fractol->fun_ptr = mand3;
}
