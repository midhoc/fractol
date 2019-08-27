/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_in_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 06:09:46 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/26 18:44:56 by midounhocin      ###   ########.fr       */
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
