/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:48:56 by dlytvyn           #+#    #+#             */
/*   Updated: 2018/02/09 16:56:18 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char		*num_di(va_list args, t_length *run, t_sp *spec)
{
	char	*res;

	if (run->z == 1)
		res = ft_itoa_base_pt(va_arg(args, size_t));
	else if (run->j == 1)
		res = ft_itoa_base_pt(va_arg(args, intmax_t));
	else if (run->ll)
		res = ft_itoa_base_pt(va_arg(args, long long int));
	else if (run->l == 1)
		res = ft_itoa_base_pt(va_arg(args, long int));
	else if (run->h == 1)
		res = ft_itoa_base_pt((short int)va_arg(args, int));
	else if (run->hh == 1)
		res = ft_itoa_base_pt((signed char)va_arg(args, int));
	else if (run->cl == 1)
		res = ft_itoa_base(va_arg(args, int64_t), search_base(spec), spec);
	else
		res = ft_itoa_base_pt(va_arg(args, int));
	return (res);
}

char		*num_rest(va_list args, t_length *run, t_sp *spec)
{
	char	*res;

	if (run->z == 1)
		res = ft_itoa_base(va_arg(args, size_t), search_base(spec), spec);
	else if (run->j == 1)
		res = ft_itoa_base(va_arg(args, uintmax_t), search_base(spec), spec);
	else if (run->ll)
		res = ft_itoa_base(va_arg(args, unsigned long long int), search_base(spec), spec);
	else if (run->l == 1)
		res = ft_itoa_base((size_t)va_arg(args, unsigned long int), search_base(spec), spec);
	else if (run->h == 1)
		res = ft_itoa_base((unsigned short int)va_arg(args, int), search_base(spec), spec);
	else if (run->hh == 1)
		res = ft_itoa_base((unsigned char)va_arg(args, int), search_base(spec), spec);
	else if (run->cl == 1)
		res = ft_itoa_base(va_arg(args, int64_t), search_base(spec), spec);
	else
		res = ft_itoa_base(va_arg(args, unsigned int), search_base(spec), spec);
	return (res);
}

char		*num_dou(va_list args, t_sp *spec, t_flags *flag)
{
	char	*res;

	res = NULL;
	if (spec->cd)
		res = ft_itoa_base_pt(va_arg(args, long int));
	else if (spec->co && flag->cell)
		res = ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec);
	else if (spec->co)
		res = ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec);
	else if (spec->cu)
		res = ft_itoa_base(va_arg(args, unsigned long int), search_base(spec), spec);
	return (res);
}

char		*ft_format(char *form, t_lst *run, va_list args)
{
	int	thing;

	thing = 0;
	while (*form && *form != '%')
	{
		if (*form == '{')
			form = get_color(form, run->color);
		if (*form && *form != '%')
		{
			run->text = ft_realloc(run->text, ft_strlen(run->text) + 1);
			run->text = ft_strncat(run->text, form, 1);
			form++;
		}
	}
	if (*form == '%')
		form++;
	while (*form && thing == 0 && *form != '\n')
	{
		form = ft_get_flags(form, run->flags);
		form = ft_gt_wd(form, run->width, args, run->flags);
		form = ft_get_precision(form, run->pr, args);
		form = ft_get_length(form, run->length);
		thing = ft_get_specifier(form, run->sp);
		if (thing == 0)
			form = ft_wrong(form, run);
		form++;
		if (run->wrong[0])
			break ;
	}
	return (form);
}
