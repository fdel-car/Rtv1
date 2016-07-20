/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:26:34 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 17:08:09 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "ft_printf.h"
# include "get_next_line.h"

void				ft_strputtab(char **tab);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
int					ft_putchar(unsigned int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(long long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
size_t				ft_strlen(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_atoi(const char *nptr);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t n);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, int n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_isupper(int c);
int					ft_islower(int c);
void				ft_swap(int *a, int *b);
void				ft_swap_string(char **s1_ptr, char **s2_ptr);
char				*ft_itoa_base(unsigned long long int nbr, int base);
char				*ft_itoa_base_maj(unsigned long long int nbr, int base);
int					ft_atoi_base(char *str, int base);
float				ft_atof(const char *str);

#endif
