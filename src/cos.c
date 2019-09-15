/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:07:45 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/14 12:55:43 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		nbr_itr(int i, int j, t_fractol_info *fractol)
{
	double	x;
	double	y;
	double	aa;
	double	bb;
	int		n;

	fractol->ac = 0;
	fractol->bc = 0;
	n = 50;
	x = ((double)i - 0) / (X_IMG) * (fractol->amp) - fractol->x_offset;
	y = ((double)j - 0) / (Y_IMG) * (fractol->amp) - fractol->y_offset;
	while (--n > 0)
	{
		aa = pow(fractol->ac, 4) + pow(fractol->bc, 4) - 6 * pow(fractol->ac, 2) * pow(fractol->bc, 2) + x;
		bb = 4 * pow(fractol->ac, 3) * fractol->bc - 4 * pow(fractol->bc, 3) * fractol->ac + y;
		// aa = pow(fractol->ac, 3) - 3 * fractol->ac * pow(fractol->bc, 2) + x;
		// bb = 3 * fractol->bc * pow(fractol->ac, 2) - pow(fractol->bc, 3) + y;
		if (fabs(aa * aa + bb * bb) > 4)
			return (n);
		fractol->ac = aa;
		fractol->bc = bb;
	}
	return (n);
}

void			fract_cos(t_fractol_info *fractol)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (i < X_IMG)
	{
		j = 0;
		while (j < Y_IMG)
		{
			n = nbr_itr(i, j, fractol);
			pixel_in_img(fractol->img_string, i,
							j, color((double)n / 50, fractol));
			j += 1;
		}
		i += 1;
	}
	mlx_put_image_to_window(fractol->mlx_ptr,
								fractol->win_ptr, fractol->img_ptr, 0, 0);
}
