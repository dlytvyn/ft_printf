/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:30:00 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/01/18 16:30:01 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		is_num(t_specifier *spec, t_length *len)
{
    if (spec->d == 1|| spec->i == 1)
        return (1);
    else if (spec->o ==1|| spec->u == 1 || spec->x == 1 || spec->X == 1 || spec->b)
        return (2);
    else if (spec->D == 1 || spec->O == 1 || spec->U == 1)
        return (3);
    else if ((spec->c == 1 || spec->s == 1) && !len->l)
        return (4);
    else if (spec->C == 1 || spec->S == 1)
        return (7);
    else if ((spec->c == 1 || spec->s == 1) && len->l)
        return (7);
    else if (spec->p == 1)
        return (5);
    else if (spec->proc == 1)
        return (6);
    else
        return (0);
}

int         type(t_lst *run)
{
    t_specifier *spec;

    spec = run->specifier;

    if (is_num(spec, run->length) == 4 || is_num(spec, run->length) == 6)
        return (1);
    else if (is_num(spec, run->length) == 7 || is_num(spec, run->length) == 0)
        return (1);
    else
        return (0);
}

int         ft_text(t_lst *run)
{
    t_specifier *spec;

    spec = run->specifier;
    if (spec->S || spec->s)
        return (1);
    else
        return (0);
}

int         ft_numeric(t_lst *run)
{
    t_specifier     *spec;

    spec = run->specifier;
    if (spec->x || spec->X || spec->d || spec->D || spec->i || spec->u || spec->U || spec->o || spec->O)
        return (1);
    else
        return (0);
}

int     ft_uni_type(t_specifier *spec, t_length *len)
{
    if (spec->C || (    spec->c && len->l))
        return (1);
    else if (spec->S || (spec->s && len->l))
        return (1);
    else
        return (0);
}
