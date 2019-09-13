/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:01:23 by midounhocin       #+#    #+#             */
/*   Updated: 2019/09/13 14:49:17 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rainbow(double percentage)
{
	int r = 0,g=0,b=0;
	int i=get_light(0, 1019, percentage);

	int d = i /255;
	int dr = i%255;
	if(d == 0)
	{
		r = 255;
		g = dr;
	}
	else if(d == 1)
	{
		g =255;
		r = 255- dr;
	}
	else if(d == 2)
	{
		g =255;
		b = dr;
	}
	else if(d == 3)
	{
		b =255;
		g = 255 - dr;
	}
	return ((r << 16) | (g << 8) | b);
}


int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(int start, int end, double percentage)
{
	int		red;
	int		green;
	int		blue;

	red = get_light((start>> 16) & 0xFF,
			(end >> 16) & 0xFF, percentage);
	green = get_light((start >> 8) & 0xFF,
			(end >> 8) & 0xFF, percentage);
	blue = get_light(start & 0xFF, end & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}


static	int	nbr_itr(int i, int j, t_fractol_info *fractol)
{
	double x;
	double y;
	double aa;
	double bb;
	int n;

	fractol->ac = 0;
	fractol->bc = 0;
	n = 100;
	x = ((double)i - 0) / (X_IMG) * (fractol->amp) - fractol->x_offset;
	y = ((double)j - 0) / (Y_IMG) * (fractol->amp) - fractol->y_offset;
	while (--n > 0)
	{

		aa =fractol->ac*fractol->ac- fractol->bc * fractol->bc + x;
		bb = 2 *fractol->ac* fractol->bc + y;
		if (fabs(aa * aa + bb * bb) > 4)
			return(n);
		fractol->ac = aa;
		fractol->bc = bb;
	}
	return (n);
}

void	m(t_fractol_info *fractol)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	while (++i < X_IMG)
	{
		j = -1;
		while (++j < Y_IMG)
		{
			n = nbr_itr(i, j, fractol);
			pixel_in_img(fractol->img_string, i, j, rainbow((double)n / 100));
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,fractol->img_ptr, 0, 0);
}
