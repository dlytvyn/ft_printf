/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:59:12 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 12:59:12 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

t_lst	*ft_newlst(void)
{
    t_lst	*elem;

    elem = (t_lst*)malloc(sizeof(t_lst));
    elem->flags = (t_flags*)malloc(sizeof(t_flags));
    elem->width = (t_width*)malloc(sizeof(t_width));
    elem->precision = (t_precision*)malloc(sizeof(t_precision));
    elem->length = (t_length*)malloc(sizeof(t_length));
    elem->specifier = (t_specifier*)malloc(sizeof(t_specifier));
    elem->color = (t_color*)malloc(sizeof(t_color));
    elem->flags = zero_to_flags(elem->flags);
    elem->width = zero_to_width(elem->width);
    elem->precision = zero_to_precision(elem->precision);
    elem->length = zero_to_length(elem->length);
    elem->specifier = zero_to_specifier(elem->specifier);
    elem->color = zero_to_color(elem->color);
    elem->text = ft_strdup("");
    elem->wrong = ft_strdup("");
    return (elem);
}
