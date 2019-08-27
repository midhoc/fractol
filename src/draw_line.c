/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:38:01 by midounhocin       #+#    #+#             */
/*   Updated: 2019/08/26 20:14:41 by midounhocin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	draw_line_x(t_info p1, t_info p2, t_fractol_info *fractol)
{
	t_info	d;
	t_info	curr;
	int		yi;
	int		diff;

	curr.y = p1.y;
	curr.x = p1.x;
	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	yi = d.y < 0 ? -1 : 1;
	d.y = abs(d.y);
	diff = 2 * d.y - d.x;
	while (curr.x < p2.x)
	{
		pixel_in_img(fractol->img_string, curr.x, curr.y,
			WHITE);
		if (diff > 0)
		{
			curr.y += yi;
			diff = diff - 2 * d.x;
		}
		diff = diff + 2 * d.y;
		curr.x++;
	}
}

void	draw_line_y(t_info p1, t_info p2, t_fractol_info *fractol)
{
	t_info	d;
	t_info	curr;
	int		xi;
	int		diff;

	curr.x = p1.x;
	curr.y = p1.y;
	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	xi = d.x < 0 ? -1 : 1;
	d.x = abs(d.x);
	diff = 2 * d.x - d.y;
	while (curr.y < p2.y)
	{
		pixel_in_img(fractol->img_string, curr.x, curr.y,
			WHITE);
		if (diff > 0)
		{
			curr.x += xi;
			diff = diff - 2 * d.y;
		}
		diff = diff + 2 * d.x;
		curr.y++;
	}
}

void	draw_line(t_info p1, t_info p2, t_fractol_info *fractol)
{
	if (abs(p1.y - p2.y) < abs(p1.x - p2.x))
	{
		if (p1.x > p2.x)
			draw_line_x(p2, p1, fractol);
		else
			draw_line_x(p1, p2, fractol);
	}
	else
	{
		if (p1.y > p2.y)
			draw_line_y(p2, p1, fractol);
		else
			draw_line_y(p1, p2, fractol);
	}
}
