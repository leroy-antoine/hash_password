/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_sqrt.c
*/

#include "my.h"

double my_sqrt(double nb)
{
    double low = 0;
    double high = nb;
    double mid;
    double epsilon = 0.000001;

    if (nb < 0)
        return -1;
    while (high - low > epsilon) {
        mid = (low + high) / 2;
        if (mid * mid > nb)
            high = mid;
        else
            low = mid;
    }
    return mid;
}
