/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:57:36 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:40:50 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int		if_minus(t_lst *run, char *num)
{
	char	*width;
	char	*accur;
	char	*flag;
	int		len;

	flag = parse_flags(ft_atoi_n(num), run, num);
	accur = parse_accuracy(run, num);
	if (ft_atoi_n(num) < 0)
		num = num + 1;
	width = parse_width(run, num, accur, flag);
	len = ft_text_m(ft_realloc_cat(flag, accur), width, num, run);
	return (len);
}

int 			if_n_min_add(t_lst *run, char *num)
{
	char	*width;
	char	*accur;
	char	*flag;
	int		len;

	accur = parse_accuracy(run, num);
	flag = parse_flags(ft_atoi_n(num), run, num);
	width = parse_width(run, num, accur, flag);
	if (run->flags->minus || run->pr->dot_number > run->width->number)
		len = ft_pt_min_p(ft_realloc_cat(flag, accur), width, num, run);
	else
		len = ft_pt_min_p(ft_realloc_cat(width, flag), accur, num, run);
	return (len);
}

static int		if_not_minus(t_lst *run, char *num)
{
	char	*width;
	char	*accur;
	char	*flag;
	int		len;

	len = 0;
	accur = parse_accuracy(run, num);
	flag = parse_flags(ft_atoi_n(num), run, num);
	if ((is_num(run->sp, run->length) == 1
		|| run->sp->cd) && ft_atoi_n(num) < 0)
		num = num + 1;
	width = parse_width(run, num, accur, flag);
	if (run->flags->zero)
	{
		if (!run->sp->p)
			len = ft_pt_zero(ft_realloc_cat(flag, width), accur, num, run);
		else
			len = ft_pt_min_p(ft_realloc_cat(flag, accur), width, num, run);
	}
	else if (!run->sp->p)
		len = ft_puttext(ft_realloc_cat(width, flag), accur, num, run);
	else
		len = if_n_min_add(run, num);
	return (len);
}

static int		ft_align(t_lst *run, char *num)
{
	if (ft_text(run) && run->pr->fl)
		num = pr_char(run, num);
	if (run->sp->s && run->pr->fl)
	{
		if (run->pr->yes == 0 || run->pr->dot_number == 0)
		{
			free(num);
			num = ft_strdup("");
		}
	}
	if (ft_atoi(num) == 0 && run->pr->fl && ft_numeric(run))
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
	size = 0;
	ft_reset(head->color);
	if (head->text[0])
		write(1, head->text, ft_strlen(head->text));
	print_color(head->color);
	if (is_num(head->sp, head->length) == 1)
		res = num_di(args, head->length, head->sp);
	else if (is_num(head->sp, head->length) == 2)
		res = num_rest(args, head->length, head->sp);
	else if (is_num(head->sp, head->length) == 3)
		res = num_dou(args, head->sp, head->flags);
	else if (is_num(head->sp, head->length) == 4)
		res = ft_char_type(args, head->sp, head->length);
	else if (is_num(head->sp, head->length) == 5)
		res = ft_pointer(res, args, head);
	else if (is_num(head->sp, head->length) == 6)
		res = ft_strdup("%");
	else if (is_num(head->sp, head->length) == 7)
		size += char_cs(args, head);
	else if (head->wrong[0])
		res = ft_strdup(head->wrong);
	else
		return (ft_strlen(head->text));
	if ((ft_uni_type(head->sp, head->length) == 0 || MB_CUR_MAX <= 1) && res)
		size += ft_align(head, res);
	size += ft_len(head->text);
	(head->sp->proc) ? free(res) : 1;
	(head->wrong[0]) ? free(res) : 1;
	(ft_numeric(head) == 1 || head->sp->p) ? free(res) : 1;
	(head->sp->s && !head->length->l) ? free(res) : 1;
	return (size);
}

int				ft_printf(const char *format, ...)
{
	va_list			args;
	char			*form;
	t_lst			*head;
	int				num;

	num = 0;
	head = NULL;
	va_start(args, format);
	form = (char*)format;
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
