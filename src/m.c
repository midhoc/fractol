/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:01:23 by midounhocin       #+#    #+#             */
/*   Updated: 2019/08/27 15:07:22 by midounhocin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     rainbow(double percentage)
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
    // else if(d == 4)
    // {
    //     b =255;
    //     r = dr;
    // }
    // else if(d == 5)
    // {
    //     b =255 - dr;
    //     r = 255;
    // }
    // while(i > 0){
    // if ( r >= 255 && g < 255 && b <= 0 )
    //   {
    //   g+=10;
    //   }
    // if ( g >= 255 && r > 0 && b <= 0 )
    //   {
    //   r-=10;
    //   if(r<0) r=0;
    //   }
    // if ( g >= 255 && b < 255 && r <= 0 )
    //   {
    //   b+=10;
    //   }
    // if ( b >= 255 && g > 0 && r <= 0 )
    //   {
    //   g-=10;
    //   }
    // if ( b >= 255 && r < 255 && g <= 0 )
    //   {
    //   r+=10;
    //   }
    // if ( r >= 255 && b > 0 && g <= 0 )
    //   {
    //   b-=10;
    //   }
    //   i-=10;
    // }
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


static int  nbr_itr(int i, int j, t_fractol_info *fractol)
{
    double x;
    double y;
    double a;
    double b;
    double aa;
    double bb;
    int n;

    a = 0;
    b = 0;
    n = 100;
    x = ((double)i - 0) / (X_IMG) * (2 * fractol->amp) + (-fractol->amp);
    y = ((double)j - 0) / (Y_IMG) * (2 * fractol->amp) + (-fractol->amp);
    while (--n > 0)
    {
        
        aa = a * a - b * b+ x;
        bb = 2 * a * b + y;
        if (fabs(aa * aa + bb * bb) > 100)
            return(n);
        a = aa;
        b = bb;
    }
    return (n);
}

void    m(t_fractol_info *fractol)
{
    int i;
    int j;
    int n;

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
}