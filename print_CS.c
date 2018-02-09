/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_CS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:55:15 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 12:55:15 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int        C_min(wchar_t c, t_lst *run)
{
    int i;
    int h;
    int res;

    i = 0;
    res = unic_c(c);
    h = run->width->number - length_c(c);
    while (i < h)
    {
        ft_putchar((run->flags->zero) ? '0' : ' ');
        i++;
    }
    res += i;
    return (res);
}

int        C_n_min(wchar_t c, t_lst *run)
{
    int i;
    int h;
    int res;

    i = 0;
    h = run->width->number - length_c(c);
    while (i < h)
    {
        ft_putchar((run->flags->zero) ? '0' : ' ');
        i++;
    }
    res = unic_c(c);
    res += i;
    return (res);
}

int        S_min(wchar_t *s, t_lst *run)
{
    int i;
    int h;
    int res;

    i = 0;
    res = 0;
    if (run->precision->dot_number >= 0)
        res = unic_sn(s, run->precision->dot_number);
    else
        res = unic_s(s);
    if (run->precision->dot_number >= 0)
        h = run->width->number - run->precision->dot_number;
    else
        h = run->width->number - length_s(s);
    while (i < h)
    {
        ft_putchar(' ');
        i++;
    }
    res += i;
    return (res);
}

int        S_n_min(wchar_t *s, t_lst *run)
{
    int i;
    int h;
    int res;

    i = 0;
    res = 0;
    if (run->precision->dot_number >= 0 || run->precision->fl)
        h = run->width->number - ulen_lim(run->precision->dot_number, s);
    else if (MB_CUR_MAX > 1)
        h = run->width->number - length_s(s);
    else
        h = run->width->number - length_s_one(s);
    while (i < h)
    {
        ft_putchar((run->flags->zero) ? '0' : ' ');
        i++;
    }
    if (run->precision->dot_number >= 0)
        res = unic_sn(s, run->precision->dot_number);
    else if (!run->precision->fl)
        res = unic_s(s);
    res += i;
    return (res);
}

int         char_CS(va_list args, t_lst *run)
{
    wchar_t c;
    wchar_t *s;

    if ((run->specifier->c && run->length->l) || run->specifier->C)
    {
        c = (va_arg(args, wint_t));
        if (run->flags->minus)
            return (C_min(c, run));
        else
            return (C_n_min(c, run));
    }
    else if ((run->specifier->s == 1 && run->length->l) || run->specifier->S)
    {
        s = (va_arg(args, wchar_t*));
        if (s == NULL)
            s = L"(null)";
        if (run->flags->minus)
            return (S_min(s, run));
        else
            return (S_n_min(s, run));
    }
    return (1);
}
