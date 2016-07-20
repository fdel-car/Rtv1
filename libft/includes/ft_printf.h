/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:01:22 by fdel-car          #+#    #+#             */
/*   Updated: 2016/06/23 14:45:16 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ATT __attribute__((format(printf,1,2)))
# define FT_P int ft_printf(char const *format, ...)ATT

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct	s_print
{
	int			l;
	int			j;
	int			f;
	int			w;
	int			p;
	int			i;
	char		c;
	int			inv;
	int			ret;
	int			neg;
	int			fl_s;
	int			temp;
	int			temp2;
	int			temp3;
	int			larg;
	int			flag;
	int			sign;
	int			hash;
	char		s[256];
	char		*str;
	wchar_t		*wide;
	int			space;
	int			s_wide;
	int			ret_err;
	int			fl_right;
}				t_print;

typedef struct	s_handle
{
	int			(*handle_fonc) (const char *, va_list, t_print *);
	char		key;
}				t_handle;

FT_P;
int				ft_wstrlen(wchar_t const *s);
int				ft_isdigit(int c);
int				ft_putchar(unsigned int c);
int				ft_putwchar(unsigned int c, int lc);
void			ft_putstr(const char *str);
int				ft_putnstr(const char *str, size_t n);
int				ft_putwstr(const wchar_t *s, int l);
void			ft_strclr(char *s);
void			ft_putnbr(long long int n);
void			ft_putunbr(unsigned long long int n);
void			ft_swap(int *a, int *b);
int				ft_string(char const *fl, va_list ap, t_print *gl);
int				ft_widestring(char const *fl, va_list ap, t_print *gl);
int				ft_unsigned(char const *fl, va_list ap, t_print *gl);
int				ft_uns_long(char const *fl, va_list ap, t_print *gl);
int				ft_int(char const *fl, va_list ap, t_print *gl);
int				ft_int_long(char const *fl, va_list ap, t_print *gl);
int				ft_int_char(char const *fl, va_list ap, t_print *gl);
int				ft_int_short(char const *fl, va_list ap, t_print *gl);
int				ft_char(char const *fl, va_list ap, t_print *gl);
int				ft_widechar(char const *fl, va_list ap, t_print *gl);
int				ft_precision_str(char const *fl, va_list ap, t_print *gl);
int				ft_width_str(char const *fl, va_list ap, t_print *gl);
int				ft_flags_str(char const *fl, va_list ap, t_print *gl);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *nptr);
int				ft_check_uni(int c);
int				ft_char_uns(unsigned long long int u);
int				ft_char_int(long long int u);
int				ft_flag_unsl(char const *fl, va_list ap, t_print *gl);
int				ft_flag_uns(char const *fl, va_list ap, t_print *gl);
int				ft_flag_int(char const *fl, va_list ap, t_print *gl, char t);
int				ft_unload_unss(t_print *gl, va_list ap);
int				ft_unload_unsc(t_print *gl, va_list ap);
int				ft_nousflag(va_list ap, t_print *gl);
int				ft_flag_unsc(char const *fl, va_list ap, t_print *gl);
int				ft_signfl(t_print *gl, long long int in);
int				unload3(t_print *gl, char t, long long int i);
int				unload5(t_print *gl, char t, va_list ap);
int				unload7(t_print *gl, char t, long long int i);
int				ft_unload_uns(t_print *gl, va_list ap);
int				ft_unload_fl(char const *fl, t_print *gl);
int				ft_unload_fl_hex(char const *fl, t_print *gl);
int				ft_octal(char const *fl, va_list ap, t_print *gl);
char			*ft_itoa_base(unsigned long long int nbr, int base);
int				ft_octal_char(char const *fl, va_list ap, t_print *gl);
int				ft_octal_long(char const *fl, va_list ap, t_print *gl);
int				ft_octal_flag(char const *fl, va_list ap, t_print *gl, char t);
int				ft_nooflag(va_list ap, t_print *gl, char t);
int				ft_unload_oct3(t_print *gl, char *str,
				unsigned long long int o);
int				ft_hexa(char const *fl, va_list ap, t_print *gl);
int				ft_hexa_maj(char const *fl, va_list ap, t_print *gl);
char			*ft_itoa_base_maj(unsigned long long int nbr, int base);
int				ft_isupper(int c);
int				ft_hexa_char(char const *fl, va_list ap, t_print *gl);
int				ft_hexa_flag(char const *fl, va_list ap, t_print *gl, char t);
int				ft_unload_hex3(t_print *gl, char *str, unsigned long long int x,
				char t);
int				ft_nohflag(va_list ap, t_print *gl, char t);
int				unload_hex(t_print *gl, char *str, unsigned long long int x,
				char t);
void			unload_hex2(t_print *gl, unsigned long long int x, char *str);
void			unload_hex3(t_print *gl, char *str, unsigned long long int x,
				char t);
int				ft_percent(char const *fl, va_list ap, t_print *gl);
int				ft_pointeur(char const *fl, va_list ap, t_print *gl);
int				ft_pointeur_maj(char const *fl, va_list ap, t_print *gl);
int				ft_binaire(char const *fl, va_list ap, t_print *gl);
int				ft_binaire_maj(char const *fl, va_list ap, t_print *gl);
int				ft_uns_short(char const *fl, va_list ap, t_print *gl);
int				ft_uns_char(char const *fl, va_list ap, t_print *gl);

#endif
