/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:34:58 by dlytvyn           #+#    #+#             */
/*   Updated: 2017/12/21 13:34:59 by dlytvyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
#define PRINT_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include <locale.h>

#define mask3 4034953344

typedef struct 		s_flags
{
	int				minus;
	int				plus;
	int				space;
	int				cell;
	int				zero;
}					t_flags;

typedef struct		s_width
{
    int 			number;
}					t_width;

typedef struct			s_precision
{
	int                 dot_number;
	int 				fl;
    int                 yes;
}						t_precision;

typedef struct			s_length
{
	int					l;
	int					L;
	int					hh;
	int					h;
	int					ll;
	int					j;
	int					z;
}						t_length;

typedef struct          s_color
{
    int                 re;
    int                 gre;
    int                 yel;
    int                 blu;
    int                 mag;
    int                 cya;
	int 				whi;
    int                 rese;
}                       t_color;

typedef struct			s_specifier
{
	int					s;
	int					S;
	int					p;
	int					d;
	int					D;
	int					i;
	int					o;
	int					O;
	int					u;
	int					U;
	int					x;
	int					X;
	int					c;
	int					C;
    int                 b;
	int					proc;
}						t_specifier;

typedef struct			s_lst
{
	t_flags			*flags;
	t_width			*width;
	t_precision		*precision;
	t_length		*length;
	t_specifier		*specifier;
    t_color         *color;
	char			*text;
	char 			*wrong;
}						t_lst;


const char	*ft_get_flags(const char *form, t_flags *run);
const char	*ft_get_width(const char *form, t_width *run, va_list args, t_flags *f);
const char	*ft_get_precision(const char *form, t_precision *run, va_list args);
const char	*ft_get_length(const char *form, t_length *run);
const char	*get_color(const char *form, t_color *run);
int			ft_get_specifier(const char *form, t_specifier *run);

t_flags		*zero_to_flags(t_flags *run);
t_width		*zero_to_width(t_width *run);
t_precision	*zero_to_precision(t_precision *run);
t_length	*zero_to_length(t_length *run);
t_specifier	*zero_to_specifier(t_specifier *run);
t_color     *zero_to_color(t_color *run);

char		*ft_itoa_base(size_t num, int base, t_specifier *spec);
char		*ft_itoa_base_pt(ssize_t n);
char		*ft_realloc_cat(char *array, char *source);
const char	*ft_wrong(const char *form, t_lst *run);

int			ft_printf(const char *format, ...);
void		*ft_realloc(void *array, size_t size);
int			search_base(t_specifier *spec);

int     	unic_sn(wchar_t *array, int num);
int     	unic_s(wchar_t *array);
int			unic_c(wchar_t ar);

int     	length_s(wchar_t *ar);
int     	length_c(wchar_t ar);
int     	length_s_one(wchar_t *ar);
int     	ulen_lim(int num, wchar_t *ar);
int     	ft_len(char *s);

int		is_num(t_specifier *spec, t_length *len);
int         type(t_lst *run);
int         ft_text(t_lst *run);
int         ft_numeric(t_lst *run);
int     ft_uni_type(t_specifier *spec, t_length *len);
char		*num_di(va_list args, t_length *run, t_specifier *spec);
char		*num_rest(va_list args, t_length *run, t_specifier *spec);
char		*num_DOU(va_list args, t_specifier *spec, t_flags *flag);
const char	*ft_format(const char *form, t_lst *run, va_list args);
char		*parse_flags(intmax_t num, t_lst *run, char *res);
char		*parse_accuracy(t_lst *run, char *num);
char		*parse_width(t_lst *run, char *num, char *accur, char *flag);
int         ft_puttext_min(char *fl_ac, char *width, char *num, t_lst *run);
int         ft_puttext_zero(char *fl_wd, char *accur, char *num, t_lst *run);
int         ft_puttext_min_p(char *fl_ac, char *width, char *num, t_lst *run);
int         ft_puttext(char *wd_fl, char *accur, char *num, t_lst *run);
char		*pr_char(t_lst *run, char *num);
char		*ft_char_type(va_list args, t_specifier *spec, t_length *length);
int        C_min(wchar_t c, t_lst *run);
int        C_n_min(wchar_t c, t_lst *run);
int        S_min(wchar_t *s, t_lst *run);
int        S_n_min(wchar_t *s, t_lst *run);
int         char_CS(va_list args, t_lst *run);
ssize_t		ft_atoi_n(const char *str);
void	*ft_realloc(void *array, size_t size);
t_lst	*ft_newlst(void);
void    clear_struct(t_lst *head);
void        ft_clear(char *width, char *accur, char *flag);
char    *ft_pointer(char *res, va_list args, t_lst *head);
int     ft_len(char *s);
int		search_base(t_specifier *spec);
void    print_color(t_color *col);
void    ft_reset(t_color *col);

#endif