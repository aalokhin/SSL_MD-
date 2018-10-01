/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:54:39 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:54:41 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H

# define MOD(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z')

# define SPR1(c) (c == 'd' || c == 'D'|| c == 'i' || c == 'c')

# define SPR2(c) (c == 'C' || c == 's' || c == 'S' || c == 'u')

# define SPR3(c) (c == 'U' || c == 'x' || c == 'X')

# define SPR4(c) (c == 'o' || c == 'O' || c == 'p')

# define SPECIFIER(c) (SPR1(c) || SPR2(c) || SPR3(c) || SPR4(c))

# define FLAGS(a) (a == '#' || a == '0' || a == ' ' || a == '-' || a == '+')

# define ELSE(c) (FLAGS(c) || c == '.' || c == '%' || MOD(c) || ft_isdigit(c))

# define SKIP(c) (FLAGS(c) || c == '.' || MOD(c) || ft_isdigit(c))

# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}					t_list;

typedef	struct		s_h
{
	int				s;
	size_t			c;
	char			*si;
	char			*tm;
	t_list			*j;
}					t_h;

typedef	struct		s_j
{
	size_t			l;
	size_t			c1;
	size_t			c2;
	int				i;
	char			*res;
}					t_j;

typedef	struct		s_l
{
	size_t			len;
	char			*pre;
	char			*res;
}					t_l;

typedef struct		s_s
{
	size_t			check;
	size_t			size;
	unsigned int	j;
}					t_s;

typedef	struct		s_find
{
	char			*s;
	size_t			va;
	size_t			count;
}					t_find;

typedef struct		s_flags
{
	int				hash;
	int				zero;
	int				space;
	int				minus;
	int				plus;
	char			mod;
	char			sign;
	size_t			wid;
	size_t			pre;
	int				dot;
	char			specifier;
}					t_flags;

int					get_next_line(int fd, char **line);
void				ft_bubble_sort(int	*tab, unsigned int size);
char				*ft_hex(size_t nbr);
void				ft_lstrev(t_list **alst);
size_t				ft_is_prime(size_t nb);
void				ft_swap(size_t *a, size_t *b);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *str, int c, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *big,
								const char *little, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
char				*ft_itoa_base(uintmax_t value, int base);
intmax_t			ft_atoi_m(char *str);
char				*ft_dec_wp(char *res, t_flags *box);
char				*ft_strjoin_m(char **s1, char **s2, int c);
void				ft_memdel(void **ap);
void				hexs1(char **res, uintmax_t ival, t_flags *box);
char				*dec2(int len, char *res, t_flags *box);
void				dec1(intmax_t *ival, t_flags *box);
void				fill_mods(char *str, size_t i, t_flags *box);
size_t				collect(char *str, size_t i);
void				ft_uns(va_list ap, t_flags *box, size_t *count);
void				ft_invalid(int	ival, t_flags *box, size_t *count);
char				*ft_char_wp(unsigned int	ival, t_flags *box);
void				print_char(unsigned int ival, size_t	*count);
void				ft_mod_u(uintmax_t *n, t_flags *box);
void				ft_uns(va_list ap, t_flags *box, size_t *count);
void				ft_uns_b(va_list ap, t_flags *box, size_t *count);
void				u2(int bytes, unsigned int s, size_t *count);
void				u3(int bytes, unsigned int s, size_t *count);
void				u4(int bytes, unsigned int s, size_t *count);
void				print_us(unsigned int *s, size_t *count);
size_t				ft_w_strlen(unsigned int *str);
char				*ft_ls_wp(unsigned int *ival, t_flags *box);
void				stroka_l(va_list ap, t_flags *box, size_t *count);
size_t				ft_char_len(unsigned int c);
void				char_b(va_list ap, t_flags *box, size_t *count);
void				hex_s(va_list ap, t_flags *box, size_t *count);
void				hex_b(va_list ap, t_flags *box, size_t *count);
char				*ft_itoa_base_small(uintmax_t value, int base);
void				ft_hash_xs(char **str);
void				ft_print_struct(t_flags *box);
char				*ft_str_wp(char	*ival, t_flags *box);
void				stroka(va_list ap, t_flags *box, size_t *count);
void				ft_hash_x(char **str);
void				octal(va_list ap, t_flags *box, size_t *count);
void				ft_hash_o(char **str);
void				fill_struct(t_flags *box);
void				ft_putchar2(char c, size_t *count);
int					ft_m_putchar(t_find	*p);
void				ft_putstr2(char const *s, size_t *count);
char				*ft_strnew(size_t size);
void				charik(va_list ap, t_flags *box, size_t *count);
void				ft_mod(intmax_t *n, t_flags *box);
void				decimal(va_list ap, t_flags *box, size_t *count);
void				ft_percent_sign(t_find	*f, va_list ap, t_flags *box);
void				ft_fill_width(t_find *f, t_flags *box);
void				fill_precision(char *str, t_flags *box, size_t *vasia);
void				ft_find_flags(char *str, t_flags *box, size_t *vasia);
void				ft_find_mods(char *str, t_flags *box, size_t *vasia);
void				ft_found(t_find *f, va_list ap, t_flags *box);
void				fill_flags(char *str, size_t i, t_flags *box);
int					ft_printf(const char *format, ...);
char				*ft_itoa_m(intmax_t value);

#endif
