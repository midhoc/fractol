/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:46:08 by midounhocin       #+#    #+#             */
/*   Updated: 2019/09/13 14:23:05 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static	int	nbr_itr(int i, int j, t_fractol_info *fractol, double ac, double bc)
{
		double a;
		double b;
		double aa;
		double bb;
		int n;

		n = 100;
		a = ((double)i - 0) / (X_IMG) * (fractol->amp) - fractol->x_offset;
		b = ((double)j - 0) / (Y_IMG) * (fractol->amp) - fractol->y_offset;
		while (--n > 0)
		{

			aa = a * a - b * b+ ac;
			bb = 2 * a * b + bc;
			if (fabs(aa * aa + bb * bb) > 4)
				return(n);
			a = aa;
			b = bb;
		}
		return (n);
	}

void	j(t_fractol_info *fractol)
{
		int i;
		int j;
		int n;

		i = 0;
		while (i < X_IMG)
		{
			j = 0;
			while (j < Y_IMG)
			{
				n = nbr_itr(i, j, fractol, fractol->ac, fractol->bc);
				pixel_in_img(fractol->img_string, i, j, rainbow((double)n / 100));
				// pixel_in_img(fractol->img_string, i + 1, j, rainbow((double)n / 100));
				// pixel_in_img(fractol->img_string, i, j + 1, rainbow((double)n / 100));
				// pixel_in_img(fractol->img_string, i + 1, j + 1, rainbow((double)n / 100));
				j += 1;
			}
			i += 1;
		}
		mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,fractol->img_ptr, 0/*X_INSTR*/, 0);
	}

int		mouse_move(int x, int y, void *param)
{
	t_fractol_info	*fractol;

	fractol = (t_fractol_info *)param;
	fractol->ac = ((double)x - 0) / (X_IMG) * (fractol->amp) - fractol->x_offset;
	fractol->bc = ((double)y - 0) / (Y_IMG) * (fractol->amp) - fractol->y_offset;
	j(fractol);
	return (1);
}

int 	key_press(int keycode, t_fractol_info *fractol)
{
	if (keycode == ARROW_UP)
		fractol->y_offset -= fractol->amp /10;
	else if (keycode == ARROW_DOWN)
		fractol->y_offset += fractol->amp /10;
	else if (keycode == ARROW_LEFT)
		fractol->x_offset -= fractol->amp /10;
	else if (keycode == ARROW_RIGHT)
		fractol->x_offset += fractol->amp /10;
	else if (keycode == MAIN_PAD_SPACE)
		reset_param(fractol);
	else if (keycode == NUMBER_PAD_PLUS)
		zoom(fractol, X_IMG / 2, Y_IMG /2, 1);
	else if (keycode == NUMBER_PAD_MINUS)
		zoom(fractol, X_IMG / 2, Y_IMG /2, 0);
	else if (keycode == MAIN_PAD_ESC)
		exit(0);
	fractol->fun_ptr(fractol);
	return(0);
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
