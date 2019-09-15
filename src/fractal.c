/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:07:45 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/15 20:20:17 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mand3(int i, int j, t_fractol_info *fractol)
{
	double	x;
	double	y;
	double	aa;
	double	bb;
	int		n;

	fractol->ac = 0;
	fractol->bc = 0;
	n = fractol->max_itr;
	x = ((double)i - 0) / (X_IMG) * (fractol->amp) - fractol->x_offset;
	y = ((double)j - 0) / (Y_IMG) * (fractol->amp) - fractol->y_offset;
	while (--n > 0)
	{
		aa = fractol->ac * fractol->ac * fractol->ac - 3 * fractol->ac * fractol->bc * fractol->bc + x;
		bb = 3 * fractol->bc * fractol->ac * fractol->ac- fractol->bc * fractol->bc * fractol->bc + y;
		if (fabs(aa * aa + bb * bb) > 4)
			return (n);
		fractol->ac = aa;
		fractol->bc = bb;
	}
	return (n);
}

int		julia(int i, int j, t_fractol_info *fractol)
{
	double	a;
	double	b;
	double	aa;
	double	bb;
	int		n;

	n = fractol->max_itr;
	a = ((double)i - 0) / (X_IMG) * (fractol->amp) - fractol->x_offset;
	b = ((double)j - 0) / (Y_IMG) * (fractol->amp) - fractol->y_offset;
	while (--n > 0)
	{
		aa = a * a - b * b + fractol->ac;
		bb = 2 * a * b + fractol->bc;
		if (fabs(aa * aa + bb * bb) > 4)
			return (n);
		a = aa;
		b = bb;
	}
	return (n);
}

int		mand(int i, int j, t_fractol_info *fractol)
{
	double	x;
	double	y;
	double	aa;
	double	bb;
	int		n;

	fractol->ac = 0;
	fractol->bc = 0;
	n = fractol->max_itr;
	x = ((double)i - 0) / (X_IMG) * (fractol->amp) - fractol->x_offset;
	y = ((double)j - 0) / (Y_IMG) * (fractol->amp) - fractol->y_offset;
	while (--n > 0)
	{
		aa = fractol->ac * fractol->ac - fractol->bc * fractol->bc + x;
		bb = 2 * fractol->ac * fractol->bc + y;
		if (fabs(aa * aa + bb * bb) > 4)
			return (n);
		fractol->ac = aa;
		fractol->bc = bb;
	}
	return (n);
}

void		draw(t_fractol_info *fractol)
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
			n = fractol->fun_ptr(i, j, fractol);
			pixel_in_img(fractol->img_string, i, j,
							color((double)n / fractol->max_itr, fractol));
			j += 1;
		}
		i += 1;
	}
	mlx_put_image_to_window(fractol->mlx_ptr,
							fractol->win_ptr, fractol->img_ptr, 0, 0);
}
