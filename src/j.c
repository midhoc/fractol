/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:46:08 by midounhocin       #+#    #+#             */
/*   Updated: 2019/09/12 18:22:42 by hmidoun          ###   ########.fr       */
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
		a = ((double)i - 0) / (X_IMG) * (2 * fractol->amp) + (-fractol->amp);
		b = ((double)j - 0) / (Y_IMG) * (2 * fractol->amp) + (-fractol->amp);
		while (--n > 0)
		{

			aa = a * a - b * b+ ac;
			bb = 2 * a * b + bc;
			if (fabs(aa * aa + bb * bb) > 16)
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
	fractol->ac = ((double)x - 0) / (X_IMG) * (2 * fractol->amp) + (-fractol->amp);
	fractol->bc = ((double)y - 0) / (Y_IMG) * (2 * fractol->amp) + (-fractol->amp);
	j(fractol);
	return (1);
}

