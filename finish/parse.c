/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:50:28 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 12:50:28 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char		*parse_flags(intmax_t num, t_lst *run, char *res)
{
    char	*space;

    space = NULL;
    if (run->flags->plus && num >= 0 && (run->specifier->d || run->specifier->i))
    {
        space = ft_strdup("+");
        return (space);
    }
    else if (run->flags->space && num >= 0 && is_num(run->specifier, run->length) == 1)
    {
        space = ft_strdup(" ");
        return (space);
    }
    else if (run->flags->cell)
    {
        space = (run->specifier->o && res[0] != '0') ? ft_strdup("0") : space;
        space = (run->specifier->O && res[0] != '0') ? ft_strdup("0") : space;
        space = (run->specifier->x == 1 && num != 0) ? ft_strdup("0x") : space;
        space = (run->specifier->X == 1 && num != 0) ? ft_strdup("0X") : space;
        return (space);
    }
    else if (run->specifier->p)
        space = ft_strdup("0x");
    if (num < 0 && (run->specifier->d || run->specifier->i || run->specifier->D))
        space = ft_strdup("-");
    return (space);
}

char		*parse_accuracy(t_lst *run, char *num)
{
    int		ac;
    int 	size;
    int 	number;
    char	*temp;

    temp = NULL;
    if (run->precision->dot_number >= 0 && is_num(run->specifier, run->length) != 4 && !run->specifier->proc)
    {
        if (run->precision->dot_number > 0)
        {
            ac = run->precision->dot_number;
            size = ft_strlen(num);
            ((run->specifier->o || run->specifier->O) && run->precision->dot_number >= 0 && run->flags->cell) ? size++ : 1;
            number = ft_atoi(num);
            size = (number >= 0) ? size : size - 1;
            if (ac - size > 0)
            {
                temp = ft_strnew(ac - size);
                temp = ft_memset(temp, '0', ac - size);
            }
        }
    }
    return (temp);
}

char		*parse_width(t_lst *run, char *num, char *accur, char *flag)
{
    int 	width;
    char 	*temp;
    int     len;

    temp = NULL;
    len = (num[0] == '\0' && run->specifier->c) ? 1 : ft_len(num);
    if (run->width->number >= 0)
    {
        width = run->width->number;
        width = width - (len + ft_len(accur) + ft_len(flag));
        if (width > 0)
        {
            temp = ft_strnew(width);
            temp = ft_memset(temp, (run->flags->zero && !run->flags->minus && (!run->precision->fl || run->precision->dot_number < 0 || type(run))) ? '0' : ' ', width);
        }
    }
    return (temp);
}
