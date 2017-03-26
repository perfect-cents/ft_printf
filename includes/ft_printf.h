#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <wchar.h>

enum				e_lm
{
	lm_none, lm_hh, lm_h, lm_l, lm_ll, lm_j, lm_et, lm_z
};

struct				s_flags
{
	int				h;
	int				j;
	int				p;
	int				s;
	int				z;
};

typedef struct
{
	struct s_flags	f;
	int				mfw;
	int				prc;
	enum e_lm		lm;
	char			cnv;
}					t_fmt_spec;

int					ft_printf(char const * format, ...);
int					ft_dprintf(int fd, char const * format, ...);
int					ft_vdprintf(int fd, char const * format, va_list ap);


int					parse_flags(char const * format, t_fmt_spec * const fmt);
int					parse_min_field_width(char const * format, va_list ap, \
t_fmt_spec * const fmt);
int					parse_precision(char const * format, va_list ap, \
t_fmt_spec * const fmt);
int					parse_length_modifier(char const * format, \
t_fmt_spec * const fmt);
int					parse_conversion_spec(char const * format, \
t_fmt_spec * const fmt);

int			write_nbr(int fd, uintmax_t nbr, char * /*const*/ pfx, t_fmt_spec *fmt);
int			write_char(int fd, wint_t c, t_fmt_spec *fmt);
int			write_str(int fd, char *s, t_fmt_spec *fmt);
int			write_wstr(int fd, wchar_t *ws, t_fmt_spec *fmt);
int			write_wstr_fake(int fd, wchar_t *ws, t_fmt_spec *fmt);
int			write_wchar_fake(int fd, wint_t c, t_fmt_spec *fmt);

char		*get_signed_prefix(intmax_t nbr, t_fmt_spec *fmt);
char		*get_unsigned_prefix(uintmax_t nbr, t_fmt_spec *fmt);


int					handler(int fd, va_list ap, t_fmt_spec *fmt);
int					parse_fmt_spec(char const * format, va_list ap, \
t_fmt_spec * const fmt);


#endif
