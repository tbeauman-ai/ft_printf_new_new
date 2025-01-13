/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:41:21 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/13 19:03:46 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
    void    *ptr;
    int     ret;
    
    ptr = -9223372036854775808;
    printf("min\n");
    ret = printf("pf:%p\n", ptr);
    printf("ret:%d\n", ret);
    ret = ft_printf("ft:%p\n", ptr);
    printf("ret:%d\n\n", ret);

    ptr = 9223372036854775807;
    printf("max\n");
    ret = printf("pf:%p\n", ptr);
    printf("ret:%d\n", ret);
    ret = ft_printf("ft:%p\n", ptr);
    printf("ret:%d\n\n", ret);

    ptr = ULONG_MAX;
    printf("ulmax\n");
    ret = printf("pf:%p\n", ptr);
    printf("ret:%d\n", ret);
    ret = ft_printf("ft:%p\n", ptr);
    printf("ret:%d\n\n", ret);

    ptr = -ULONG_MAX;
    printf("-ulmax\n");
    ret = printf("pf:%p\n", ptr);
    printf("ret:%d\n", ret);
    ret = ft_printf("ft:%p\n", ptr);
    printf("ret:%d\n\n", ret);



    char    *s;

    s = NULL;
    // printf("%s\n", s);
    ft_printf("%s\n", s);

    int     d;

    d = -42715;
    ret = printf("%d\n", d);
    printf("ret:%d\n", ret);
    ret = ft_printf("%d\n", d);
    printf("ret:%d\n", ret);

    return (0);
}