/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:57:36 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 11:57:37 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int        if_minus(t_lst *run, char *num)
{
    char	*width;
    char    *accur;
    char    *flag;
    int     len;

    flag = parse_flags(ft_atoi_n(num), run, num);
    accur = parse_accuracy(run, num);
    if (ft_atoi_n(num) < 0)
        num = num + 1;
    width = parse_width(run, num, accur, flag);
    len = ft_puttext_min(ft_realloc_cat(flag, accur), width, num, run);
    return (len);
}

static int        if_not_minus(t_lst *run, char *num)
{
    char	*width;
    char    *accur;
    char    *flag;
    int     len;

    len = 0;
    accur = parse_accuracy(run, num);
    flag = parse_flags(ft_atoi_n(num), run, num);
    if ((is_num(run->specifier, run->length) == 1 || run->specifier->D) && ft_atoi_n(num) < 0)
        num = num + 1;
    width = parse_width(run, num, accur, flag);
    if (run->flags->zero)
    {
        if (!run->specifier->p)
            len = ft_puttext_zero(ft_realloc_cat(flag, width), accur, num, run);
        else
            len = ft_puttext_min_p(ft_realloc_cat(flag, accur), width, num, run);
    }
    else if (!run->specifier->p)
        len = ft_puttext(ft_realloc_cat(width, flag), accur, num, run);
    else
    {
        if (run->flags->minus || run->precision->dot_number > run->width->number)
            len = ft_puttext_min_p(ft_realloc_cat(flag, accur), width, num, run);
        else
            len = ft_puttext_min_p(ft_realloc_cat(width, flag), accur, num, run);
    }
    return (len);
}

static int		ft_align(t_lst *run, char *num)
{
    if (ft_text(run) && run->precision->fl)
        num = pr_char(run, num);
    if (run->specifier->s && run->precision->fl)
    {
        if (run->precision->yes == 0 || run->precision->dot_number == 0)
        {
            free(num);
            num = ft_strdup("");
        }
    }
    if (ft_atoi(num) == 0 && run->precision->fl && ft_numeric(run))
    {
        free(num);
        num = ft_strdup("");
    }
    if (run->flags->minus)
        return (if_minus(run, num));
    else
        return (if_not_minus(run, num));
}

static int		ft_typing(va_list args, t_lst *head)
{
    char	*res;
    int		size;

    res = NULL;
    size  = 0;
    ft_reset(head->color);
    if (head->text[0])
        write(1, head->text, ft_strlen(head->text));
    print_color(head->color);
    if (is_num(head->specifier, head->length) == 1)
        res = num_di(args, head->length, head->specifier);
    else if (is_num(head->specifier, head->length) == 2)
        res = num_rest(args, head->length, head->specifier);
    else if (is_num(head->specifier, head->length) == 3)
        res = num_DOU(args, head->specifier, head->flags);
    else if (is_num(head->specifier, head->length) == 4)
        res = ft_char_type(args, head->specifier, head->length);
    else if (is_num(head->specifier, head->length) == 5)
        res = ft_pointer(res, args, head);
    else if (is_num(head->specifier, head->length) == 6)
        res = ft_strdup("%");
    else if (is_num(head->specifier, head->length) == 7)
        size += char_CS(args, head);
    else if (head->wrong[0])
        res = ft_strdup(head->wrong);
    else
        return (ft_strlen(head->text));
    if ((ft_uni_type(head->specifier, head->length) == 0 || MB_CUR_MAX <= 1) && res)
        size += ft_align(head, res);
    size += ft_len(head->text);
    (head->specifier->proc) ? free(res) : 1;
    (head->wrong[0]) ? free(res) : 1;
    (ft_numeric(head) == 1 || head->specifier->p) ? free(res) : 1;
    (head->specifier->s && !head->length->l) ? free(res) : 1;
    return (size);
}

int		ft_printf(const char *format, ...)
{
    va_list			args;
    const char		*form;
    t_lst			*head;
    int				num;

    num = 0;
    head = NULL;
    va_start(args, format);
    form = format;
    while (*form)
    {
        head = ft_newlst();
        form = ft_format(form, head, args);
        num += ft_typing(args, head);
        clear_struct(head);
        free(head);
    }
    va_end(args);
    return (num);
}