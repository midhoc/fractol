/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midounhocine <midounhocine@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:46:08 by midounhocin       #+#    #+#             */
/*   Updated: 2019/08/27 11:03:52 by midounhocin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int  nbr_itr(int i, int j, t_fractol_info *fractol, double ac, double bc)
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

void    j(t_fractol_info *fractol)
{
    int i;
    int j;
    int n;
    double ac = -0.4;
    double bc = 0.6;

    i = -1;
    while (++i < X_IMG)
    {
        j = -1;
        while (++j < Y_IMG)
        {
            n = nbr_itr(i, j, fractol, ac, bc);
            pixel_in_img(fractol->img_string, i, j, rainbow(1 - (double)n / 100));
        }
    }
}