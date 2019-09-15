/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:42:25 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/13 23:30:53 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rainbow(double percentage)
{
	int	d;
	int	dr;

	dr = get_light(0, 1019, percentage) % 255;
	d = get_light(0, 1019, percentage) / 255;
	if (d == 0)
		return ((255 << 16) | (dr << 8) | 0);
	else if (d == 1)
		return (((255 - dr) << 16) | (255 << 8) | 0);
	else if (d == 2)
		return ((0 << 16) | (255 << 8) | dr);
	else if (d == 3)
		return ((0 << 16) | ((255 - dr) << 8) | 255);
	return (0);
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		b_w_color(double percentage)
{
	int		red;
	int		green;
	int		blue;

	red = get_light((BLACK >> 16) & 0xFF,
			(WHITE >> 16) & 0xFF, percentage);
	green = get_light((BLACK >> 8) & 0xFF,
			(WHITE >> 8) & 0xFF, percentage);
	blue = get_light(BLACK & 0xFF, WHITE & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int		color(double percentage, t_fractol_info *fractol)
{
	if (fractol->color_type == 1)
		return (rainbow(percentage));
	else
		return (b_w_color(percentage));
}
