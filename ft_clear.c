/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:00:06 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 13:00:07 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void    clear_struct(t_lst *head)
{
    free(head->length);
    free(head->specifier);
    free(head->text);
    free(head->wrong);
    free(head->width);
    free(head->precision);
    free(head->flags);
    free(head->color);
}

void        ft_clear(char *width, char *accur, char *flag)
{
    if (width)
        ft_strdel(&width);
    if (accur)
        ft_strdel(&accur);
    if (flag)
        ft_strdel(&flag);
}
