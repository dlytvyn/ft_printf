/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:03:22 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 13:03:23 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		search_base(t_specifier *spec)
{
    if (spec->d || spec->i || spec->u || spec->D || spec->U)
        return (10);
    else if (spec->o || spec->O)
        return (8);
    else if (spec->x == 1 || spec->X == 1)
        return (16);
    else if (spec->b)
        return (2);
    else
        return (10);
}