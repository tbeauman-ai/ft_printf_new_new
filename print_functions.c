/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:06:47 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/13 19:13:57 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_c(va_list *ap)
{
    int c;

    c = va_arg(*ap, int);
    ft_putchar_fd(c, 1);
    return (1);
}

int print_s(va_list *ap)
{
    char *s;

    s = va_arg(*ap, char *);
    if (!s)
    {
        ft_putstr_fd("(null)", 1);
        return (6);
    }
    ft_putstr_fd(s, 1);
    return (ft_strlen(s));
}

int custom_putnbr_base(long p, int b)
{
    char *base;
    int ret;
    int neg;

    ret = 1;
    neg = 0;
    if (b == 0 || b >= 36)
        return (-1);
    if (b == 16 && p == (long)0x8000000000000000)
    {
        ft_putstr_fd("8000000000000000", 1);
        return (ft_strlen("8000000000000000"));
    }
    base = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (p < 0)
    {
        p = -p;
        ft_putchar_fd('-', 1);
        neg = 1;
    }
    if (p / b != 0)
        ret = 1 + custom_putnbr_base(p / b, b);
    ft_putchar_fd(base[p % b], 1);
    return (ret + neg);
}

int print_p(va_list *ap)
{
    long p;

    p = va_arg(*ap, long);
    if (!p)
    {
        ft_putstr_fd("(nil)", 1);
        return (5);
    }
    if ((unsigned long)p == 0xffffffffffffffff)
    {
        ft_putstr_fd("0xffffffffffffffff", 1);
        return (ft_strlen("0xffffffffffffffff"));
    }
    ft_putstr_fd("0x", 1);
    return (2 + custom_putnbr_base((unsigned long)p, 16));
}

int print_d(va_list *ap)
{
    int d;

    d = va_arg(*ap, int);
    return (custom_putnbr_base((int)d, 10));
}