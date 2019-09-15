/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:46:08 by midounhocin       #+#    #+#             */
/*   Updated: 2019/09/13 23:35:19 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		nbr_itr(int i, int j, t_fractol_info *fractol)
{
	double	a;
	double	b;
	double	aa;
	double	bb;
	int		n;

	n = 100;
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

void			julia(t_fractol_info *fractol)
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
			n = nbr_itr(i, j, fractol);
			pixel_in_img(fractol->img_string, i, j,
							color((double)n / 100, fractol));
			j += 1;
		}
		i += 1;
	}
	mlx_put_image_to_window(fractol->mlx_ptr,
							fractol->win_ptr, fractol->img_ptr, 0, 0);
}
