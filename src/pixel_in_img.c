/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_in_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:37:00 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/13 23:37:09 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_in_img(char *image_string, int x, int y, int color)
{
	if (!(x < 0 || y < 0 || x > X_IMG - 1 || y > Y_IMG - 1))
	{
		image_string[4 * (x + y * X_IMG)] = color & 0xFF;
		image_string[4 * (x + y * X_IMG) + 1] = color >> 8 & 0xFF;
		image_string[4 * (x + y * X_IMG) + 2] = color >> 16 & 0xFF;
	}
}

void	reset_img(char *image_string)
{
	int i;

	i = -1;
	while (++i < SIZE_IMG)
		image_string[i] = 0;
}
